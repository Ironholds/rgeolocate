#'@title Geolocate IP Addresses through IP2Location Databases
#'@description IP2Location provides proprietary databases for IP geolocation;
#'this function acts as a binding to them, letting you efficiently geolocate
#'a vector of IP addresses to retrieve various values (much like \code{\link{maxmind}}).
#'Note that depending on the database type you have, certain fields may or may not be
#'available.
#'
#'@param ips A character vector of IP addresses.
#'
#'@param file The path to an IP2Location binary database.
#'
#'@param fields Which pieces of metadata to retrieve for each IP address. Options are:
#'\itemize{
#'  \item{country_code}{: the ISO code of the country.}
#'  \item{country_name}{: the English-language name of the country.}
#'  \item{region_name}{: the English-language name of the region.}
#'  \item{city}{: the English-language name of the city.}
#'  \item{isp}{: The Internet Service Provider}
#'  \item{lat}{: The latitude.}
#'  \item{long}{: The longitude.}
#'  \item{domain}{: The domain name associated with the IP (if any).}
#'  \item{zip_code}{: The Zip Code or Post Code or national equivalent.}
#'  \item{timezone}{: The timezone, in the format +02:00/-03:00 from UTC.}
#'  \item{netspeed}{: The internet connection class of the IP address.}
#'  \item{international_code}{: The international dialing code.}
#'  \item{area_code}{: The local dialing code.}
#'  \item{station_code}{: The identifying code of the nearest weather station. }
#'  \item{station_name}{: The name of the nearest weather station. }
#'  \item{mcc}{: The Mobile Country Code, which identifies mobile stations. }
#'  \item{mnc}{: The Mobile Network Code, which (with MCC) uniquely identifies the mobile carrier.}
#'  \item{mobile_brand}{: The commercial brand associated with the mobile carrier.}
#'  \item{elevation}{: The elevation of the location above sea level, in meters.}
#'  \item{usage_type}{: The type of organisation or purpose behind the IP; see the list
#'  \href{http://www.ip2location.com/docs/db24-ip-country-region-city-latitude-longitude-zipcode-timezone-isp-domain-netspeed-areacode-weather-mobile-elevation-usagetype-specification.pdf}{here}}.
#'}
#'Note that these fields may or may not be available depending on your database type.
#'
#'@param use_memory Whether to cache the binary in memory or not. Caching it drastically
#'increases the speed of geolocation, but may be too much for very old machines. Set to
#'TRUE by default.
#'
#'@return
#' A data.frame containing the geolocation metadata about \code{ips}; missing
#' values are represented by \code{NA}.
#' 
#'@examples
#'file <- system.file("extdata","ip2_sample.bin", package = "rgeolocate")
#'example_ip <- "2A04:0000:0000:0000:0000:0000:0000:0000"
#'
#'ip2location(example_ip, file, c("country_code", "country_name", "region", "city"))
#'
#'@seealso
#'\code{\link{maxmind}}, which uses MaxMind proprietary databases to get similar
#'information.
#'
#'@export
ip2location <- function(ips, file, fields = c("country_code", "country_name"),
                        use_memory = TRUE){
  
  possible_fields <- c("country_code", "country_name", "region", "city", "isp", "lat", 
                       "long", "domain", "zip_code", "timezone", "netspeed", "international_code", 
                       "area_code", "station_code", "station_name", "mcc", "mnc", "mobile_brand", 
                       "elevation", "usage_type")
  
  if(any(!fields %in% possible_fields)){
    warning("Some entries in 'fields' are not valid and will be removed")
    fields <- fields[fields %in% possible_fields]
  }
  
  stopifnot(!is.na(file))
  
  return(ip2location_(ips, fields, file, use_memory))
}