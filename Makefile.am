AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libtprint.la
include_HEADERS = tprint.h

noinst_PROGRAMS = test_tprint

libtprint_la_SOURCES = tprint.c
libtprint_la_LDFLAGS = $(DEPS_LIBS)
libtprint_la_CFLAGS = $(DEPS_CFLAGS)

test_tprint_SOURCES = test_tprint.c
test_tprint_CFLAGS = $(DEPS_CFLAGS) 
test_tprint_LDADD = $(DEPS_LIBS) libtprint.la
