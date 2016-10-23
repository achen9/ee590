CXX = g++ -std=c++11
LIBS = -lm -lfraction -lcomplex
INCLUDE_DIRS = -I.. -I../../prob1/ -I../../prob2/
LIBDIRS = -L..

SOURCES = P3_double.cc P3_int.cc P3_bool.cc P3_fraction.cc P3_complex.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../*.hh ../libfraction.a ../libcomplex.a
	$(CXX)  $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
