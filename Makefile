IDIR=.
PROJECT=EvolutionSimulation
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
BIN=bin

DEPS=RandomSelectEvolution.h
_OBJ=main.o RandomSelectEvolution.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(PROJECT): $(OBJS) | $(BIN)
	$(CC) -o $(BIN)/$@ $^ $(FLAGS)

$(ODIR)/%.o: %.c $(DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR): 
	mkdir $(ODIR)
$(BIN):
	mkdir $(BIN)

.PHONY: clean

clean:
	rm -Rf $(ODIR) $(BIN)