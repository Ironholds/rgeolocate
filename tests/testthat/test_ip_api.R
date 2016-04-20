context("Test ip-api")

test_that("data.frames can be returned from ip-api", {
  result <- try({
    ip_api("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93")},
    silent = TRUE)
  if(!"try-error" %in% class(result)){
    expect_that(is.data.frame(result), equals(TRUE))
    expect_that(nrow(result), equals(1))
    expect_that(ncol(result), equals(13))
  }
})

test_that("Lists can be returned from ip-api", {
  result <- try({
    ip_api("2607:FB90:426:DC1D:CFC4:4875:8BC2:4D93", FALSE)},
    silent = TRUE)
  if(!"try-error" %in% class(result)){
    expect_that(is.list(result), equals(TRUE))
    expect_that(length(result), equals(1))
    expect_that(length(result[[1]]), equals(14))
  }
})

test_that("data.frames with errors can be returned from ip-api", {
  result <- try({
    ip_api("Go ahead and try to hit me if you're able, can't you see that my relationship is stable")},
    silent = TRUE)
  if(!"try-error" %in% class(result)){
    expect_that(is.data.frame(result), equals(TRUE))
    expect_that(nrow(result), equals(1))
    expect_that(ncol(result), equals(13))
    expect_that(result$status[1], equals("Error"))
  }
})