#define EXPLICIT_CONSTRUCTOR
// #define NOT_CALLED_EXPLICITLY

class Orange {};

class Apple
{
public:
#ifdef EXPLICIT_CONSTRUCTOR

    explicit Apple(const Orange &) {}

#else

    Apple(const Orange &) {}

#endif // EXPLICIT_CONSTRUCTOR
};

void spy(Apple) {}

int main()
{
#ifdef EXPLICIT_CONSTRUCTOR
#ifdef NOT_CALLED_EXPLICITLY

    spy(Orange());          // error: could not convert ‘Orange()’ from ‘Orange’ to ‘Apple’

#else

    spy(Apple(Orange()));   // OK

#endif // NOT_CALLED_EXPLICITLY
#else

    spy(Orange());          // OK

#endif // EXPLICIT_CONSTRUCTOR

    return 0;
}