GCC=g++
OPTM=-o2
STD=-std=c++11
LIB=-lncurses

all: test

test: drive.cpp drive.h Window.o WindowFactory.o Panel.o
	$(GCC) $(STD) -o test drive.cpp Window.o WindowFactory.o Panel.o $(LIB)

Window.o: Window.h Window.cpp Window.h WindowFactory.h
	$(GCC) $(STD) -c -o Window.o Window.cpp $(LIB) 

WindowFactory.o: WindowFactory.cpp WindowFactory.h
	$(GCC) $(STD) -c -o WindowFactory.o WindowFactory.cpp $(LIB)

Panel.o: Panel.h Panel.cpp
	$(GCC) $(STD) -c -o Panel.o Panel.cpp $(LIB)

clean:
	@rm *.o test
