context("Test ip-api")

test_that("data.frames can be returned from ip-api", {
  result <- ip_api("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93")
  expect_that(is.data.frame(result), equals(TRUE))
  expect_that(nrow(result), equals(1))
  expect_that(ncol(result), equals(13))
})

test_that("Lists can be returned from ip-api", {
  result <- ip_api("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93", FALSE)
  expect_that(is.list(result), equals(TRUE))
  expect_that(length(result), equals(1))
  expect_that(length(result[[1]]), equals(14))
})

test_that("data.frames with errors can be returned from ip-api", {
  result <- ip_api("Go ahead and try to hit me if you're able, can't you see that my relationship is stable")
  expect_that(is.data.frame(result), equals(TRUE))
  expect_that(nrow(result), equals(1))
  expect_that(ncol(result), equals(13))
  expect_that(result$status[1], equals("Error"))
})

test_that("client_info() works", {
  result <- client_info()
  expect_that(is.data.frame(result), equals(TRUE))
  expect_that(nrow(result), equals(1))
})