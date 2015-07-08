GCC=g++
OPTM=-o2
STD=-std=c++11
LIB=-lncurses -pthread
HEADER_DIR=..
OBJECTS=$(wildcard ../*.o)

all: colorTest

colorTest: colorTest.cpp colorTest.h $(OBJECTS)
	$(GCC) $(STD) -o $@ $^ -I $(HEADER_DIR) $(LIB)

clean:
	@find . -perm +100 -type f -delete
