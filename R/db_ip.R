query_db_ip <- function(ip, key){
  url <- paste0("http://api.db-ip.com/addrinfo?addr=", ip, "&api_key=", key)
  result <- GET(url, user_agent("rgeolocate - https://github.com/Ironholds/rgeolocate"))
  if(result$status > 300){
    return("Error")
  }
  return(unlist(content(result, as = "parsed", type = "application/json")))
}

#'@title Geolocate IP Addresses Through db-ip.com
#'@description \code{ip_api} consumes a vector of IP addresses
#'and geolocates them via \href{https://db-ip.com/}{db-ip.com}.
#'See `Details` for more information.
#'
#'@param ip_addresses a character vector of IP addresses.
#'
#'@param key a db-ip.com API key.
#'
#'@details \href{http://db-ip.com/}{db-ip.com} provides IP geolocation,
#'either for free (with a cap of 2,500 requests a day) or in various paid tiers.
#'
#'To use the service, register there for an API key, and plug that key and the
#'IP addresses into \code{\link{db_ip}}
#'
#'@return a list of lists, each containing the geolocated values for one IP address.
#'The variables found depend on the level of access your API key has; see the
#'\href{http://db-ip.com/api/#key}{API documentation} for more information.
#'
#'@examples
#'\dontrun{
#'db_ip(ip_addresses = "173.194.67.1", key = "ThisIsNotARealKey")
#'}
#'@export
db_ip <- function(ip_addresses, key){
  lapply(ip_addresses, query_db_ip, key = key)
}