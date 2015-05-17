#include "maxmind.h"

std::string maxmind_bindings::mmdb_convert_string(MMDB_entry_data_s entry){
  std::string output(entry.utf8_string, 0, entry.data_size);
  return output;
}

std::string maxmind_bindings::mmdb_convert_int(MMDB_entry_data_s entry){
  std::stringstream convert;
  std::string output;
  convert << entry.uint32;
  output = convert.str();
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
  }
  return output;
}

List maxmind_bindings::call_maxmind(std::vector < std::string > ip_addresses, const char* file, std::vector < std::string > fields){
  
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
  std::vector < std::string > holding(fields.size());
  std::vector < std::string > continents(input_size);
  std::vector < std::string > country_names(input_size);
  std::vector < std::string > country_codes(input_size);
  std::vector < std::string > regions(input_size);
  List output;
  
  for(int i = 0; i < input_size; i++){
    holding = lookup(ip_ref[i], &geo_file);
    continents[i] = holding[0];
    country_names[i] = holding[1];
    country_codes[i] = holding[2];
    regions[i] = holding[3];
  }
  
  output.push_back(continents);
  output.push_back(country_names);
  output.push_back(country_codes);
  output.push_back(regions);
  
  //Close and return
  MMDB_close(&geo_file);
  return output;
}