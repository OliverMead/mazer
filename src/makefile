IDIR = ../include
CC=gcc
CFLAGS=-I$(IDIR) -Wno-implicit-function-declaration

ODIR=obj
LDIR =../lib

LIBS=-lbsd -lm

_DEPS = mazer.h test.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = mazer.o nodes.o test.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

mazer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
