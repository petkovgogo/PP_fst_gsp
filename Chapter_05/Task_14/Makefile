CPP := g++
INCLUDES := inc
SRC := src
BIN := bin

main.o: $(SRC)/main.cpp
	$(CPP) -c $^ -I$(INCLUDES)

stackOfInts.o: $(SRC)/stackOfInts.cpp
	$(CPP) -c $^ -I$(INCLUDES)

$(BIN)/program: main.o stackOfInts.o
	$(CPP) $^ -o $@

all: main.o stackOfInts.o $(BIN)/program