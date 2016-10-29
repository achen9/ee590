CXX = g++ -O0 -std=c++11 -Wall
LIBS = -ljson
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cc 2.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libjson.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@ -g

test: $(TARGETS)
	./test.sh

memtest1: $(TARGETS)
	valgrind --leak-check=yes ./1.x

clean:
	rm -rf $(TARGETS)
