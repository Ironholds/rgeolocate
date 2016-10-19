#include "maxmind.h"
#include "ip2.h"
using namespace Rcpp;

//[[Rcpp::export]]
List maxmind_(CharacterVector ips, const char* file, std::vector < std::string > fields){
  maxmind_bindings bind_inst;
  return bind_inst.call_maxmind(ips, file, fields);
}

//[[Rcpp::export]]
List ip2location_(CharacterVector ips, CharacterVector fields, std::string file, bool use_memory){
  return ip2_wrapper::ip_location(ips, fields, file, use_memory);
}