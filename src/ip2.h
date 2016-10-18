#include <Rcpp.h>
#include "IP2Location.h"
using namespace Rcpp;

namespace ip2_wrapper {

  CharacterVector country_code(std::vector <IP2LocationRecord*>& results, unsigned int& in_size);

  CharacterVector country_name(std::vector <IP2LocationRecord*>& results, int& in_size);

  CharacterVector region(std::vector <IP2LocationRecord*>& results, int& in_size);

  CharacterVector city(std::vector <IP2LocationRecord*>& results, int& in_size);

  CharacterVector isp(std::vector <IP2LocationRecord*>& results, int& in_size);

  NumericVector lat(std::vector <IP2LocationRecord*>& results, int& in_size);

  NumericVector lng(std::vector <IP2LocationRecord*>& results, int& in_size);

  CharacterVector domain(std::vector <IP2LocationRecord*>& results, int& in_size);

  CharacterVector zipcode(std::vector <IP2LocationRecord*>& results, int& in_size);

  CharacterVector tz(std::vector <IP2LocationRecord*>& results, int& in_size);
  
  CharacterVector netspeed(std::vector <IP2LocationRecord*>& results, int& in_size);
  
  CharacterVector idd(std::vector <IP2LocationRecord*>& results, int& in_size);
// char *areacode;
// char *weatherstationcode;
// char *weatherstationname;
// char *mcc;
// char *mnc;
// char *mobilebrand;
// float elevation;
// char *usagetype;

  List process_results(CharacterVector& fields, std::vector <IP2LocationRecord*>& results);
  
  DataFrame ip_location(CharacterVector ip_addresses, CharacterVector fields,
                        std::string file);
}