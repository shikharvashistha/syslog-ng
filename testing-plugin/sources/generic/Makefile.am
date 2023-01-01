module_LTLIBRARIES      += modules/generic/libgeneric.la
modules_generic_libgeneric_la_SOURCES = \
  modules/generic/generic-grammar.y       \
  modules/generic/generic-parser.c        \
  modules/generic/generic-parser.h        \
  modules/generic/generic-plugin.c

BUILT_SOURCES       +=      \
  modules/generic/generic-grammar.y       \
  modules/generic/generic-grammar.c       \
  modules/generic/generic-grammar.h

EXTRA_DIST        +=      \
  modules/generic/generic-grammar.ym \
  modules/generic/CMakeLists.txt

modules_generic_libgeneric_la_CPPFLAGS  =     \
  $(AM_CPPFLAGS)            \
  -I$(top_srcdir)/modules/generic        \
  -I$(top_builddir)/modules/generic
modules_generic_libgeneric_la_LIBADD  = $(MODULE_DEPS_LIBS)
modules_generic_libgeneric_la_LDFLAGS = $(MODULE_LDFLAGS)
modules_generic_libgeneric_la_DEPENDENCIES= $(MODULE_DEPS_LIBS)

modules/generic modules/generic/ mod-generic: modules/generic/libgeneric.la
.PHONY: modules/generic/ mod-generic
