#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Pcre Windows], [1.0], [])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([pcr_windows.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([ncursesw], [initscr], [], ["Couldn't find ncursesw lib"])
AC_CHECK_LIB([pcre2-8], [pcre2_compile_8], [], ["Couldn't find pcre2 lib"])

# Checks for header files.
AC_CHECK_HEADERS([ncurses.h], [], ["Couldn't find ncurses.h"])
AC_CHECK_HEADERS([locale.h], [], ["Couldn't find locale.h"])

# Checks for typedefs, structures, and compiler characteristics.
AC_ARG_WITH([UTF],
    [AS_HELP_STRING([--without-UTF],
        [Disable UCP flag])],
    [with_utf="no"])

AS_IF([test "x$with_utf" = "xno"], [
    AC_DEFINE(NO_UTF, [1], [UTF])
])

# Checks for library functions.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
