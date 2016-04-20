context("Test MaxMind.")
test_that("non-existent files are detected", {
  expect_that(maxmind("foo","[@8"), throws_error("could not be opened"))
})

test_that("non-existent IPs are detected", {
  file <- system.file("extdata","GeoLite2-Country.mmdb", package = "rgeolocate")
  results <- maxmind("foo",file, "country_name")
  expect_true(is.na(results[1,1]))
})

test_that("IPs without entries are detected", {
  file <- system.file("extdata","GeoLite2-Country.mmdb", package = "rgeolocate")
  results <- maxmind("10.68.16.31",file, "country_name")
  expect_true(is.na(results[1,1]))
})

test_that("A df of the right dimensions is returned", {
  file <- system.file("extdata","GeoLite2-Country.mmdb", package = "rgeolocate")
  results <- maxmind("196.200.60.51",file, c("country_name", "country_code"))
  expect_that(nrow(results), equals(1))
  expect_that(ncol(results), equals(2))
  expect_that(is.data.frame(results), equals(TRUE))
  expect_that(names(results), equals(c("country_name", "country_code")))
})

test_that("A df of the right values is returned", {
  file <- system.file("extdata","GeoLite2-Country.mmdb", package = "rgeolocate")
  results <- maxmind("196.200.60.51",file, c("continent_name", "country_code", "country_name"))
  expect_that(results$continent_name[1], equals("Africa"))
  expect_that(results$country_code[1], equals("ML"))
  expect_that(results$country_name[1],equals("Mali"))
})


test_that("Longitude, latitude, and geoname_id can be retrieved", {
  test_files <- c("GeoIP2-City-Test.mmdb",
                  "GeoIP2-Precision-City-Test.mmdb")
  for (test_file in test_files) {
    infile <- system.file("extdata", test_file, package = "rgeolocate")
    results <- maxmind("2.125.160.216", infile, c("continent_name", "country_code",
                                       "country_name", "city_name",
                                       "latitude", "longitude", "city_geoname_id"))
    expect_that(results$continent_name[1], equals("Europe"))
    expect_that(results$country_code[1], equals("GB"))
    expect_that(results$country_name[1], equals("United Kingdom"))
    expect_that(results$city_name[1], equals("Boxford"))
    expect_that(results$latitude[1], equals(51.75))
    expect_that(results$longitude[1], equals(-1.25))
    expect_that(results$city_geoname_id[1], equals(2655045))
  }
})


test_that("Unknown longitude, latitude and geoname_id are returned as NA", {
  test_files <- c("GeoIP2-Anonymous-IP-Test.mmdb",
                  "GeoLite2-Country.mmdb")
  for (test_file in test_files) {
    infile <- system.file("extdata", test_file, package = "rgeolocate")
    results <- maxmind("2.125.160.216", infile, c("continent_name", "country_code",
                                                  "country_name", "city_name",
                                                  "latitude", "longitude",
                                                  "city_geoname_id"))
    expect_that(is.na(results$latitude[1]), is_true())
    expect_that(is.na(results$longitude[1]), is_true())
    expect_that(is.na(results$city_geoname_id[1]), is_true())
  }
})

