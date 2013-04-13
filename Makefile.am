AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libtprint.la
include_HEADERS = tprint.h

noinst_PROGRAMS = test_tprint test_tprint_dir_list

libtprint_la_SOURCES = tprint.c
libtprint_la_LDFLAGS = $(DEPS_LIBS)
libtprint_la_CFLAGS = $(DEPS_CFLAGS)

test_tprint_SOURCES = test_tprint.c
test_tprint_CFLAGS = $(DEPS_CFLAGS) 
test_tprint_LDADD = $(DEPS_LIBS) libtprint.la

test_tprint_dir_list_SOURCES = test_tprint_dir_list.c
test_tprint_dir_list_CFLAGS = $(DEPS_CFLAGS) 
test_tprint_dir_list_LDADD = $(DEPS_LIBS) libtprint.la
