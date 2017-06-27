CC=gcc
CFLAGS=-I./inc -g
SRC=./src
OBJ=bst.o
EXE=bst
%.o: $(SRC)/%.c
	$(CC) -g -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	gcc -g -o $(EXE) $^ $(CFLAGS)

clean:
	rm -i *.o $(EXE)
