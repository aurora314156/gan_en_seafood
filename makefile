all: hw2


hw2: mainTerm.o mainNumber.o mainVariable.o mainAtom.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainTerm.o mainNumber.o mainVariable.o mainAtom.o -lgtest
else
	g++ -o hw2 mainTerm.o mainNumber.o mainVariable.o mainAtom.o -lgtest -lpthread
endif

mainTerm.o: mainTerm.cpp utTerm.h 
	g++ -std=c++11 -c mainTerm.cpp
mainNumber.o: mainNumber.cpp atom.h number.h variable.h
	g++ -std=c++11 -c mainNumber.cpp
mainVariable.o: mainVariable.cpp atom.h number.h variable.h
	g++ -std=c++11 -c mainVariable.cpp 
mainAtom.o: mainAtom.cpp atom.h number.h variable.h
	g++ -std=c++11 -c mainAtom.cpp 
	
clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif