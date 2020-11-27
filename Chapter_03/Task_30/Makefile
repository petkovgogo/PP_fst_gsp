CPP := g++
EXECUTABLE := program

run: all
	clear
	./${EXECUTABLE}

.SUFFIXES: . .cpp
.cpp.:
	$(CPP) $< -o ${EXECUTABLE}
all: ./*.