#include "maxmind.h"
#include <stdarg.h>

static CharacterVector mmdb_getstring(MMDB_s *data, const CharacterVector ip_addresses, ...){
  int input_size = ip_addresses.size();
  CharacterVector output(input_size);
  
  int run_status;
  int lookup_error;
  int gai_error;
  MMDB_lookup_result_s result;
  MMDB_entry_data_s entry_data;
  va_list path;
  
  
  for(int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(CharacterVector::is_na(ip_addresses[i])){
      output[i] = NA_STRING;
    } else {
      result = MMDB_lookup_string(data, ip_addresses[i].operator char *(), &lookup_error, &gai_error);
      if((lookup_error != MMDB_SUCCESS) | (gai_error != MMDB_SUCCESS)){
        output[i] = NA_STRING;
      } else {
        va_start(path, ip_addresses);
        run_status = MMDB_vget_value(&result.entry, &entry_data, path);
        va_end(path);
        if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
          output[i] = NA_STRING;
        } else {
          std::string out(entry_data.intunion.utf8_string, 0, entry_data.data_size);
          output[i] = out;
        }
      }
    }
  }
  
  return output;
}

static NumericVector mmdb_getdouble(MMDB_s *data, const CharacterVector ip_addresses, ...){
  int input_size = ip_addresses.size();
  NumericVector output(input_size);
  
  int run_status;
  int lookup_error;
  int gai_error;
  MMDB_lookup_result_s result;
  MMDB_entry_data_s entry_data;
  va_list path;
  
  
  for(int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    
    result = MMDB_lookup_string(data, ip_addresses[i].operator char *(), &lookup_error, &gai_error);
    if((lookup_error != MMDB_SUCCESS) | (gai_error != MMDB_SUCCESS)){
      output[i] = NA_REAL;
    } else {
      va_start(path, ip_addresses);
      run_status = MMDB_vget_value(&result.entry, &entry_data, path);
      va_end(path);
      if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
        output[i] = NA_REAL;
      } else {
        output[i] = entry_data.intunion.double_value;
      }
    }
  }
  
  return output;
}

static IntegerVector mmdb_getint32(MMDB_s *data, const CharacterVector ip_addresses, ...){
  int input_size = ip_addresses.size();
  IntegerVector output(input_size);
  
  int run_status;
  int lookup_error;
  int gai_error;
  MMDB_lookup_result_s result;
  MMDB_entry_data_s entry_data;
  va_list path;
  
  
  for(int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    
    result = MMDB_lookup_string(data, ip_addresses[i].operator char *(), &lookup_error, &gai_error);
    if((lookup_error != MMDB_SUCCESS) | (gai_error != MMDB_SUCCESS)){
      output[i] = NA_INTEGER;
    } else {
      va_start(path, ip_addresses);
      run_status = MMDB_vget_value(&result.entry, &entry_data, path);
      va_end(path);
      if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
        output[i] = NA_INTEGER;
      } else {
        output[i] = entry_data.intunion.uint32;
      }
    }
  }
  
  return output;
}


static IntegerVector mmdb_getint16(MMDB_s *data, const CharacterVector ip_addresses, ...){
  int input_size = ip_addresses.size();
  IntegerVector output(input_size);
  
  int run_status;
  int lookup_error;
  int gai_error;
  MMDB_lookup_result_s result;
  MMDB_entry_data_s entry_data;
  va_list path;
  
  
  for(int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    
    result = MMDB_lookup_string(data, ip_addresses[i].operator char *(), &lookup_error, &gai_error);
    if((lookup_error != MMDB_SUCCESS) | (gai_error != MMDB_SUCCESS)){
      output[i] = NA_INTEGER;
    } else {
      va_start(path, ip_addresses);
      run_status = MMDB_vget_value(&result.entry, &entry_data, path);
      va_end(path);
      if((run_status != MMDB_SUCCESS) | (!entry_data.has_data)){
        output[i] = NA_INTEGER;
      } else {
        output[i] = entry_data.intunion.uint16;
      }
    }
  }
  
  return output;
}

CharacterVector maxmind_bindings::continent_name(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "continent", "names", "en", NULL);
}

CharacterVector maxmind_bindings::country_name(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "country", "names", "en", NULL);
}

CharacterVector maxmind_bindings::country_code(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "country", "iso_code", NULL);
}

CharacterVector maxmind_bindings::region_name(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "subdivisions", "0", "names", "en", NULL);
}

CharacterVector maxmind_bindings::city_name(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "city", "names", "en", NULL);
}

CharacterVector maxmind_bindings::timezone(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "location", "time_zone", NULL);
}

CharacterVector maxmind_bindings::postcode(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "postal", "code", NULL);
}

CharacterVector maxmind_bindings::connection(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "connection_type", NULL);
}

CharacterVector maxmind_bindings::isp(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "isp", NULL);
}

CharacterVector maxmind_bindings::organization(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "organization", NULL);
}

IntegerVector maxmind_bindings::asn(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getint32(data, ip_addresses, "autonomous_system_number", NULL);
}

CharacterVector maxmind_bindings::aso(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getstring(data, ip_addresses, "autonomous_system_organization", NULL);
}

IntegerVector maxmind_bindings::city_geoname_id(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getint32(data, ip_addresses, "city", "geoname_id", NULL);
}

IntegerVector maxmind_bindings::city_metro_code(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getint16(data, ip_addresses, "location", "metro_code", NULL);
}

NumericVector maxmind_bindings::latitude(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getdouble(data, ip_addresses, "location", "latitude", NULL);
}

NumericVector maxmind_bindings::longitude(MMDB_s *data, CharacterVector ip_addresses){
  return mmdb_getdouble(data, ip_addresses, "location", "longitude", NULL);
}

List maxmind_bindings::lookup(CharacterVector ip_addresses, MMDB_s *mmdb_set,
                                                     std::vector < std::string > fields){
  
  List output;
  int field_length = fields.size();

  for(int i = 0; i < field_length; i++){
    if(fields[i] == "continent_name"){
      output.push_back(continent_name(mmdb_set, ip_addresses));
    } else if(fields[i] == "country_name"){
      output.push_back(country_name(mmdb_set, ip_addresses));
    } else if(fields[i] == "country_code"){
      output.push_back(country_code(mmdb_set, ip_addresses));
    } else if(fields[i] == "region_name"){
      output.push_back(region_name(mmdb_set, ip_addresses));
    } else if(fields[i] == "city_name"){
      output.push_back(city_name(mmdb_set, ip_addresses));
    } else if(fields[i] == "timezone"){
      output.push_back(timezone(mmdb_set, ip_addresses));
    } else if(fields[i] == "latitude"){
      output.push_back(latitude(mmdb_set, ip_addresses));
    } else if(fields[i] == "longitude"){
      output.push_back(longitude(mmdb_set, ip_addresses));
    } else if(fields[i] == "connection"){
      output.push_back(connection(mmdb_set, ip_addresses));
    } else if(fields[i] == "organization"){
      output.push_back(organization(mmdb_set, ip_addresses));
    } else if(fields[i] == "isp"){
      output.push_back(isp(mmdb_set, ip_addresses));
    } else if(fields[i] == "asn"){
      output.push_back(asn(mmdb_set, ip_addresses));
    } else if(fields[i] == "aso"){
      output.push_back(aso(mmdb_set, ip_addresses));
    } else if(fields[i] == "postcode"){
      output.push_back(postcode(mmdb_set, ip_addresses));
    } else if (fields[i] == "city_geoname_id") {
      output.push_back(city_geoname_id(mmdb_set, ip_addresses));
    } else if (fields[i] == "city_metro_code") {
      output.push_back(city_metro_code(mmdb_set, ip_addresses));
    }
    
  }
  
  return output;
}

List maxmind_bindings::call_maxmind(CharacterVector ip_addresses, const char* file,
                                    std::vector < std::string > fields){
  
  //Open file
  MMDB_s geo_file;
  int result;
  result = MMDB_open(file, 0, &geo_file);
  if(MMDB_SUCCESS != result){
    Rcpp::stop("The geolocation database could not be opened");
  }

  //Create references and holding
  int input_size = ip_addresses.size();
  IntegerVector rownames(input_size);
  rownames = Rcpp::seq(1,input_size);
  
  List output = lookup(ip_addresses, &geo_file, fields);
  output.attr("class") = "data.frame";
  output.attr("names") = fields;
  output.attr("row.names") = rownames;
  
  //Close and return
  MMDB_close(&geo_file);
  return output;
}
