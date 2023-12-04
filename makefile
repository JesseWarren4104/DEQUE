CC = g++
CFLAGS = -g -Wall

default: test

test: deque.o main.o
	$(CC) $(CFlags) -o test deque.o main.o

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) test *.o *~
