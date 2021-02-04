class Simple
{
public:
#ifdef SHOW_ERROR

    // error: ‘Simple& Simple::operator=(Simple&, const char*)’ must have exactly one argument
    Simple &operator=(Simple &rvalue, const char *message = "op= call")
    {
        if (this != &rvalue) { /* self assignment */ }

        return *this;
    }

#endif // SHOW_ERROR
};

int main() { return 0; }