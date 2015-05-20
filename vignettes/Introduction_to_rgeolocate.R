## ------------------------------------------------------------------------
library(rgeolocate)
file <- system.file("extdata","GeoLite2-Country.mmdb", package = "rgeolocate")
results <- maxmind("196.200.60.51", file)
results

