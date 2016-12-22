## Generalised IP geolocation through R

__Author(s:__ Oliver Keyes, Drew Schmidt<br/>
__License:__ Apache 2.0
__Status:__ Stable
__Current release:__ 0.8.0 ("It's A Map")

[![Travis-CI Build Status](https://travis-ci.org/Ironholds/rgeolocate.svg?branch=master)](https://travis-ci.org/Ironholds/rgeolocate) ![downloads](http://cranlogs.r-pkg.org/badges/grand-total/rgeolocate)

IP geolocation is a powerful tool to have if you're dealing with web data, and there are a couple of R packages that
provide access to specific services, such as the legacy rgeoip package
or Bob Rudis's [ipapi](https://github.com/hrbrmstr/ipapi). They're all spread about and have diffing interfaces,
styles and requirements.

`rgeolocate` aims to be a single generalised package for geolocation; if you have a source you'd like to pull from, the
goal is that `rgeolocate` will provide a binding to it. As of the 0.8.0 release, it contains:

1. A binding to the binary MaxMind databases;
2. Wrappers around multiple online geolocation services ([see the vignette](https://github.com/Ironholds/rgeolocate/blob/master/vignettes/Introduction_to_rgeolocate.Rmd)
for more)

If you have other bindings you'd like to see, [open a request](https://github.com/Ironholds/rgeolocate/issues)!

Please note that this project is released with a [Contributor Code of Conduct](CONDUCT.md). By participating in this project you agree to abide by its terms.

### Installation

For the latest CRAN release:

    install.packages("rgeolocate")

For the development version:

    devtools::install_github("ironholds/rgeolocate")
    
### Dependencies
`rgeolocate` depends on [httr](https://cran.r-project.org/package=httr) for the bindings
to web databases; other than that, just base R! Thanks to the work of Drew Schmidt, `rgeolocate` includes the underlying
MaxMind library and its dependencies.
