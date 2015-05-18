query_ip_api <- function(ip){
  result <- query(paste0("http://ip-api.com/json/", ip))
  if(result$status == "fail"){
    return(paste("Request failed:", result$message))
  }
  
  return(unlist(result))
}

#'@title Geolocate IP Addresses Through ip-api.com
#'@description \code{ip_api} consumes a vector of IP addresses
#'and geolocates them via \href{http://ip-api.com}{ip-api.com}.
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
#'result <- ip_api("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93")
#'
#'#Invalid, data.frame output
#'result <- ip_api("argh")
#'
#'#Valid list output
#'result <- ip_api("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93", as_data_frame = FALSE)
#'
#'#Invalid list output
#'result <- ip_api("argh", as_data_frame = FALSE)
#'}
#'@export
ip_api <- function(ip_addresses, as_data_frame = TRUE){
  results <- lapply(ip_addresses, query_ip_api)
  if(as_data_frame){
    return(ip_to_df(results))
  }
  
  return(results)
}
