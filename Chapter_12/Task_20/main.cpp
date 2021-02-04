class Simple {};

// error: ‘Simple& operator=(Simple&, Simple&)’ must be a nonstatic member function

#ifdef NON_MEMBER

Simple &operator=(Simple &lvalue, Simple &rvalue)
{
    if (&lvalue != &rvalue) { /* code */ }

    return lvalue;
}

#endif // NON_MEMBER

int main() { return 0; }