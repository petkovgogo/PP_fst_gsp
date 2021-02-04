class Orange {};

class Apple
{
public:
    Apple() {}
    Apple(const Orange &) {}

    friend const Apple operator*(const Apple &, const Apple &);
};

const Apple operator*(const Apple &, const Apple &) { return Apple(); }

int main()
{
    Apple() * Apple();   // OK
    Orange() * Apple();  // OK
    Apple() * Orange();  // OK
    Orange() * Orange(); // OK

    return 0;
}