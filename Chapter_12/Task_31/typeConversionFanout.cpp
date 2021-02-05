class Orange {};

class Pear {};

class Apple {
public:
    operator Orange() const;
    explicit operator Pear() const;
};

// Overloaded eat():
void eat(Orange);

void eat(Pear);

int main()
{
    Apple c;

    eat(c);         // Apple -> Orange
    eat(Pear(c));   // Apple -> Pear
    
    return 0;
}