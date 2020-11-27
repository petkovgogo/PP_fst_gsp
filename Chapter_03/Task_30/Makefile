CPP := g++
EXECUTABLE := program

run: ./${EXECUTABLE}
	clear
	./${EXECUTABLE}

./${EXECUTABLE}: ./*.cpp
	${CPP} $^ -o $@