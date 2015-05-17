query <- function(url){
  result <- GET(url, user_agent("rgeolocate - https://github.com/Ironholds/rgeolocate"))
  return(content(result, as = "parsed", type = "application/json"))
}