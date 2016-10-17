#include <Rcpp.h>
#include "IP2location.h"
using namespace Rcpp;

namespace ip2_wrapper {


  List process_results(CharacterVector& fields, std::vector <IP2LocationRecord*>& results){
    
    List output;
    
    for(unsigned int i = 0; i < fields.size(); i++){
      
      if(fields[i] == "foo"){
        
      }
    }
    
    return output;
    
  }
  
  DataFrame ip_location(CharacterVector ip_addresses, CharacterVector fields,
                        std::string file){
    
    // Open file
    IP2Location* loc_obj = IP2Location_open((char*)file.c_str());
    if (loc_obj == NULL){
      Rcpp::stop("Database could not be opened");
    }
    
    // Get the results
    unsigned int input_size = ip_addresses.size();
    std::vector <IP2LocationRecord*> x(input_size);
    for(unsigned int i = 0; i < input_size; i++){
      
      if(ip_addresses[i] != NA_STRING){
        x[i] = IP2Location_get_all(loc_obj, ip_addresses[i].operator char *());
      } else {
        x[i] = NULL;
      }
      
    }
    
    List output
    // Close file
    IP2Location_close(loc_obj);
    
    return DataFrame::create();
  }
}