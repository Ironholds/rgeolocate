#include "ip2.h"

CharacterVector ip2_wrapper::country_code(std::vector <IP2LocationRecord*>& results,
                                          unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      holding = results[i]->country_short;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::country_name(std::vector <IP2LocationRecord*>& results,
                                          unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      holding = results[i]->country_long;
      if(holding == "-" || holding == "INVALID IPV4 ADDRESS"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::region(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
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

CharacterVector ip2_wrapper::city(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
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

CharacterVector ip2_wrapper::isp(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
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

NumericVector ip2_wrapper::lat(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
  NumericVector output(in_size);
  double holding;
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_REAL;
    } else {
      holding = results[i]->latitude;
      if(holding == 0.0){
        output[i] = NA_REAL;
      } else {
        output[i] = holding;
      }
    }
  }
  
  return output;
}

NumericVector ip2_wrapper::lng(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
  NumericVector output(in_size);
  double holding;
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_REAL;
    } else {
      holding = results[i]->longitude;
      if(holding == 0.0){
        output[i] = NA_REAL;
      } else {
        output[i] = holding;
      }
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::domain(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
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

CharacterVector ip2_wrapper::zipcode(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
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

CharacterVector ip2_wrapper::tz(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
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

CharacterVector ip2_wrapper::netspeed(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
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

CharacterVector ip2_wrapper::idd(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
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

CharacterVector ip2_wrapper::area_code(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->areacode;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::ws_code(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->weatherstationcode;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::ws_name(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->weatherstationname;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::mcc(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->mcc;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::mnc(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->mnc;
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::mobile_brand(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->mobilebrand;
    }
  }
  
  return output;
}

NumericVector ip2_wrapper::elevation(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  NumericVector output(in_size);
  double holding;
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_REAL;
    } else {
      holding = results[i]->elevation;
      if(holding == 0.0){
        output[i] = NA_REAL;
      } else {
        output[i] = holding;
      }
    }
  }
  
  return output;
}

CharacterVector ip2_wrapper::usage_type(std::vector <IP2LocationRecord*>& results, unsigned int& in_size){
  CharacterVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    if(results[i] == NULL){
      output[i] = NA_STRING;
    } else {
      output[i] = results[i]->usagetype;
    }
  }
  
  return output;
}

List ip2_wrapper::process_results(CharacterVector fields,
                                  std::vector <IP2LocationRecord*>& results){
  
  List output;
  unsigned int in_size = results.size();

  for(unsigned int i = 0; i < fields.size(); i++){
    if(fields[i] == "country_code"){
      output.push_back(country_code(results, in_size));
    } else if(fields[i] == "country_name"){
      output.push_back(country_name(results, in_size));
    } else if(fields[i] == "region"){
      output.push_back(region(results, in_size));
    } else if(fields[i] == "city"){
      output.push_back(city(results, in_size));
    } else if(fields[i] == "isp"){
      output.push_back(isp(results, in_size));
    } else if(fields[i] == "lat"){
      output.push_back(lat(results, in_size));
    } else if(fields[i] == "long"){
      output.push_back(lng(results, in_size));
    } else if(fields[i] == "domain"){
      output.push_back(domain(results, in_size));
    } else if(fields[i] == "area_code"){
      output.push_back(zipcode(results, in_size));
    } else if(fields[i] == "timezone"){
      output.push_back(tz(results, in_size));
    } else if(fields[i] == "netspeed"){
      output.push_back(netspeed(results, in_size));
    } else if(fields[i] == "international_code"){
      output.push_back(idd(results, in_size));
    } else if(fields[i] == "area_code"){
      output.push_back(area_code(results, in_size));
    } else if(fields[i] == "station_code"){
      output.push_back(ws_code(results, in_size));
    } else if(fields[i] == "station_name"){
      output.push_back(ws_name(results, in_size));
    } else if(fields[i] == "mcc"){
      output.push_back(mcc(results, in_size));
    } else if(fields[i] == "mnc"){
      output.push_back(mnc(results, in_size));
    } else if(fields[i] == "mobile_brand"){
      output.push_back(mobile_brand(results, in_size));
    } else if(fields[i] == "elevation"){
      output.push_back(elevation(results, in_size));
    } else if(fields[i] == "usage_type"){
      output.push_back(usage_type(results, in_size));
    }
  }
  
  return output;
  
}

List ip2_wrapper::ip_location(CharacterVector ip_addresses, CharacterVector fields,
                              std::string file, bool use_memory){
  
  // Open file
  IP2Location* loc_obj = IP2Location_open((char*)file.c_str());
  if (loc_obj == NULL){
    Rcpp::stop("Database could not be opened");
  }
  
  if(use_memory){
    if(IP2Location_open_mem(loc_obj, IP2LOCATION_CACHE_MEMORY) < 0){
      IP2Location_close(loc_obj);
      Rcpp::stop("Database could not be stored in memory");
    }
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
  
  // Generate results
  IntegerVector rownames(input_size);
  rownames = Rcpp::seq(1,input_size);
  
  // Format as df
  List output = process_results(fields, x);
  output.attr("class") = "data.frame";
  output.attr("names") = fields;
  output.attr("row.names") = rownames;
  
  // Free db values
  for(unsigned int i = 0; i < x.size(); i++){
    IP2Location_free_record(x[i]);
  }
  
  // Close file
  IP2Location_close(loc_obj);
  
  return output;
}