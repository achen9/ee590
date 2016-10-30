CXX = g++ -O0 -std=c++11 -Wall
LIBS = -ljson
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cc 2.cc 3.cc 4.cc 5.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libjson.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@ -g

test: $(TARGETS)
	./test.sh

memtest1: $(TARGETS)
	valgrind --leak-check=yes ./1.x

memtest2: $(TARGETS)
	valgrind --leak-check=yes ./2.x

memtest3: $(TARGETS)
	valgrind --leak-check=yes ./3.x

memtest4: $(TARGETS)
	valgrind --leak-check=yes ./4.x

memtest5: $(TARGETS)
	valgrind --leak-check=yes ./5.x

clean:
	rm -rf $(TARGETS)
