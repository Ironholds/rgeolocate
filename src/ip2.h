#include <Rcpp.h>
#include "IP2Location.h"
using namespace Rcpp;

namespace ip2_wrapper {

  CharacterVector country_code(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  CharacterVector country_name(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  CharacterVector region(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  CharacterVector city(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  CharacterVector isp(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  NumericVector lat(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  NumericVector lng(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  CharacterVector domain(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  CharacterVector zipcode(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  CharacterVector tz(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector netspeed(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector idd(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector area_code(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector ws_code(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector ws_name(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector mcc(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector mnc(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector mobile_brand(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  NumericVector elevation(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  CharacterVector usage_type(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);
  
  List process_results(CharacterVector fields, std::vector <IP2LocationRecord*>& results);
  
  List ip_location(CharacterVector ip_addresses, CharacterVector fields,
                   std::string file);
}