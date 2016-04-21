#'@title Geolocate IP Addresses through MaxMind Databases
#'@description MaxMind does a set of proprietary geolocation databases
#'- they're pretty accurate! \code{maxmind} provides a connector to
#'MaxMind services.
#'
#'@param ips a character vector of IP addresses (IPv4 and IPv6 both work)
#'
#'@param file the full path to the .mmdb file you want to query. 
#'
#'@param fields the fields you want to retrieve - options are:
#'\itemize{
#'  \item{continent_name}{: the English-language name of the continent. Requires a country or city database.}
#'  \item{country_name}{: the English-language name of the country Requires a country or city database.}
#'  \item{country_code}{: the ISO code of the country. Requires a country or city database.}
#'  \item{region_name}{: the English-language name of the region. Requires a city database.}
#'  \item{city_name}{: the English-language name of the city. Requires a city database.}
#'  \item{city_geoname_id}{: a unique ID representing a city. Requires a city database. }
#'  \item{timezone}{: the tzdata-compatible time zone. Requires a city database.}
#'  \item{longitude}{: latitude of location. Requires a city database.}
#'  \item{latitude}{: longitude of location. Requires a city database.}
#'  \item{connection}{: the type of internet connection. Requires a connection type/netspeed database.}
#'}
#'@details
#'\code{geolookup} uses the \href{http://dev.maxmind.com/geoip/geoip2/downloadable/}{MaxMind GeoIP2 databases}
#'to geolocate IP addresses, retrieving any of the data listed in \code{fields}. Different fields are
#'appropriate for different provided files; the connection type databases, for example, contain connection
#'types and nothing else, while the city- and country-level files don't contain connection types at all.
#'
#'\code{rgeolocate} ships with a country-level database (accessing it can be seen in the examples). If
#'you need city-level data, or other MaxMind databases, you'll need to download the \code{.mmdb} files
#'yourself - for CRAN and/or copyright reasons, depending, we cannot include them.
#'
#'In the event that the file provided does not have the field you have requested (or the IP address does
#'not have an entry for that field), NA will be returned instead. In the event that the IP
#'address doesn't have an entry in the file at all, NA will be returned for every field.
#'
#'@examples
#'
#'# An example, using the country-level dataset shipped with rgeolocate.
#'file <- system.file("extdata","GeoLite2-Country.mmdb", package = "rgeolocate")
#'results <- maxmind("196.200.60.51", file, "country_code")
#'@export
maxmind <- function(ips, file, fields = c("continent_name", "country_name", "country_code")){
  possible_fields <- c("continent_name", "country_name", "country_code", "region_name",
                       "city_name", "timezone", "connection", "city_geoname_id", "latitude", "longitude")
  
  if(!all(fields %in% possible_fields)){
    warning("Some field names you have provided are not supported and no data will be retrieved for them. \nThe
            unsupported fields are: ", paste(fields[!fields %in% possible_fields], collapse = ", "))
    fields <- fields[fields %in% possible_fields]
  }

  return(maxmind_(ips, file, fields))
}