IDIR=../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm

DEPS =

OBJ = main.o

# Add header files here
_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

calculator.bin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.bin $(ODIR)/*.o *~ core $(INCDIR)/*~
