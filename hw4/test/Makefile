CXX = g++ -std=c++11 -Wall
LIBS = -ljson
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 2.cc 3.cc 4.cc 5.cc 6.cc 7.cc 8.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libjson.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

memtest2: $(TARGETS)
	valgrind --leak-check=yes ./2.x

memtest3: $(TARGETS)
	valgrind --leak-check=yes ./3.x

memtest4: $(TARGETS)
	valgrind --leak-check=yes ./4.x

memtest5: $(TARGETS)
	valgrind --leak-check=yes ./5.x

memtest6: $(TARGETS)
	valgrind --leak-check=yes ./6.x

memtest7: $(TARGETS)
	valgrind --leak-check=yes ./7.x

memtest8: $(TARGETS)
	valgrind --leak-check=yes ./8.x

clean:
	rm -rf $(TARGETS)
