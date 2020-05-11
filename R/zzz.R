rgeo_env <- new.env(parent = emptyenv())

.onLoad <- function(...) {
  maxmind_tags <- c("continent_name", "country_name", "country_code", "region_name",
                    "city_name", "timezone", "connection", "city_geoname_id", "latitude", "longitude",
                    "isp", "organization", "asn", "aso", "postcode","city_metro_code")
  ipinfo_tags <- c("hostname", "city", "region", "country",
                   "loc", "org", "postal", "phone")
  
  ip2loc_tags <- c("country_code", "country_name", "region", "city", "isp", "lat", 
                   "long", "domain", "zip_code", "timezone", "netspeed", "international_code", 
                   "area_code", "station_code", "station_name", "mcc", "mnc", "mobile_brand", 
                   "elevation", "usage_type")
  
  assign("maxmind_tags", maxmind_tags, envir = rgeo_env)
  assign("ipinfo_tags", ipinfo_tags, envir = rgeo_env)
  assign("ip2loc_tags", ip2loc_tags, envir = rgeo_env)
}