query_freegeoip <- function(ip){
  result <- query(paste0("http://freegeoip.net/json/", ip))
  if(length(result) == 1){
    return(result)
  }
  return(unlist(result))
}

#'@title Geolocate IP Addresses Through freegeoip.net
#'@description \code{freegeoip} consumes a vector of IP addresses
#'and geolocates them via \href{http://freegeoip.net}{freegeoip.net}.
#'
#'@param ip_addresses a character vector of IP addresses
#'
#'@param as_data_frame whether to return the results as a data.frame or not.
#'Set to TRUE by default.
#'
#'@return either a data.frame or a list of vectors. If an IP cannot be geolocated, it
#'will provide an error message: see the examples for field names and examples of each
#'possible output.
#'
#'@examples
#'\dontrun{
#'#Valid, data.frame output
#'result <- freegeoip("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93")
#'
#'#Invalid, data.frame output
#'result <- freegeoip("argh")
#'
#'#Valid list output
#'result <- freegeoip("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93", as_data_frame = FALSE)
#'
#'#Invalid list output
#'result <- freegeoip("argh", as_data_frame = FALSE)
#'}
#'
#'@export
freegeoip <- function(ip_addresses, as_data_frame = TRUE){
  
  results <- lapply(ip_addresses, query_freegeoip)
  
  if(as_data_frame){
    return(freegeoip_to_df(results))
  }
  return(results)
}