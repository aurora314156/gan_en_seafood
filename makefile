all: hw5

hw5: main.o atom.o variable.o struct.o parser.o scanner.o global.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 main.o atom.o variable.o struct.o parser.o  scanner.o global.o list.o-lgtest
else
	g++ -o hw5 main.o atom.o variable.o struct.o parser.o  scanner.o global.o list.o -lgtest -lpthread
endif


main.o : main.cpp utParser.h
	g++ -std=gnu++0x -c  main.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++0x -c  atom.cpp
variable.o: variable.cpp variable.h
	g++ -std=gnu++0x -c  variable.cpp
struct.o: struct.cpp struct.h
	g++ -std=gnu++0x -c  struct.cpp
parser.o: parser.cpp parser.h global.h
	g++ -std=gnu++0x -c  parser.cpp
scanner.o: scanner.cpp scanner.h global.h
	g++ -std=gnu++0x -c  scanner.cpp
global.o: global.cpp global.h
	g++ -std=gnu++0x -c  global.cpp
list.o:list.cpp list.h
	g++ -std=gnu++0x -c  list.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw5
endif