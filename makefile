all: hw3

hw3: main.o mainStruct.o mainTerm.o mainAtom.o mainNumber.o mainVariable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 main.o mainStruct.o mainTerm.o mainAtom.o mainNumber.o mainVariable.o -lgtest
else
	g++ -o hw3 main.o mainStruct.o mainTerm.o mainAtom.o mainNumber.o mainVariable.o -lgtest -lpthread
endif


main.o: main.cpp utVariable.h utStruct.h
	g++ -std=gnu++0x -c main.cpp
mainStruct.o: mainStruct.cpp struct.h
	g++ -std=gnu++0x -c mainStruct.cpp
mainTerm.o: mainTerm.cpp term.h
	g++ -std=gnu++0x -c mainTerm.cpp
mainVariable.o: mainVariable.cpp variable.h
	g++ -std=gnu++0x -c mainVariable.cpp 
mainNumber.o: mainNumber.cpp number.h
	g++ -std=gnu++0x -c mainNumber.cpp 
mainAtom.o: mainAtom.cpp atom.h
	g++ -std=gnu++0x -c mainAtom.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw3
endif