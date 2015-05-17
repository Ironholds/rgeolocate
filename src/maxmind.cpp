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

std::vector < MMDB_lookup_result_s > maxmind_bindings::lookup(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set){
  
  int input_size = ip_addresses.size();
  std::vector < MMDB_lookup_result_s > output;
  MMDB_lookup_result_s result;
  int lookup_error;
  int gai_error;
  
  for(int i = 0; i < input_size; i++){
    result = MMDB_lookup_string(mmdb_set, ip_addresses[i].c_str(), &lookup_error, &gai_error);
    if((lookup_error == MMDB_SUCCESS) && (gai_error == MMDB_SUCCESS)){
      output.push_back(result);
    }
  }
  
  return output;
}

void maxmind_bindings::call_maxmind(std::vector < std::string > ip_addresses, const char* file, std::vector < std::string > fields){
  
}