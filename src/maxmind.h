extern "C" {
#include <maxminddb.h>
}
#include <Rcpp.h>
#include <sstream>
using namespace Rcpp;

#ifndef __LIBMAXMIND_BINDINGS__
#define __LIBMAXMIND_BINDINGS__

class maxmind_bindings {
  
private:
  
  std::string mmdb_convert_string(MMDB_entry_data_s entry);
  
  std::string continent_name(MMDB_lookup_result_s& results);
  
  std::string country_name(MMDB_lookup_result_s& results);
  
  std::string country_code(MMDB_lookup_result_s& results);
  
  std::string region_name(MMDB_lookup_result_s& results);
  
  std::string city_name(MMDB_lookup_result_s& results);

  std::string timezone(MMDB_lookup_result_s& results);
  
  std::string connection(MMDB_lookup_result_s& results);
  
  std::vector < std::string > lookup(std::string& ip_address, MMDB_s *mmdb_set);
  
public:
  
  DataFrame call_maxmind(std::vector < std::string > ip_addresses, const char* file);
};

#endif