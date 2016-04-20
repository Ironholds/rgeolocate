#include "maxmind.h"
using namespace Rcpp;

//[[Rcpp::export]]
List maxmind_(CharacterVector ips, const char* file, std::vector < std::string > fields){
  maxmind_bindings bind_inst;
  return bind_inst.call_maxmind(ips, file, fields);
}
