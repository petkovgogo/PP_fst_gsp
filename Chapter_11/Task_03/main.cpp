int main()
{
    // int &numRef; // error: ‘numRef’ declared as reference but not initialized
    
    int num1 = 42;
    int num2 = 451;
    int &ref = num1;

    // ref = &num2; // error: invalid conversion from ‘int*’ to ‘int’

    // int &nullRef = nullptr; // error: invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘std::nullptr_t’

    return 0;
}