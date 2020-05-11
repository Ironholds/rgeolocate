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
  
  CharacterVector continent_name(MMDB_s *data, CharacterVector ip_addresses);
  
  CharacterVector country_name(MMDB_s *data, CharacterVector ip_addresses);
  
  CharacterVector country_code(MMDB_s *data, CharacterVector ip_addresses);
  
  CharacterVector region_name(MMDB_s *data, CharacterVector ip_addresses);
  
  CharacterVector city_name(MMDB_s *data, CharacterVector ip_addresses);

  IntegerVector city_geoname_id(MMDB_s *data, CharacterVector ip_addresses);

  IntegerVector city_metro_code(MMDB_s *data, CharacterVector ip_addresses);
  
  CharacterVector postcode(MMDB_s *data, CharacterVector ip_addresses);
  
  CharacterVector timezone(MMDB_s *data, CharacterVector ip_addresses);
  
  CharacterVector connection(MMDB_s *data, CharacterVector ip_addresses);

  CharacterVector isp(MMDB_s *data, CharacterVector ip_addresses);
  
  CharacterVector organization(MMDB_s *data, CharacterVector ip_addresses);

  IntegerVector asn(MMDB_s *data, CharacterVector ip_addresses);

  CharacterVector aso(MMDB_s *data, CharacterVector ip_addresses);
  
  NumericVector latitude(MMDB_s *data, CharacterVector ip_addresses);

  NumericVector longitude(MMDB_s *data, CharacterVector ip_addresses);
  
  List lookup(CharacterVector ip_addresses, MMDB_s *mmdb_set, std::vector < std::string > fields);
  
public:
  
  List call_maxmind(CharacterVector ip_addresses, const char* file, std::vector < std::string > fields);
};

#endif
