query <- function(url){
  result <- GET(url, user_agent("rgeolocate - https://github.com/Ironholds/rgeolocate"))
  if(result$status < 300){
    return(content(result, as = "parsed", type = "application/json"))
  } else {
    return("Error")
  }
}