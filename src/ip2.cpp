#include "ip2.h"


CharacterVector ip2_wrapper::country_code(std::vector <IP2LocationRecord*>& results,
                                          unsigned int& in_size){
  
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

CharacterVector ip2_wrapper::country_name(std::vector <IP2LocationRecord*>& results,
                                          int& in_size){
  
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

CharacterVector ip2_wrapper::region(std::vector <IP2LocationRecord*>& results, int& in_size){
  
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

CharacterVector ip2_wrapper::city(std::vector <IP2LocationRecord*>& results, int& in_size){
  
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

CharacterVector ip2_wrapper::isp(std::vector <IP2LocationRecord*>& results, int& in_size){
  
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

NumericVector ip2_wrapper::lat(std::vector <IP2LocationRecord*>& results, int& in_size){
  
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

NumericVector ip2_wrapper::lng(std::vector <IP2LocationRecord*>& results, int& in_size){
  
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

CharacterVector ip2_wrapper::domain(std::vector <IP2LocationRecord*>& results, int& in_size){
  
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->domain;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::zipcode(std::vector <IP2LocationRecord*>& results, int& in_size){
  
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->zipcode;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::tz(std::vector <IP2LocationRecord*>& results, int& in_size){
  
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->timezone;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::netspeed(std::vector <IP2LocationRecord*>& results, int& in_size){
  
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->netspeed;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::idd(std::vector <IP2LocationRecord*>& results, int& in_size){
  
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->iddcode;
    }
  }
  
  return output;
}
// char *areacode;
// char *weatherstationcode;
// char *weatherstationname;
// char *mcc;
// char *mnc;
// char *mobilebrand;
// float elevation;
// char *usagetype;

List ip2_wrapper::process_results(CharacterVector& fields, std::vector <IP2LocationRecord*>& results){
  
  List output;
  unsigned int in_size = results.size();
  for(unsigned int i = 0; i < fields.size(); i++){
    
    if(fields[i] == "country_code"){
      output.push_back(country_code(results, in_size));
    }
  }
  
  return output;
  
}

DataFrame ip2_wrapper::ip_location(CharacterVector ip_addresses, CharacterVector fields,
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