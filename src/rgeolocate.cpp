#include "maxmind.h"
#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
DataFrame maxmind_(std::vector < std::string > ips, const char* file){
  maxmind_bindings bind_inst;
  return bind_inst.call_maxmind(ips, file);
}
