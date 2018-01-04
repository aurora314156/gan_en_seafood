all: hw8 shell

hw8: mainExp.o list.o atom.o struct.o  scanner.h  number.h parser.h exp.h
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainExp.o list.o atom.o struct.o  -lgtest
else
	g++ -o hw8 mainExp.o list.o atom.o struct.o -lgtest -lpthread
endif

shell: shell.o atom.o struct.o list.o parser.h scanner.h exp.h atom.h variable.h iterator.h
ifeq (${OS}, Windows_NT)
	g++ -o shell shell.o struct.o list.o atom.o -lgtest
else
	g++ -o shell shell.o struct.o list.o atom.o -lgtest -lpthread
endif

shell.o:  shell.cpp atom.h variable.h struct.h iterator.h  global.h \
		  list.h scanner.h parser.h \
		  struct.o list.o atom.o
	g++ -std=gnu++0x -c shell.cpp

mainExp.o: mainExp.cpp atom.h  variable.h struct.h iterator.h exception.h  node.h\
		   list.h scanner.h parser.h global.h expression.h  number.h\
		   struct.o list.o atom.o
	g++ -std=gnu++0x -c mainExp.cpp

atom.o: atom.cpp atom.h variable.h 
	g++ -std=gnu++0x -c atom.cpp
	
struct.o:struct.cpp struct.h atom.o number.h
		 g++ -std=gnu++0x -c struct.cpp

list.o: list.cpp list.h number.h atom.o
		g++ -std=gnu++0x -c list.cpp


clean:
	rm -f *.o hw8 shell
stat:
	wc *.h *.cpp
hw:
	make clean
	make hw8
	./hw8
sh:
	make clean
	make shell
	./shell