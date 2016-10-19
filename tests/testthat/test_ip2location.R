context("Test ip2location")
file <- system.file("extdata","ip2_4_sample.bin", package = "rgeolocate")
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