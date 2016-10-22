CXX = g++ -std=c++11 -O3
LIBS = -lm -lcomplex
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 01.cc 02.cc 03.cc 04.cc 05.cc 06.cc 07.cc 08.cc 09.cc 10.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libcomplex.a
	$(CXX)  $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)