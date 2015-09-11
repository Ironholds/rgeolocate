### Modified version of the libmaxminddb configure.ac 6/23/2015
### Removed unneeded options and checks.

AC_PREREQ([2.63])
AC_INIT([libmaxminddb], [1.0.4])
AC_CONFIG_HEADERS([src/config.h])

AC_PROG_CC_C99

# Copied from http://stackoverflow.com/a/10682813/9832 and tweaked for C (as
# opposed to C++)
#
# AX_CHECK_CFLAGS(ADDITIONAL-CFLAGS, ACTION-IF-FOUND, ACTION-IF-NOT-FOUND)
#
# checks whether the $(CC) compiler accepts the ADDITIONAL-CFLAGS
# if so, they are added to the CXXFLAGS
AC_DEFUN([AX_CHECK_CFLAGS],
[
  AC_MSG_CHECKING([whether compiler accepts "$1"])
  cat > conftest.c << EOF
  int main(){
    return 0;
  }
EOF
  if $CC $CFLAGS -o conftest.o conftest.c [$1] > /dev/null 2>&1
  then
    AC_MSG_RESULT([yes])
    MAXMINDDB_CFLAGS="[$1]"
    [$2]
  else
    AC_MSG_RESULT([no])
   [$3]
  fi
])dnl AX_CHECK_CFLAGS

AX_CHECK_CFLAGS([-fms-extensions])

AC_C_RESTRICT

AC_CHECK_HEADERS([arpa/inet.h assert.h fcntl.h inttypes.h libgen.h math.h netdb.h netinet/in.h stdarg.h stdbool.h stdint.h stdio.h stdlib.h string.h sys/mman.h sys/socket.h sys/stat.h sys/time.h sys/types.h unistd.h])

AC_CHECK_TYPES([boolean])

AC_CHECK_FUNC(
        [open_memstream],
        [AC_DEFINE([HAVE_OPEN_MEMSTREAM], [1], [Has an open_memstream() function])])

AC_SEARCH_LIBS([getaddrinfo], [socket])

AC_SUBST(MAXMINDDB_CFLAGS)
AC_OUTPUT(src/Makevars)
