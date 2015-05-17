#' @title IP Geolocation in R
#' @name rgeolocate
#' @description This package aims to provide connectors to myriad online and offline sources for
#' taking IP addresses and geolocating them to country, city, timezone and a whole other host of goodies.
#' For individual connectors, see the package index. It depends on libmaxminddb, which can be obtained and
#' installed from https://github.com/maxmind/libmaxminddb
#' 
#' @useDynLib rgeolocate
#' @importFrom Rcpp sourceCpp
#' @importFrom httr user_agent GET content
#' @docType package
#' @aliases rgeolocate rgeolocate-package
NULL