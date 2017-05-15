#ifndef MAXMINDDB_CONFIG_H
#define MAXMINDDB_CONFIG_H


/* Modified 5/14/17 Drew Schmidt */
#if (defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__TOS_WIN__) || defined(__WINDOWS__))
#define OS_WINDOWS 1
#else
#define OS_WINDOWS 0
#endif

#define MMDB_UINT128_USING_MODE     0
#define MMDB_UINT128_IS_BYTE_ARRAY  1

#if OS_WINDOWS
  #define PACKAGE_VERSION "1.0.4"
#else
  #include "config.h"
#endif


#endif                          /* MAXMINDDB_CONFIG_H */
