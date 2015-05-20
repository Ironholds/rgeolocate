context("Test telize")

test_that("data.frames can be returned", {
  result <- telize("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93")
  expect_that(is.data.frame(result), equals(TRUE))
  expect_that(nrow(result), equals(1))
  expect_that(ncol(result), equals(12))
})

test_that("Lists can be returned", {
  result <- telize("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93", FALSE)
  expect_that(is.list(result), equals(TRUE))
  expect_that(length(result), equals(1))
  expect_that(length(result[[1]]), equals(11))
})

test_that("data.frames with errors can be returned", {
  result <- telize("Go ahead and try to hit me if you're able, can't you see that my relationship is stable")
  expect_that(is.data.frame(result), equals(TRUE))
  expect_that(nrow(result), equals(1))
  expect_that(ncol(result), equals(12))
  expect_that(result$status[1], equals("Error"))
})

test_that("Lists can be returned", {
  result <- freegeoip("I can see you hate the way we intermingle, but I think you're just mad cuz you're single", FALSE)
  expect_that(is.list(result), equals(TRUE))
  expect_that(length(result), equals(1))
  expect_that(length(result[[1]]), equals(1))
})