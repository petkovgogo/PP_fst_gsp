inline int sum(int a, int b)
{
    return a + b;
}

int main()
{
    const int NUM_1 = 42;
    const int NUM_2 = 451;

    // The function still gets called even when inline
    // Look at the comments inside both .s files for the differences
    sum(NUM_1, NUM_2);

    return 0;
}