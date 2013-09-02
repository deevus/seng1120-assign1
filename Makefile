CC = g++
CFLAGS = -c -Wall

all: LandingDemo

LandingDemo: LandingList.o
	$(CC) -o LandingDemo Flight.o Node.o LinkedList.o LandingList.o LandingDemo.cpp 

LandingList.o: LandingList.cpp Flight.o datastruct
	$(CC) $(CFLAGS) LandingList.cpp

Flight.o: Flight.cpp
	$(CC) $(CFLAGS) Flight.cpp

clean: 
	rm -rf *.o LandingDemo *.gch

datastruct: LinkedList.o

Node.o: datastructures/Node.cpp Flight.o
	$(CC) $(CFLAGS) datastructures/Node.cpp 

LinkedList.o: datastructures/LinkedList.cpp Node.o 
	$(CC) $(CFLAGS) datastructures/LinkedList.cpp

run: LandingDemo
	./LandingDemo
