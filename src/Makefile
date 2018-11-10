IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -g -Wall -pthread

ODIR = obj
LDIR = ../lib

LIBS = -lm -lgtest

DEPS =

TARGET = calculator.bin

# Add header files here
_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o calculator.o logger.o timer.o test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -f *.bin $(ODIR)/*.o *~ core $(INCDIR)/*~

.PHONY: force
force: clean all
