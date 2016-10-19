#include "ip2.h"

CharacterVector ip2_wrapper::country_code(IP2Location*& db_ptr,
                                          CharacterVector& entries,
                                          unsigned int& in_size){
  
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_country_short(db_ptr, entries[i].operator char *());

    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->country_short;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::country_name(IP2Location*& db_ptr, CharacterVector& entries, unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_country_long(db_ptr, entries[i].operator char *());

    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->country_long;
      if(holding == "-" || holding == "INVALID IPV4 ADDRESS"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::region(IP2Location*& db_ptr, CharacterVector& entries,
                                    unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_region(db_ptr, entries[i].operator char *());

    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->region;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::city(IP2Location*& db_ptr, CharacterVector& entries,
                                  unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_city(db_ptr, entries[i].operator char *());

    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->city;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::isp(IP2Location*& db_ptr, CharacterVector& entries,
                                 unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_isp(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->isp;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

NumericVector ip2_wrapper::lat(IP2Location*& db_ptr, CharacterVector& entries,
                               unsigned int& in_size){
  
  NumericVector output(in_size);

  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_latitude(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_REAL;
    } else {
      output[i] = record->latitude;
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

NumericVector ip2_wrapper::lng(IP2Location*& db_ptr, CharacterVector& entries,
                               unsigned int& in_size){
  
  NumericVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_longitude(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_REAL;
    } else {
      output[i] = record->longitude;
    }
    IP2Location_free_record(record);
  }
  
  
  return output;
}

CharacterVector ip2_wrapper::domain(IP2Location*& db_ptr, CharacterVector& entries,
                                    unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_domain(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->domain;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

                                    
CharacterVector ip2_wrapper::zipcode(IP2Location*& db_ptr, CharacterVector& entries,
                                     unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_zipcode(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->zipcode;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::tz(IP2Location*& db_ptr, CharacterVector& entries,
                                unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_timezone(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->timezone;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::netspeed(IP2Location*& db_ptr, CharacterVector& entries,
                                      unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_netspeed(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->netspeed;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::idd(IP2Location*& db_ptr, CharacterVector& entries,
                                 unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_iddcode(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->iddcode;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::area_code(IP2Location*& db_ptr, CharacterVector& entries,
                                       unsigned int& in_size){
  
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_areacode(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->areacode;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::ws_code(IP2Location*& db_ptr, CharacterVector& entries,
                                     unsigned int& in_size){
  CharacterVector output(in_size);
  
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_weatherstationcode(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->weatherstationcode;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::ws_name(IP2Location*& db_ptr, CharacterVector& entries,
                                     unsigned int& in_size){
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_weatherstationname(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->weatherstationname;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::mcc(IP2Location*& db_ptr, CharacterVector& entries,
                                 unsigned int& in_size){
  CharacterVector output(in_size);
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_mcc(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->mcc;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::mnc(IP2Location*& db_ptr, CharacterVector& entries,
                                 unsigned int& in_size){
  CharacterVector output(in_size);
  
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_mnc(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->mnc;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::mobile_brand(IP2Location*& db_ptr, CharacterVector& entries,
                                          unsigned int& in_size){
  CharacterVector output(in_size);
  
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_mobilebrand(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->mobilebrand;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

NumericVector ip2_wrapper::elevation(IP2Location*& db_ptr, CharacterVector& entries,
                                     unsigned int& in_size){
  NumericVector output(in_size);
  
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_elevation(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_REAL;
    } else {
      output[i] = record->elevation;
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

CharacterVector ip2_wrapper::usage_type(IP2Location*& db_ptr, CharacterVector& entries,
                                        unsigned int& in_size){
  CharacterVector output(in_size);
  
  std::string holding;
  for(unsigned int i = 0; i < in_size; i++){
    IP2LocationRecord* record = IP2Location_get_usagetype(db_ptr, entries[i].operator char *());
    
    if(record == NULL){
      output[i] = NA_STRING;
    } else {
      holding = record->usagetype;
      if(holding == "-"){
        output[i] = NA_STRING;
      } else {
        output[i] = holding;
      }
    }
    IP2Location_free_record(record);
  }
  
  return output;
}

List ip2_wrapper::ip_location(CharacterVector ip_addresses, CharacterVector fields,
                              std::string file){
  
  // Open file
  IP2Location* loc_obj = IP2Location_open((char*)file.c_str());
  if (loc_obj == NULL){
    Rcpp::stop("Database could not be opened");
  }
  
  // Get the results
  List output;
  unsigned int in_size = ip_addresses.size();
  
  for(unsigned int i = 0; i < fields.size(); i++){
    if(fields[i] == "country_code"){
      output.push_back(country_code(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "country_name"){
      output.push_back(country_name(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "region"){
      output.push_back(region(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "city"){
      output.push_back(city(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "isp"){
      output.push_back(isp(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "lat"){
      output.push_back(lat(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "long"){
      output.push_back(lng(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "domain"){
      output.push_back(domain(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "area_code"){
      output.push_back(zipcode(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "timezone"){
      output.push_back(tz(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "netspeed"){
      output.push_back(netspeed(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "international_code"){
      output.push_back(idd(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "area_code"){
      output.push_back(area_code(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "station_code"){
      output.push_back(ws_code(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "station_name"){
      output.push_back(ws_name(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "mcc"){
      output.push_back(mcc(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "mnc"){
      output.push_back(mnc(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "mobile_brand"){
      output.push_back(mobile_brand(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "elevation"){
      output.push_back(elevation(loc_obj, ip_addresses, in_size));
    } else if(fields[i] == "usage_type"){
      output.push_back(usage_type(loc_obj, ip_addresses, in_size));
    }
  }
  
  // Format as df
  IntegerVector rownames(in_size);
  rownames = Rcpp::seq(1, in_size);
  output.attr("class") = "data.frame";
  output.attr("names") = fields;
  output.attr("row.names") = rownames;
  
  // Close file
  IP2Location_close(loc_obj);
  
  return output;
}