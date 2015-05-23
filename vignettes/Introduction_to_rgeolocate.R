## ------------------------------------------------------------------------
library(rgeolocate)
file <- system.file("extdata","GeoLite2-Country.mmdb", package = "rgeolocate")
results <- maxmind("196.200.60.51", file, c("continent_name", "country_code", "country_name"))
results

