ip2location <- function(ips, file, use_memory = TRUE,
                        fields = c("country_code", "country_name")){
  
  possible_fields <- c("country_code", "country_name", "region", "city", "isp", "lat", 
                       "long", "domain", "area_code", "timezone", "netspeed", "international_code", 
                       "area_code", "station_code", "station_name", "mcc", "mnc", "mobile_brand", 
                       "elevation", "usage_type")
  
  if(any(!fields %in% possible_fields)){
    warning("Some entries in 'fields' are not valid and will be removed")
    fields <- fields[fields %in% possible_fields]
  }
  
  stopifnot(!is.na(file))
  
  return(ip2location_(ips, fields, file, use_memory))
}