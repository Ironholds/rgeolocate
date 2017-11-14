ipinfo_single <- function(url){
  
  data <- httr::GET(url)
  
  if(data$status_code == 404){
    return(data.frame(
      hostname = NA,
      city = NA,
      region = NA,
      country = NA,
      loc = NA,
      org = NA,
      postal = NA,
      phone = NA,
      stringsAsFactors = FALSE
    ))
  }
  
  httr::stop_for_status(data)
  
  results <- httr::content(data)
  
  missing_vals <- setdiff(rgeo_env$ipinfo_tags, names(results))
  if(length(missing_vals)){
    for(val in missing_vals){
      results[[val]] <- NA
    }
  }
  results$ip <- NULL
  return(data.frame(results, stringsAsFactors = FALSE)[,])
}

#'@title Geolocate IP Addresses Through ipinfo.io
#'@description \code{ip_info} consumes a vector of IP addresses
#'and geolocates them via \href{http://ipinfo.io}{ipinfo.io}.
#'
#'@param ip_addresses a character vector of IP addresses
#'
#'@param token optionally, an API token. If you don't use one, you
#'can still use the system, but requests will be capped to 1,000 a day.
#'
#'@return either a data.frame containing the geolocated information.
#'If an IP cannot be geolocated, or values are not available, the
#'fields will be filled with \code{NA} values.
#'
#'@seealso \code{\link{ip_api}} and \code{\link{db_ip}} for other
#'online geolocation APIs.
#'
#'@examples
#'\dontrun{
#'#Valid, data.frame output
#'result <- ip_info("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93")
#'
#'#Invalid, data.frame output
#'result <- ip_info("argh")
#'
#'#Valid list output
#'result <- ip_info("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93", as_data_frame = FALSE)
#'
#'#Invalid list output
#'result <- ip_info("argh", as_data_frame = FALSE)
#'}
#'@export
ip_info <- function(ip_addresses, token = NULL){
  
  urls <- paste0("ipinfo.io/", ip_addresses,
                 ifelse(is.null(token), "",
                        paste0("?token=", token)))
  
  output <- do.call("rbind", lapply(urls, ipinfo_single))
  
  return(#cbind(data.frame(ip_address = ip_addresses,
              #            stringsAsFactors = FALSE),
               output)#)
}