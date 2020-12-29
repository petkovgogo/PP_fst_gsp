#include <stdio.h>

const int NUM_1 = 7;
const int NUM_2 = 5;

int main() // I don't get any warnings or differences in the output when compiling under both C and C++ (Why?)
{
    printf("Sum: %d\n", NUM_1 + NUM_2);

    return 0;
}