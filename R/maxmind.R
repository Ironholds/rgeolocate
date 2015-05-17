#'@title Geolocate IP Addresses through MaxMind Databases
#'@description MaxMind does a set of proprietary geolocation databases
#'- they're pretty accurate! \code{maxmind} provides a connector to
#'MaxMind services.
#'
#'@param ips a character vector of IP addresses (IPv4 and IPv6 both work)
#'
#'@param file the full path to the .mmdb file you want to query.
#'
#'@param fields the fields you want to return.
#'
#'@export
maxmind <- function(ips, file, fields){
  
}