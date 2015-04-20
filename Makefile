GCC=g++
SPEC=-std=c++11
OPTM=-o2
LIB=-lncurses

all: test

test: drive.cpp drive.h Window.o
	$(GCC) $(OPTM) $(SPEC) -o test drive.cpp Window.o

Window.o: Window.h Window.cpp WindowInterface.h
	$(GCC) $(OPTM) $(SPEC) -c -o Window.o Window.cpp $(LIB)

clean:
	@rm *.o test
