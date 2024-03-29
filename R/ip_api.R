query_ip_api <- function(ip, sleep){
  if(sleep){
    Sys.sleep(0.40)
  }
  url <- paste0("https://ip-api.com/json/", ip)
  
  result <- httr::GET(url, user_agent("rgeolocate - https://github.com/Ironholds/rgeolocate"))
  if(result$status > 300){
    return("Error")
  }
  
  parsed_results <- httr::content(result, as = "parsed", type = "application/json")
  if(parsed_results$status == "fail"){
    return("Error")
  }
  return(unlist(parsed_results))
}

#'@title Geolocate IP Addresses Through ip-api.com
#'@description \code{ip_api} consumes a vector of IP addresses
#'and geolocates them via \href{https://ip-api.com}{ip-api.com}.
#'
#'@param ip_addresses a character vector of IP addresses
#'
#'@param as_data_frame whether to return the results as a data.frame or not.
#'Set to TRUE by default.
#'
#'@param delay whether or not to delay each request by 400ms. ip-api.com has a
#'maximum threshold of 150 requests a minute; if you're parallelising calls, you
#'might run into this. \code{delay} allows you to set a delay between requests, taking
#'advantage of parallelisation while avoiding running into this threshold. Set to
#'FALSE by default
#'
#'@return either a data.frame or a list of vectors. If an IP cannot be geolocated, it
#'will provide an error message: see the examples for field names and examples of each
#'possible output.
#'
#'@seealso \code{\link{ip_info}} and \code{\link{db_ip}} for other
#'online geolocation APIs.
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
ip_api <- function(ip_addresses, as_data_frame = TRUE, delay = FALSE){
  results <- lapply(ip_addresses, query_ip_api, delay)
  if(as_data_frame){
    return(ip_to_df(results))
  }
  
  return(results)
}
