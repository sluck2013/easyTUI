GCC=g++
OPTM=-o2
STD=-std=c++11
LIB=-lncurses -pthread

all: Window.o Factory.o Panel.o Style.o ColorManager.o

Window.o: Window.h Window.cpp Window.h Factory.h
	$(GCC) $(STD) -c -o Window.o Window.cpp $(LIB) 

Factory.o: Factory.cpp Factory.h
	$(GCC) $(STD) -c -o Factory.o Factory.cpp $(LIB)

Panel.o: Panel.h Panel.cpp
	$(GCC) $(STD) -c -o Panel.o Panel.cpp $(LIB)

Style.o: Style.h Style.cpp
	$(GCC) $(STD) -c -o Style.o Style.cpp $(LIB)

ColorManager.o: ColorManager.h ColorManager.cpp
	$(GCC) $(STD) -c -o ColorManager.o ColorManager.cpp $(LIB)

clean:
	@rm *.o test
