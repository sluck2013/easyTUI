GCC=g++
OPTM=-o2
STD=-std=c++11
LIB=-lncurses -pthread
HEADER_DIR=..
OBJECTS=$(wildcard ../*.o)

all: colorTest multipleWindows panelStyle

colorTest: colorTest.cpp colorTest.h $(OBJECTS)
	$(GCC) $(STD) -o $@ $^ -I $(HEADER_DIR) $(LIB)

multipleWindows: multipleWindows.cpp $(OBJECTS)
	$(GCC) $(STD) -o $@ $^ -I $(HEADER_DIR) $(LIB)

panelStyle: panelStyle.cpp $(OBJECTS)
	$(GCC) $(STD) -o $@ $^ -I $(HEADER_DIR) $(LIB)

clean:
	@find . -perm +100 -type f -delete
