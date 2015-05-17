#include <maxminddb.h>
#include <Rcpp.h>
#include <sstream>
using namespace Rcpp;

#ifndef __LIBMAXMIND_BINDINGS__
#define __LIBMAXMIND_BINDINGS__

class maxmind_bindings {
  
private:
  
  std::string mmdb_convert_string(MMDB_entry_data_s entry);
  
  std::string mmdb_convert_int(MMDB_entry_data_s entry);
  
  std::vector < std::string > continent(std::vector < MMDB_lookup_result_s >& results);
  
  std::vector < std::string > country(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set);
  
  std::vector < std::string > country_iso(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set);
  
  std::vector < std::string > region(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set); 
  
  std::vector < std::string > city(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set);
  
  std::vector < std::string > timezone(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set);

  std::vector < std::string > connection(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set);
  
  std::vector < MMDB_lookup_result_s > lookup(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set);
  
public:
  
  DataFrame call_maxmind(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set);
};

#endif