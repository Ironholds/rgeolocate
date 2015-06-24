#ifndef MAXMINDDB_CONFIG_H
#define MAXMINDDB_CONFIG_H


/* Modified 5/26/15 Drew Schmidt */
#define OS_WIN32 (defined(__WIN32) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__))
#define OS_WIN64 (defined(__WIN64) || defined(_WIN64) || defined(__WIN64__))

// Winows assumptions: 1. you're using MinGW, 2. no ability to run configure
#if OS_WIN32
  #define MMDB_UINT128_USING_MODE     0
  #define MMDB_UINT128_IS_BYTE_ARRAY  1
#elif OS_WIN64
  #define MMDB_UINT128_USING_MODE     1
  #define MMDB_UINT128_IS_BYTE_ARRAY  1
#else
  #include "config.h"
#endif

#if OS_WIN32 || OS_WIN64
  #define PACKAGE_VERSION "1.0.4"
#endif



#ifndef MMDB_UINT128_USING_MODE
/* Define as 1 if we we use unsigned int __atribute__ ((__mode__(TI))) for uint128 values */
#define MMDB_UINT128_USING_MODE 0
#endif

#ifndef MMDB_UINT128_IS_BYTE_ARRAY
/* Define as 1 if we don't have an unsigned __int128 type */
#undef MMDB_UINT128_IS_BYTE_ARRAY
#endif

#endif                          /* MAXMINDDB_CONFIG_H */
