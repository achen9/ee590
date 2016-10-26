CXX = g++ -std=c++11
LIBS = -lm -lfraction -lcomplex -lDFT
INCLUDE_DIRS = -I.. 
LIBDIRS = -L..

P3_SOURCES = P3_double.cc P3_int.cc P3_bool.cc P3_fraction.cc P3_complex.cc
P4_SOURCES = P4_1.cc P4_2.cc P4_3.cc P4_4.cc P4_5.cc
P3_TARGETS = $(P3_SOURCES:%.cc=%.x)
P4_TARGETS = $(P4_SOURCES:%.cc=%.x)

all: $(P3_TARGETS) $(P4_TARGETS)

P3: $(P3_TARGETS)

P4: $(P4_TARGETS)

%.x: %.cc ../*.hh ../libfraction.a ../libcomplex.a ../libDFT.a
	$(CXX)  $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(P3_TARGETS) $(P4_TARGETS)
	./test.sh

clean:
	rm -rf $(P3_TARGETS) $(P4_TARGETS)
