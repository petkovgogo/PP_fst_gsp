#include <iostream>
#include "../inc/MyString.h"

/**
 * PROBLEM:
 *      The problem of Mem.cpp and MemTest.cpp is described on page 343:
 * "notice that it’s not safe to hold the result of pointer() if the memory is resized"
 * That's because of the dynamic memory allocation - if we have a pointer   byte *bufPtr   which holds the same address
 * as m_mem (the return value of pointer()), upon resizing m_mem the address in the heap 
 * changes (storage is allocated with new) and the old one is cleaned (delete[] is called),
 * which leads to bufPtr pointing to a deleted memory
 * 
 * SOLUTION:
 *      The solution I came up with is to pass a reference to a pointer as the result of pointer().
 * The main idea is that the initial code will be unchanged (except the declaration), but because the returned value is a reference,
 * the pointer holding this result will always point to the same memory as m_mem
 * 
 * EXAMPLE:
 *      For the fixed example compile the program with flag and argument  -D FIXED_EXAMPLE 
**/

int main()
{
    MyString s("My test string");

    s.print(std::cout);
    s.concat(" some additional stuff");
    s.print(std::cout);

    MyString s2;

    s2.concat("Using default constructor");
    s2.print(std::cout);

    return 0;
}