CC = g++
CFLAGS = -c -Wall
ZIP = zip

all: CC += -DNDEBUG 
all: LandingDemo

debug: CC += -DDEBUG -g
debug: LandingDemo

LandingDemo: LandingList.o
	$(CC) -o LandingDemo Flight.o Node.o LinkedList.o LandingList.o LandingDemo.cpp 

LandingList.o: LandingList.cpp Flight.o datastruct
	$(CC) $(CFLAGS) LandingList.cpp

Flight.o: Flight.cpp
	$(CC) $(CFLAGS) Flight.cpp

clean: 
	rm -rf *.o LandingDemo *.gch *.zip

datastruct: LinkedList.o

Node.o: datastructures/Node.cpp Flight.o
	$(CC) $(CFLAGS) datastructures/Node.cpp 

LinkedList.o: datastructures/LinkedList.cpp Node.o 
	$(CC) $(CFLAGS) datastructures/LinkedList.cpp

run: LandingDemo
	./LandingDemo

package: LandingDemo.cpp LandingList.h LandingList.cpp Flight.h Flight.cpp datastructures/Node.h datastructures/Node.cpp datastructures/LinkedList.h datastructures/LinkedList.cpp README.md
	$(ZIP) seng1120_assign1.zip *.h *.cpp datastructures/*.h datastructures/*.cpp README.md Makefile
