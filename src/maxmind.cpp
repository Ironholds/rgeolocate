#include "maxmind.h"
#include <stdarg.h>

static inline std::string mmdb_convert_string(const MMDB_entry_data_s &entry){
  std::string output(entry.utf8_string, 0, entry.data_size);
  return output;
}

static std::vector < std::string > mmdb_getval(MMDB_s *data, const std::vector< std::string > &ip_addresses, ...){
  int input_size = ip_addresses.size();
  std::vector < std::string > output(input_size);
  
  int run_status;
  int lookup_error;
  int gai_error;
  MMDB_lookup_result_s result;
  MMDB_entry_data_s entry_data;
  va_list path;
  
  
  for(int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    
    result = MMDB_lookup_string(data, ip_addresses[i].c_str(), &lookup_error, &gai_error);
    if((lookup_error != MMDB_SUCCESS) | (gai_error != MMDB_SUCCESS)){
      output[i] = "Unknown";
    } else {
      va_start(path, ip_addresses);
      run_status = MMDB_vget_value(&result.entry, &entry_data, path);
      va_end(path);
      if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
        output[i] ="Unknown";
      } else {
        output[i] = mmdb_convert_string(entry_data);
      }
    }
  }
  
  return output;
}


std::vector < std::string > maxmind_bindings::continent_name(MMDB_s *data, std::vector < std::string >& ip_addresses){
  return mmdb_getval(data, ip_addresses, "continent", "names", "en", NULL);
}

std::vector < std::string > maxmind_bindings::country_name(MMDB_s *data, std::vector < std::string >& ip_addresses){
  return mmdb_getval(data, ip_addresses, "country", "names", "en", NULL);
}

std::vector < std::string > maxmind_bindings::country_code(MMDB_s *data, std::vector < std::string >& ip_addresses){
  return mmdb_getval(data, ip_addresses, "country", "iso_code", NULL);
}

std::vector < std::string > maxmind_bindings::region_name(MMDB_s *data, std::vector < std::string >& ip_addresses){
  return mmdb_getval(data, ip_addresses, "subdivisions", "0", "names", "en", NULL);
}

std::vector < std::string > maxmind_bindings::city_name(MMDB_s *data, std::vector < std::string >& ip_addresses){
  return mmdb_getval(data, ip_addresses,"city", "names", "en", NULL);
}

std::vector < std::string > maxmind_bindings::timezone(MMDB_s *data, std::vector < std::string >& ip_addresses){
  return mmdb_getval(data, ip_addresses, "location", "time_zone", NULL);
}

std::vector < std::string > maxmind_bindings::connection(MMDB_s *data, std::vector < std::string >& ip_addresses){
  return mmdb_getval(data, ip_addresses, "connection_type", NULL);
}

List maxmind_bindings::lookup(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set,
                                                     std::vector < std::string > fields){
  
  List output;
  int field_length = fields.size();

  for(int i = 0; i < field_length; i++){
    if(fields[i] == "continent_name"){
      output.push_back(continent_name(mmdb_set, ip_addresses));
    } else if(fields[i] == "country_name"){
      output.push_back(country_name(mmdb_set, ip_addresses));
    } else if(fields[i] == "country_code"){
      output.push_back(country_code(mmdb_set, ip_addresses));
    } else if(fields[i] == "region_name"){
      output.push_back(region_name(mmdb_set, ip_addresses));
    } else if(fields[i] == "city_name"){
      output.push_back(city_name(mmdb_set, ip_addresses));
    } else if(fields[i] == "timezone"){
      output.push_back(timezone(mmdb_set, ip_addresses));
    } else if(fields[i] == "connection"){
      output.push_back(connection(mmdb_set, ip_addresses));
    }
  }
  
  return output;
}

List maxmind_bindings::call_maxmind(std::vector < std::string > ip_addresses, const char* file,
                                    std::vector < std::string > fields){
  
  //Open file
  MMDB_s geo_file;
  int result;
  result = MMDB_open(file, 0, &geo_file);
  if(result != MMDB_SUCCESS){
    throw std::range_error("The geolocation database could not be opened");
  }
  
  //Create references and holding
  std::vector < std::string >& ip_ref = ip_addresses;
  int input_size = ip_addresses.size();
  IntegerVector rownames(input_size);
  rownames = Rcpp::seq(1,input_size);
  
  List output = lookup(ip_ref, &geo_file, fields);
  output.attr("class") = "data.frame";
  output.attr("names") = fields;
  output.attr("row.names") = rownames;
  
  //Close and return
  MMDB_close(&geo_file);
  return output;
}
