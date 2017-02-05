SRCDIR = ./src
BUILDDIR = build
OBJDIR = ./build/obj
BIN = ./build/bin
INC = ./inc
_DEPS = list_common.h
CFLAGS = -I $(INC)
CC = gcc
LDLIB = -lm
DEPS = $(patsubst %,$(INC)/%,$(_DEPS))

_OBJ = sll_main.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

all: $(BIN)/sll

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	mkdir -p $(BUILDDIR)
	mkdir -p $(OBJDIR)
	mkdir -p $(BIN)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN)/sll: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIB)
.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(BUILDDIR)
