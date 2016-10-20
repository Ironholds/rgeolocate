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
#'@param use_memory Whether to cache the binary in memory or not. Caching it drastically
#'increases the speed of geolocation, but may be too much for very old machines. Set to
#'TRUE by default.
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
#'  \item{timezone}{: }
#'  \item{netspeed}{: }
#'  \item{international_code}{: }
#'  \item{area_code}{: }
#'  \item{station_code}{: }
#'  \item{station_name}{: }
#'  \item{mcc}{: }
#'  \item{mnc}{: }
#'  \item{mobile_brand}{: }
#'  \item{elevation}{: }
#'  \item{usage_type}{: }
#'}
#'
#'@return
#'
#'@examples
#'
#'@seealso
#'
#'@export
ip2location <- function(ips, file, use_memory = TRUE,
                        fields = c("country_code", "country_name")){
  
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