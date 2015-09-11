#ifndef MAXMINDDB_CONFIG_H
#define MAXMINDDB_CONFIG_H


/* Modified 5/26/15 Drew Schmidt */
#define OS_WIN32 (defined(__WIN32) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__))
#define OS_WIN64 (defined(__WIN64) || defined(_WIN64) || defined(__WIN64__))

#define MMDB_UINT128_USING_MODE     0
#define MMDB_UINT128_IS_BYTE_ARRAY  1

#if OS_WIN32 || OS_WIN64
  #define PACKAGE_VERSION "1.0.4"
#else
  #include "config.h"
#endif


#endif                          /* MAXMINDDB_CONFIG_H */
