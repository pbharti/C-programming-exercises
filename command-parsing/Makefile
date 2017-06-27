#
# Make file to generate parser App.
#

INCPATH = ./inc
SRCPATH = ./src
CFLAGS = -g -Wall -I$(INCPATH)
CC = gcc
all: parser

parser: parser_main.o
	$(CC) $(CFLAGS) -o parser parser_main.o

parser_main.o:
	$(CC) $(CFLAGS) -c $(SRCPATH)/parser_main.c

clean:
	rm -rf *.o parser

