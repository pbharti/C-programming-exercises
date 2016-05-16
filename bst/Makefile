CC=gcc
CFLAGS=-I./inc
SRC=./src
OBJ=bst.o
EXE=bst
%.o: $(SRC)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	gcc -o $(EXE) $^ $(CFLAGS)

clean:
	rm -i *.o $(EXE)
