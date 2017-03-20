AC_INIT([Himinbjörg], [0.1], [dennis.a.ek@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AC_CONFIG_MACRO_DIR([m4])
AC_PROG_CXX
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
                 Makefile
                 src/Makefile
                 ])

AM_PROG_AR()

LT_INIT()

AX_CXX_COMPILE_STDCXX(11)

PKG_CHECK_MODULES([glfw3],[glfw3])
PKG_CHECK_MODULES([glew],[glew])
PKG_CHECK_MODULES([gl],[gl])
PKG_CHECK_MODULES([icu],[icu-uc])
PKG_CHECK_MODULES([bullet],[bullet])
PKG_CHECK_MODULES([freetype2],[freetype2])

AC_OUTPUT

