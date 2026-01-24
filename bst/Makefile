#CC=gcc
CC=g++
CFLAGS=-I./inc -g
SRC=./src
OBJ=bst.o
EXE=bst
%.o: $(SRC)/%.c
	$(CC) -g -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -g -o $(EXE) $^ $(CFLAGS)

clean:
	rm -i *.o $(EXE)
