#include "maxmind.h"

std::string maxmind_bindings::mmdb_convert_string(MMDB_entry_data_s entry){
  std::string output(entry.utf8_string, 0, entry.data_size);
  return output;
}

std::string maxmind_bindings::continent_name(MMDB_lookup_result_s& results){
  
  int run_status;
  MMDB_entry_data_s entry_data;
  run_status = MMDB_get_value(&results.entry, &entry_data, "continent","names","en", NULL);
  
  if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
    return "Unknown";
  } else {
    return mmdb_convert_string(entry_data);
  }
    
}

std::string maxmind_bindings::country_name(MMDB_lookup_result_s& results){
  
  int run_status;
  MMDB_entry_data_s entry_data;
  run_status = MMDB_get_value(&results.entry, &entry_data, "country","names","en", NULL);
  
  if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
    return "Unknown";
  }
  
  return mmdb_convert_string(entry_data);
  
}

std::string maxmind_bindings::country_code(MMDB_lookup_result_s& results){
  
  int run_status;
  MMDB_entry_data_s entry_data;
  run_status = MMDB_get_value(&results.entry, &entry_data, "country","iso_code", NULL);
  
  if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
    return "Unknown";
  }
  
  return mmdb_convert_string(entry_data);
  
}

std::string maxmind_bindings::region_name(MMDB_lookup_result_s& results){
  
  int run_status;
  MMDB_entry_data_s entry_data;
  run_status = MMDB_get_value(&results.entry, &entry_data, "subdivisions","0","names","en", NULL);
  
  if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
    return "Unknown";
  }
  
  return mmdb_convert_string(entry_data);
  
}

std::string maxmind_bindings::city_name(MMDB_lookup_result_s& results){
  
  int run_status;
  MMDB_entry_data_s entry_data;
  run_status = MMDB_get_value(&results.entry, &entry_data, "city","names","en", NULL);
  
  if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
    return "Unknown";
  }
  
  return mmdb_convert_string(entry_data);
  
}

std::string maxmind_bindings::timezone(MMDB_lookup_result_s& results){
  
  int run_status;
  MMDB_entry_data_s entry_data;
  run_status = MMDB_get_value(&results.entry, &entry_data, "location","time_zone", NULL);
  
  if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
    return "Unknown";
  }
  
  return mmdb_convert_string(entry_data);
  
}

std::string maxmind_bindings::connection(MMDB_lookup_result_s& results){
  int run_status;
  MMDB_entry_data_s entry_data;
  run_status = MMDB_get_value(&results.entry, &entry_data, "connection_type", NULL);
  
  if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
    return "Unknown";
  }
  
  return mmdb_convert_string(entry_data);
}

std::vector < std::string > maxmind_bindings::lookup(std::string& ip_address, MMDB_s *mmdb_set){
  
  std::vector < std::string > output(7);
  MMDB_lookup_result_s result;
  int lookup_error;
  int gai_error;
  
  result = MMDB_lookup_string(mmdb_set, ip_address.c_str(), &lookup_error, &gai_error);
  
  if((lookup_error != MMDB_SUCCESS) | (gai_error != MMDB_SUCCESS)){
    for(int i = 0; i < output.size(); i++){
      output[i] = "Unknown";
    }
  } else {
    
    output[0] = continent_name(result);
    output[1] = country_name(result);
    output[2] = country_code(result);
    output[3] = region_name(result);
    output[4] = city_name(result);
    output[5] = timezone(result);
    output[6] = connection(result);
  }
  return output;
}

DataFrame maxmind_bindings::call_maxmind(std::vector < std::string > ip_addresses, const char* file){
  
  //Open file
  MMDB_s geo_file;
  int result;
  result = MMDB_open(file, 0, &geo_file);
  if(result != MMDB_SUCCESS){
    throw std::range_error("The geolocation database could not be opened");
  }
  
  //Create references
  std::vector < std::string >& ip_ref = ip_addresses;
  int input_size = ip_addresses.size();
  
  //Create holding vectors
  std::vector < std::string > holding(7);
  std::vector < std::string > continents(input_size);
  std::vector < std::string > country_names(input_size);
  std::vector < std::string > country_codes(input_size);
  std::vector < std::string > regions(input_size);
  std::vector < std::string > city_names(input_size);
  std::vector < std::string > timezones(input_size);
  std::vector < std::string > connection_types(input_size);
  
  for(int i = 0; i < input_size; i++){
    
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    holding = lookup(ip_ref[i], &geo_file);
    continents[i] = holding[0];
    country_names[i] = holding[1];
    country_codes[i] = holding[2];
    regions[i] = holding[3];
    city_names[i] = holding[4];
    timezones[i] = holding[5];
    connection_types[i] = holding[6];
  }
  
  //Close and return
  MMDB_close(&geo_file);
  
  return DataFrame::create(_["continent_name"] = continents,
                           _["country_name"] = country_names,
                           _["country_code"] = country_codes,
                           _["region_name"] = regions,
                           _["city_name"] = city_names,
                           _["timezone"] = timezones,
                           _["connection_type"] = connection_types,
                           _["stringsAsFactors"] = false);
}