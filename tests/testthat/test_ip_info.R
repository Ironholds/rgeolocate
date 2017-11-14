context("Test ipinfo")

test_that("data.frames can be returned from ip-api", {
  result <-  ip_info("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93")
  expect_that(is.data.frame(result), equals(TRUE))
  expect_that(nrow(result), equals(1))
})

test_that("data.frames with false entries can be returned from ip-api", {
  result <- ip_info(c("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93",
                      "foo"))
  expect_that(is.data.frame(result), equals(TRUE))
  expect_that(nrow(result), equals(2))
  expect_true(any(is.na(result)))
})