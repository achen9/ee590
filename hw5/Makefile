CXX = g++ -std=c++11 -Wall

SOURCES = object.cc number.cc string.cc array.cc hash.cc token.cc tokenizer.cc parser.cc
HEADERS = json.hh object.hh number.hh string.hh array.hh hash.hh token.hh tokenizer.hh parser.hh

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
