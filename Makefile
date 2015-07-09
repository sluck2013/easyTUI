GCC=g++
OPTM=-o2
STD=-std=c++11
LIB=-lncurses -pthread

all: Window.o WindowFactory.o Panel.o Style.o ColorManager.o Label.o

Window.o: Window.h Window.cpp Window.h Factory.h Label.h
	$(GCC) $(STD) -c -o $@ Window.cpp $(LIB) 

WindowFactory.o: WindowFactory.cpp WindowFactory.h Factory.h
	$(GCC) $(STD) -c -o $@ WindowFactory.cpp $(LIB)

Panel.o: Panel.h Panel.cpp
	$(GCC) $(STD) -c -o $@ Panel.cpp $(LIB)

Style.o: Style.h Style.cpp
	$(GCC) $(STD) -c -o $@ Style.cpp $(LIB)

ColorManager.o: ColorManager.h ColorManager.cpp
	$(GCC) $(STD) -c -o $@ ColorManager.cpp $(LIB)

Label.o: Label.h Label.cpp TextComponent.h Window.h
	$(GCC) $(STD) -c -o $@ Label.cpp $(LIB)

clean:
	@rm *.o
