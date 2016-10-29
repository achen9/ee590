CXX = g++ -std=c++11 -O0 -Wall

SOURCES = object.cc number.cc array.cc hash.cc string.cc
HEADERS = json.hh object.hh number.hh array.hh hash.hh string.hh

OBJECTS=$(SOURCES:.cc=.o)

LIB_JSON=libjson.a

all: $(LIB_JSON)
	make -C test

$(LIB_JSON): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_JSON) $(OBJECTS)

%.o: %.cc $(HEADERS)
	$(CXX) -c $< -g

clean:
	rm -f $(OBJECTS) $(LIB_JSON)
	make -C test clean
