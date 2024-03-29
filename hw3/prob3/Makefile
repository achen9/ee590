CXX = g++ -std=c++11

HEADERS = matrix.hh matrix.impl.hh

FRACTION_SOURCES = fraction.cc fraction_operations.cc
FRACTION_HEADERS = fraction.hh
COMPLEX_SOURCES = complex.cc complex_operations.cc
COMPLEX_HEADERS = complex.hh
DFT_SOURCES = DFT.cc
DFT_HEADERS = DFT.hh

FRACTION_OBJECTS=$(FRACTION_SOURCES:.cc=.o)
COMPLEX_OBJECTS=$(COMPLEX_SOURCES:.cc=.o)
DFT_OBJECTS=$(DFT_SOURCES:.cc=.o)

LIB_FRACTION=libfraction.a
LIB_COMPLEX=libcomplex.a
LIB_DFT=libDFT.a

all: $(HEADERS) $(LIB_FRACTION) $(LIB_COMPLEX) $(LIB_DFT)
	make -C test

P3: $(HEADERS) $(LIB_FRACTION) $(LIB_COMPLEX) $(LIB_DFT)
	make P3 -C test

P4: $(HEADERS) $(LIB_FRACTION) $(LIB_COMPLEX) $(LIB_DFT)
	make P4 -C test

$(LIB_FRACTION): $(FRACTION_OBJECTS) $(FRACTION_HEADERS)
	ar cr $(LIB_FRACTION) $(FRACTION_OBJECTS)

$(LIB_COMPLEX): $(COMPLEX_OBJECTS) $(COMPLEX_HEADERS)
	ar cr $(LIB_COMPLEX) $(COMPLEX_OBJECTS)

$(LIB_DFT): $(DFT_OBJECTS) $(COMPLEX_OBJECTS) $(DFT_HEADERS)
	ar cr $(LIB_DFT) $(DFT_OBJECTS) $(COMPLEX_OBJECTS)

%.o: %.cc $(HEADERS) $(FRACTION_HEADERS) $(COMPLEX_HEADERS) $(DFT_HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(FRACTION_OBJECTS) $(LIB_FRACTION) $(COMPLEX_OBJECTS) $(LIB_COMPLEX) $(DFT_OBJECTS) $(LIB_DFT)
	make -C test clean
