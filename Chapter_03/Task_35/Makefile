CPP := g++
EXECUTABLE := program
SRC := ../Task_31

run: ${SRC}/*.cpp
	${CPP} $^ -o ${EXECUTABLE}
	./${EXECUTABLE}

debug: ${SRC}/*.cpp
	${CPP} -D DEBUG $^ -o ${EXECUTABLE}
	./${EXECUTABLE}