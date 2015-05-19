#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame ip_to_df(std::list < std::vector < std::string > > x){
  
  //Iterators and holding entries
  int input_size = x.size();
  int i = 0;
  std::vector < std::string > holding;
  std::list<std::vector < std::string > >::iterator it;
  
  std::vector < std::string > as_code(input_size);
  std::vector < std::string > city_name(input_size);
  std::vector < std::string > country_name(input_size);
  std::vector < std::string > country_code(input_size);
  std::vector < std::string > isp(input_size);
  std::vector < std::string > latitude(input_size);
  std::vector < std::string > longitude(input_size);
  std::vector < std::string > organisation(input_size);
  std::vector < std::string > region_code(input_size);
  std::vector < std::string > region_name(input_size);
  std::vector < std::string > timezone(input_size);
  std::vector < std::string > zip_code(input_size);
  std::vector < std::string > status(input_size);
  
  for(it = x.begin(); it != x.end(); it++){
    holding = *it;
    if(holding.size() == 14){
      as_code[i] = holding[0];
      city_name[i] = holding[1];
      country_name[i] = holding[2];
      country_code[i] = holding[3];
      isp[i] = holding[4];
      latitude[i] = holding[5];
      longitude[i] = holding[6];
      organisation[i] = holding[7];
      region_code[i] = holding[9];
      region_name[i] = holding[10];
      status[i] = holding[11];
      timezone[i] = holding[12];
      zip_code[i] = holding[13];
    } else {
      status[i] = holding[0];
    }
    i++;
  }
  
  return DataFrame::create(_["as_code"] = as_code,
                           _["city_name"] = city_name,
                           _["country_name"] = country_name,
                           _["country_code"] = country_code,
                           _["isp"] = isp,
                           _["latitude"] = latitude,
                           _["longitude"] = longitude,
                           _["organisation"] = organisation,
                           _["region_code"] = region_code,
                           _["region_name"] = region_name,
                           _["timezone"] = timezone,
                           _["zip_code"] = zip_code,
                           _["status"] = status,
                           _["stringsAsFactors"] = false);
}

// [[Rcpp::export]]
DataFrame freegeoip_to_df(std::list < std::vector < std::string > > x){
  int input_size = x.size();
  int i = 0;
  std::vector < std::string > holding;
  std::list<std::vector < std::string > >::iterator it;
  
  std::vector < std::string > ip(input_size);
  std::vector < std::string > country_code(input_size);
  std::vector < std::string > country_name(input_size);
  std::vector < std::string > region_code(input_size);
  std::vector < std::string > region_name(input_size);
  std::vector < std::string > city(input_size);
  std::vector < std::string > zip_code(input_size);
  std::vector < std::string > time_zone(input_size);
  std::vector < std::string > latitude(input_size);
  std::vector < std::string > longitude(input_size);
  std::vector < std::string > metro_code(input_size);
  std::vector < std::string > status(input_size);
  
  for(it = x.begin(); it != x.end(); it++){
    holding = *it;
    if(holding.size() == 11){
      ip[i] = holding[0];
      country_code[i] = holding[1];
      country_name[i] = holding[2];
      region_code[i] = holding[3];
      city[i] = holding[4];
      zip_code[i] = holding[5];
      time_zone[i] = holding[6];
      latitude[i] = holding[7];
      longitude[i] = holding[9];
      metro_code[i] = holding[10];
      status[i] = "Success";
    } else {
      status[i] = holding[0];
    }
    i++;
  }
  
  return DataFrame::create(_["ip_address"] = ip,
                           _["country_code"] = country_code,
                           _["country_name"] = country_name,
                           _["region_code"] = region_code,
                           _["city"] = city,
                           _["zip_code"] = zip_code,
                           _["time_zone"] = time_zone,
                           _["latitude"] = latitude,
                           _["longitude"] = longitude,
                           _["metro_code"] = metro_code,
                           _["status"] = status,
                           _["stringsAsFactors"] = false);
}

//[[Rcpp::export]]
DataFrame telize_to_df(std::list < std::vector < std::string > > x){
  int input_size = x.size();
  int i = 0;
  std::vector < std::string > holding;
  std::list<std::vector < std::string > >::iterator it;
  
  std::vector < std::string > ip(input_size);
  std::vector < std::string > country_code(input_size);
  std::vector < std::string > country_name(input_size);
  std::vector < std::string > asn(input_size);
  std::vector < std::string > continent(input_size);
  std::vector < std::string > area_code(input_size);
  std::vector < std::string > isp(input_size);
  std::vector < std::string > latitude(input_size);
  std::vector < std::string > longitude(input_size);
  std::vector < std::string > dma_code(input_size);
  std::vector < std::string > country_code_3(input_size);
  std::vector < std::string > status(input_size);
  
  for(it = x.begin(); it != x.end(); it++){
    holding = *it;
    if(holding.size() == 11){
      longitude[i] = holding[0];
      latitude[i] = holding[1];
      asn[i] = holding[2];
      ip[i] = holding[3];
      area_code[i] = holding[4];
      continent[i] = holding[5];
      dma_code[i] = holding[6];
      country_code[i] = holding[7];
      isp[i] = holding[8];
      country_name[i] = holding[9];
      country_code_3[i] = holding[10];
      status[i] = "Success";
    } else {
      status[i] = holding[0];
    }
    i++;
  }
  
  return DataFrame::create(_["longitude"] = longitude,
                           _["latitude"] = latitude,
                           _["asn"] = asn,
                           _["ip"] = ip,
                           _["area_code"] = area_code,
                           _["continent_code"] = continent,
                           _["dma_code"] = dma_code,
                           _["country_code"] = country_code,
                           _["isp"] = isp,
                           _["country_name"] = country_name,
                           _["country_code_3"] = country_code_3,
                           _["status"] = status,
                           _["stringsAsFactors"] = false);
}