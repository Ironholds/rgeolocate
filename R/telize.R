query_telize <- function(ip){
  result <- query(paste0("http://www.telize.com/geoip/", ip))
  if(length(result) == 1){
    return(result)
  }
  return(unlist(result))
}

telize <- function(ip_addresses, as_data_frame = TRUE){
  
  results <- lapply(ip_addresses, query_telize)
  
  if(as_data_frame){
    return(telize_to_df(results))
  }
  return(results)
}