CPP := g++
INCLUDES := inc
SRC := src
BIN := bin

main.o: $(SRC)/main.cpp
	$(CPP) -c $^ -I$(INCLUDES)

handle.o: $(SRC)/handle.cpp
	$(CPP) -c $^ -I$(INCLUDES)

$(BIN)/program: main.o handle.o
	$(CPP) $^ -o $@

all: main.o handle.o $(BIN)/program