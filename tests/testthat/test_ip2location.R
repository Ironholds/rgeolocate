context("Test ip2location")
test_that("non-existent files are detected", {
  expect_that(ip2location("foo", "bar"), throws_error("could not be opened"))
})

test_that("non-existent IPs are detected", {
  file <- system.file("extdata","ip2_4_sample.bin", package = "rgeolocate")
  results <- ip2location("foo", file, "country_name")
  expect_true(is.na(results[1,1]))
})