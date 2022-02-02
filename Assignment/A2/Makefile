CC = g++
CFLAGS = -std=c++11 -Wall
LIBHARU = ./libharu
LIBNAME = hpdfs
INPUT =  "The quick brown fox jumps over the lazy dog. We need more text to test a spiral. Maybe the radians needs to increase with smaller radius."
OUTPUTNAME = spiralPDF

$(OUTPUTNAME): HaruPDF.o Spiral.o spiralPDF.o
	$(CC) $(CFLAGS) HaruPDF.o Spiral.o spiralPDF.o -o spiralPDF -I$(LIBHARU)/include -L$(LIBHARU)/src/ -l$(LIBNAME)

spiralPDF.o: spiralPDF.cpp Spiral.o HaruPDF.o
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c spiralPDF.cpp -L$(LIBHARU)/src/ -l$(LIBNAME)

Spiral.o: Spiral.cpp Spiral.h
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c Spiral.cpp -L$(LIBHARU)/src/ -l$(LIBNAME)

HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c HaruPDF.cpp -L$(LIBHARU)/src/ -l$(LIBNAME)

test:
	./$(OUTPUTNAME) $(INPUT)

clean:
	rm -f spiralPDF *.o
rebuild:
	make clean 
	make $(OUTPUTNAME) 
	make test


