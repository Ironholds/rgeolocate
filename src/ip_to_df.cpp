#include <Rcpp.h>
using namespace Rcpp;

String check_str(String x){
  if(x == ""){
    return NA_STRING;
  }
  return x;
}

// [[Rcpp::export]]
DataFrame ip_to_df(List x){
  
  //Iterators and holding entries
  int input_size = x.size();
  int i = 0;
  CharacterVector holding;
  
  CharacterVector as_code(input_size, NA_STRING);
  CharacterVector city_name(input_size, NA_STRING);
  CharacterVector country_name(input_size, NA_STRING);
  CharacterVector country_code(input_size, NA_STRING);
  CharacterVector isp(input_size, NA_STRING);
  CharacterVector latitude(input_size, NA_STRING);
  CharacterVector longitude(input_size, NA_STRING);
  CharacterVector organisation(input_size, NA_STRING);
  CharacterVector region_code(input_size, NA_STRING);
  CharacterVector region_name(input_size, NA_STRING);
  CharacterVector timezone(input_size, NA_STRING);
  CharacterVector zip_code(input_size, NA_STRING);
  CharacterVector status(input_size, NA_STRING);
  
  for(List::iterator it = x.begin(); it != x.end(); ++it ){
    holding = *it;
    if(holding.size() == 14){
      as_code[i] = check_str(holding[12]);
      city_name[i] = check_str(holding[5]);
      country_name[i] = check_str(holding[1]);
      country_code[i] = check_str(holding[2]);
      isp[i] = check_str(holding[10]);
      latitude[i] = check_str(holding[7]);
      longitude[i] = check_str(holding[8]);
      organisation[i] = check_str(holding[11]);
      region_code[i] = check_str(holding[3]);
      region_name[i] = check_str(holding[4]);
      status[i] = check_str(holding[0]);
      timezone[i] = check_str(holding[9]);
      zip_code[i] = check_str(holding[6]);
    } else {
      status[i] = check_str(check_str(holding[0]));
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