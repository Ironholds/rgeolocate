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