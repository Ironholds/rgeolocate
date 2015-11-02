query_telize <- function(ip){
  url <-paste0("http://www.telize.com/geoip/", ip)
  result <- GET(url, user_agent("rgeolocate - https://github.com/Ironholds/rgeolocate"))
  if(result$status > 300){
    return("Error")
  }
  return(unlist(content(result, as = "parsed", type = "application/json")))
}

#'@title Geolocate IP Addresses Through telize.com
#'@description \href{http://www.telize.com}{telize.com} provides IP geolocation based
#'on MaxMind's free downloadable databases (one of which is, distinctly, included in
#'this package). \code{telize} allows you to query the Telize service to geolocate
#'IPv4 or IPv6 IP addresses.
#'
#'@param ip_addresses a vector of IP addresses.
#'
#'@param as_data_frame whether to return the results as a data.frame (TRUE)
#'or a list of named vectors (FALSE). Set to TRUE by default.
#'
#'@return either a data.frame or a list of named vectors, depending on
#'the option for \code{as_data_frame}
#'
#'@examples
#'\dontrun{
#'#Valid, data.frame output
#'result <- telize("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93")
#'
#'#Invalid, data.frame output
#'result <- telize("argh")
#'
#'#Valid list output
#'result <- telize("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93", as_data_frame = FALSE)
#'
#'#Invalid list output
#'result <- telize("argh", as_data_frame = FALSE)
#'}
#'@export
telize <- function(ip_addresses, as_data_frame = TRUE){
  
  results <- lapply(ip_addresses, query_telize)
  
  if(as_data_frame){
    return(telize_to_df(results))
  }
  return(results)
}

#'@title Obtain and geolocate current (external) client IP address
#'@description \href{http://www.telize.com}{telize.com} provides IP geolocation based
#'on MaxMind's free downloadable databases. \code{client_info} uses Telize to determine
#'the IP address of the current user/client and return the IP address and associated
#'geolocation info, making it suitable for providing customization (i.e. function
#'defaults) based on client location data. 
#'
#'@param as_data_frame whether to return the results as a data.frame (TRUE)
#'or a list of named vectors (FALSE). Set to TRUE by default.
#'
#'@note This function requires internet access.
#'
#'@return either a data.frame or a list of named vectors, depending on
#'the option for \code{as_data_frame}
#'
#'@author Bob Rudis
#'
#'@examples
#'\dontrun{
#' info <- client_info()
#'}
#'@export
client_info <- function(as_data_frame = TRUE) {
  
  results <- content(GET("http://www.telize.com/geoip"),
                     as = "parsed", type = "application/json")

  if (as_data_frame) {
    return(data.frame(results, stringsAsFactors=FALSE))
  }
  
  return(results)

}

