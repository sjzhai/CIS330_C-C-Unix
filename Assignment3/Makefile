SOURCES = reversi.c
HEADERS = reversi.h 
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

tests: test-reversi

test-reversi: test-reversi.o reversi.o
	$(CC) -o $@ test-reversi.o reversi.o $(LIBS)

test-test: test.o reversi.o 
	$(CC) -o $@ test.o reversi.o  $(LIBS)

clean: 
	$(RM) main $(OBJECTS) test-*