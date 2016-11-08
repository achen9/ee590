CXX = g++ -std=c++11
LIBS = -ljson
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cc 2.cc 3.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libjson.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@ -g

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)