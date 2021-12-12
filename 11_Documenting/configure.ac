#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Guess Number], [1.0], [])
AM_INIT_AUTOMAKE([foreign subdir-objects])
DX_INIT_DOXYGEN([Guess Number])
AC_CONFIG_SRCDIR([src/binsearch.c])
AC_CONFIG_HEADERS([config.h])
AC_PATH_PROG([HELP2MAN], [help2man])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CONFIG_FILES([Makefile src/Makefile Doxyfile])

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_OUTPUT
