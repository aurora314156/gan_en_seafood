all: hw4

hw4: main.o atom.o mainVariable.o mainStruct.o mainList.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 main.o atom.o mainVariable.o mainStruct.o mainList.o -lgtest
else
	g++ -o hw4 main.o atom.o mainVariable.o mainStruct.o mainList.o -lgtest -lpthread
endif

main.o: main.cpp utList.h
	g++ -std=gnu++0x -c  main.cpp

atom.o: atom.h atom.cpp
	g++ -std=gnu++0x -c  atom.cpp

mainVariable.o: mainVariable.cpp variable.h 
	g++ -std=gnu++0x -c  mainVariable.cpp

mainStruct.o: mainStruct.cpp struct.h  
	g++ -std=gnu++0x -c  mainStruct.cpp

mainList.o: mainList.cpp list.h 
	g++ -std=gnu++0x -c  mainList.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw4
endif