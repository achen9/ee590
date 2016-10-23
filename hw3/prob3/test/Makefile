CXX = g++ -std=c++11
LIBS = -lm -lfraction -lcomplex
INCLUDE_DIRS = -I.. -I../../prob1/ -I../../prob2/
LIBDIRS = -L..

SOURCES = 1_double.cc 2_int.cc 3_bool.cc 4_fraction.cc 5_complex.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../*.hh ../libfraction.a ../libcomplex.a
	$(CXX)  $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
