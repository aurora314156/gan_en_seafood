all: hw7

hw7: main.o utIterator.h atom.o list.o struct.o iterator.h 
ifeq (${OS}, Windows_NT)
	 g++ -o hw7  main.o atom.o list.o struct.o -lgtest
else
	 g++ -o hw7  main.o atom.o list.o struct.o -lgtest -lpthread
endif

main.o: main.cpp utIterator.h iterator.h
	g++ -std=gnu++0x -c main.cpp

atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp
list.o:list.cpp list.h
		g++ -std=c++11 -c list.cpp
struct.o:struct.cpp struct.h
		g++ -std=c++11 -c struct.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw7 
endif

