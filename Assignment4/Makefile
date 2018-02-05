SOURCES = main.cpp reversi.cpp
HEADERS = reversi.h 
OBJECTS = $(SOURCES:.cpp=.o)
LIBS = -lm

CC = g++
CFLAGS = -std=c++11 -g

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

tests: test-reversi

test-reversi: test-reversi.o reversi.o
	$(CC) -o $@ test-reversi.o reversi.o $(LIBS)

test-main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

test-test: test.o reversi.o 
	$(CC) -o $@ test.o reversi.o  $(LIBS)

clean: 
	$(RM) main $(OBJECTS) test-*