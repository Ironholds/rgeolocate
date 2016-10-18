#include <Rcpp.h>
#include "IP2location.h"
using namespace Rcpp;

namespace ip2_wrapper {

  CharacterVector country_code(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
    
    CharacterVector output(in_size);
    
    for(unsigned int i = 0; i < in_size; i++){
      if(results[i] == NULL){
        output[i] = NA_STRING;
      } else {
        output[i] = results[i]->country_short;
      }
    }
    
    return output;
  }

  CharacterVector country_name(std::vector <IP2LocationRecord*>& results, int& in_size){
    
    CharacterVector output(in_size);
    
    for(unsigned int i = 0; i < in_size; i++){
      if(results[i] == NULL){
        output[i] = NA_STRING;
      } else {
        output[i] = results[i]->country_long;
      }
    }
    
    return output;
  }

  CharacterVector region(std::vector <IP2LocationRecord*>& results, int& in_size){
    
    CharacterVector output(in_size);
    
    for(unsigned int i = 0; i < in_size; i++){
      if(results[i] == NULL){
        output[i] = NA_STRING;
      } else {
        output[i] = results[i]->region;
      }
    }
    
    return output;
  }

  CharacterVector city(std::vector <IP2LocationRecord*>& results, int& in_size){
    
    CharacterVector output(in_size);
    
    for(unsigned int i = 0; i < in_size; i++){
      if(results[i] == NULL){
        output[i] = NA_STRING;
      } else {
        output[i] = results[i]->city;
      }
    }
    
    return output;
  }

CharacterVector isp(std::vector <IP2LocationRecord*>& results, int& in_size){
  
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->isp;
    }
  }
  
  return output;
}

NumericVector lat(std::vector <IP2LocationRecord*>& results, int& in_size){
  
  NumericVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_REAL;
    } else {
      output[i] = results[i]->latitude;
    }
  }
  
  return output;
}

NumericVector lng(std::vector <IP2LocationRecord*>& results, int& in_size){
  
  NumericVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_REAL;
    } else {
      output[i] = results[i]->longitude;
    }
  }
  
  return output;
}


// char *domain;
// char *zipcode;
// char *timezone;
// char *netspeed;
// char *iddcode;
// char *areacode;
// char *weatherstationcode;
// char *weatherstationname;
// char *mcc;
// char *mnc;
// char *mobilebrand;
// float elevation;
// char *usagetype;

  List process_results(CharacterVector& fields, std::vector <IP2LocationRecord*>& results){
    
    List output;
    unsigned int in_size = results.size();
    for(unsigned int i = 0; i < fields.size(); i++){
      
      if(fields[i] == "country_code"){
        output.push_back(country_code(results, in_size));
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
    
    // Loop to free
    for(unsigned int i = 0; i < input_size; i++){
      IP2Location_free_record(x[i]);
    }
    // Close file
    IP2Location_close(loc_obj);
    
    return DataFrame::create();
  }
}