all: hw4

hw4: main.o atom.o  
ifeq (${OS}, Windows_NT)
	g++ -o hw4 main.o atom.o -lgtest
else
	g++ -o hw4 main.o atom.o -lgtest -lpthread
endif

main.o: main.cpp utList.h 
	g++ -std=gnu++0x -c  main.cpp

atom.o: atom.h atom.cpp variable.h struct.h list.h 
	g++ -std=gnu++0x -c  atom.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw4
endif