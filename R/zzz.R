rgeo_env <- new.env(parent = emptyenv())

.onLoad <- function(...) {
  maxmind_tags <- c("continent_name", "country_name", "country_code", "region_name",
                    "city_name", "timezone", "connection", "city_geoname_id", "latitude", "longitude",
                    "isp", "organization", "asn", "aso", "postcode")
  assign("maxmind_tags", maxmind_tags, envir = rgeo_env)
}