CXX = g++ -std=c++11

HEADERS = matrix.hh matrix.impl.hh

FRACTION_SOURCES = ../prob1/fraction.cc ../prob1/fraction_operations.cc
FRACTION_HEADERS = ../prob1/fraction.hh
COMPLEX_SOURCES = ../prob2/complex.cc ../prob2/complex_operations.cc
COMPLEX_HEADERS = ../prob2/complex.hh
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
	ar cr $(LIB_FRACTION) fraction.o fraction_operations.o

$(LIB_COMPLEX): $(COMPLEX_OBJECTS) $(COMPLEX_HEADERS)
	ar cr $(LIB_COMPLEX) complex.o complex_operations.o

$(LIB_DFT): $(DFT_OBJECTS) $(DFT_HEADERS)
	ar cr $(LIB_DFT) DFT.o

%.o: %.cc $(FRACTION_HEADERS)
	$(CXX) -c $<
%.o: %.cc $(COMPLEX_HEADERS)
	$(CXX) -c $<
%.o: %.cc $(DFT_HEADERS) 
	$(CXX) -c $<
%.o: %.cc $(HEADERS) 
	$(CXX) -c $<

clean:
	rm -f fraction.o fraction_operations.o complex.o complex_operations.o $(LIB_FRACTION) $(LIB_COMPLEX) $(DFT_OBJECTS) $(LIB_DFT)
	make -C test clean
