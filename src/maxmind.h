extern "C" {
#include "maxminddb.h"
}
#include <Rcpp.h>
#include <sstream>
using namespace Rcpp;

#ifndef __LIBMAXMIND_BINDINGS__
#define __LIBMAXMIND_BINDINGS__

class maxmind_bindings {
  
private:
  
  std::vector < std::string > continent_name(MMDB_s *data, std::vector < std::string >& ip_addresses);
  
  std::vector < std::string > country_name(MMDB_s *data, std::vector < std::string >& ip_addresses);
  
  std::vector < std::string > country_code(MMDB_s *data, std::vector < std::string >& ip_addresses);
  
  std::vector < std::string > region_name(MMDB_s *data, std::vector < std::string >& ip_addresses);
  
  std::vector < std::string > city_name(MMDB_s *data, std::vector < std::string >& ip_addresses);
  
  std::vector < std::string > timezone(MMDB_s *data, std::vector < std::string >& ip_addresses);
  
  std::vector < std::string > connection(MMDB_s *data, std::vector < std::string >& ip_addresses);

  std::vector < double > latitude(MMDB_s *data, std::vector < std::string >& ip_addresses);

  std::vector < double > longitude(MMDB_s *data, std::vector < std::string >& ip_addresses);
  
  List lookup(std::vector < std::string >& ip_addresses, MMDB_s *mmdb_set, std::vector < std::string > fields);
  
public:
  
  List call_maxmind(std::vector < std::string > ip_addresses, const char* file, std::vector < std::string > fields);
};

#endif
