void t(int &) {}

void u(const int &cip)
{
    int i = cip; // OK -- copies value
}

/*
const char &v()
{
    // Returns address of static character array:

    // return "result of function v()"; // cannot return reference to temporary object

    // static const char &result = "result of function v()"; // cannot assign reference to temporary object
    // return result;
}
*/

const int &w() // const int &const w() => error: ‘const’ qualifiers cannot be applied to ‘const int&’
{
    static int i;
    return i;
}

int main()
{
    int x = 0;
    int &ip = x;
    const int &cip = x;

    t(ip);
    u(ip);
    u(cip);

    // const char &ccp = v(); // error
    const int &ccip = w();
    const int cip2 = w();

    return 0;
}