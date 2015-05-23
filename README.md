## Generalised IP geolocation through R

__Author:__ Oliver Keyes<br/>
__License:__ [MIT](http://opensource.org/licenses/MIT)<br/>
__Status:__ In development

IP geolocation is a powerful tool to have if you're dealing with web data, and there are a couple of R packages that
provide access to specific services, such as my [rgeoip](https://github.com/Ironholds/rgeoip) package
or Bob Rudis's [ipapi](https://github.com/hrbrmstr/ipapi). They're all spread about and have diffing interfaces,
styles and requirements.

`rgeolocate` aims to be a single generalised package for geolocation; if you have a source you'd like to pull from, the
goal is that `rgeolocate` will provide a binding to it. As of the 0.1.0 release, it contains:

1. A binding to the binary MaxMind databases;
2. Wrappers around multiple online geolocation services ([see the vignette](https://github.com/Ironholds/rgeolocate/blob/master/vignettes/Introduction_to_rgeolocate.Rmd)
for more)


If you have other bindings you'd like to see, [open a request](https://github.com/Ironholds/rgeolocate/issues)!

Please note that this project is released with a [Contributor Code of Conduct](CONDUCT.md). By participating in this project you agree to abide by its terms.

### Installation

For the 0.2.0 release:

    devtools::install_github("ironholds/rgeolocate", ref = "0.3.0")

For the development version:

    devtools::install_github("ironholds/rgeolocate")
    

### Dependencies
`rgeolocate` depends on [httr](http://cran.r-project.org/web/packages/httr/index.html) for the bindings
to web databases, and [libmaxminddb](https://github.com/maxmind/libmaxminddb) for the MaxMind binary
files. You'll need to install those for this to work for you.
