context("Test ip2location")
file <- system.file("extdata","ip2_sample.bin", package = "rgeolocate")
test_ips <- c("66.249.69.245","2A04:0000:0000:0000:0000:0000:0000:0000")

test_that("non-existent files are detected", {
  expect_that(ip2location("foo", "bar"), throws_error("could not be opened"))
})

test_that("non-existent IPs are detected", {
  results <- ip2location("foo", file, "country_name")
  expect_true(is.na(results[1,1]))
})

test_that("IPv4 and 6 geolocation works with large-field files", {
  results <- ip2location(ips = test_ips, fields = "country_name", file = file)
  expect_identical(results$country_name, c("United States", "Germany"))
})

test_that("Lat/long retrieval works", {
  result <- ip2location(test_ips, file, c("lat", "long"))
  expect_true(is.na(result$lat[1]))
  expect_gt(result$lat[2], 50)
  expect_lt(result$lat[2], 51)
  expect_true(is.na(result$long[1]))
  expect_gt(result$long[2], 8)
  expect_lt(result$long[2], 9)
  
  
})