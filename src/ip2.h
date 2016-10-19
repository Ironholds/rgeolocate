#include <Rcpp.h>
#include "IP2Location.h"
using namespace Rcpp;

namespace ip2_wrapper {

  CharacterVector country_code(IP2Location*& db_ptr, CharacterVector& entries,
                               unsigned int& in_size);

  CharacterVector country_name(IP2Location*& db_ptr, CharacterVector& entries,
                               unsigned int& in_size);

  CharacterVector region(IP2Location*& db_ptr, CharacterVector& entries,
                         unsigned int& in_size);

  CharacterVector city(IP2Location*& db_ptr, CharacterVector& entries,
                       unsigned int& in_size);

  CharacterVector isp(IP2Location*& db_ptr, CharacterVector& entries,
                      unsigned int& in_size);

  NumericVector lat(IP2Location*& db_ptr, CharacterVector& entries,
                    unsigned int& in_size);

  NumericVector lng(IP2Location*& db_ptr, CharacterVector& entries,
                    unsigned int& in_size);

  CharacterVector domain(IP2Location*& db_ptr, CharacterVector& entries,
                         unsigned int& in_size);

  CharacterVector zipcode(IP2Location*& db_ptr, CharacterVector& entries,
                          unsigned int& in_size);

  CharacterVector tz(IP2Location*& db_ptr, CharacterVector& entries,
                     unsigned int& in_size);
  
  CharacterVector netspeed(IP2Location*& db_ptr, CharacterVector& entries,
                           unsigned int& in_size);
  
  CharacterVector idd(IP2Location*& db_ptr, CharacterVector& entries,
                      unsigned int& in_size);
  
  CharacterVector area_code(IP2Location*& db_ptr, CharacterVector& entries,
                            unsigned int& in_size);
  
  CharacterVector ws_code(IP2Location*& db_ptr, CharacterVector& entries,
                          unsigned int& in_size);
  
  CharacterVector ws_name(IP2Location*& db_ptr, CharacterVector& entries,
                          unsigned int& in_size);
  
  CharacterVector mcc(IP2Location*& db_ptr, CharacterVector& entries,
                      unsigned int& in_size);
  
  CharacterVector mnc(IP2Location*& db_ptr, CharacterVector& entries,
                      unsigned int& in_size);
  
  CharacterVector mobile_brand(IP2Location*& db_ptr, CharacterVector& entries,
                               unsigned int& in_size);
  
  NumericVector elevation(IP2Location*& db_ptr, CharacterVector& entries,
                          unsigned int& in_size);
  
  CharacterVector usage_type(IP2Location*& db_ptr, CharacterVector& entries,
                             unsigned int& in_size);
  
  List ip_location(CharacterVector ip_addresses, CharacterVector fields,
                   std::string file);
}