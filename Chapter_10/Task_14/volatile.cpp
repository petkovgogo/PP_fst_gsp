class Comm
{
    static const unsigned char byte;
    static unsigned char flag;
    enum
    {
        bufsize = 100
    };

    static unsigned char buf[bufsize];
    static int index;

public:
    static void isr(); // volatile; not allowed with static
    char read(int index) const;
};

const unsigned char Comm::byte = 0;
unsigned char Comm::flag = 0;
unsigned char Comm::buf[bufsize] {0};
int Comm::index = 0;

void Comm::isr()
{
    flag = 0;
    buf[index++] = byte;
    // Wrap to beginning of buffer:
    if (index >= bufsize)
    {
        index = 0;
    }
}

char Comm::read(int index) const
{
    if (index < 0 || index >= bufsize)
    {
        return 0;
    }

    return buf[index];
}

int main()
{
    volatile Comm Port;
    Comm::isr(); // OK
    //! Port.read(0); // Error, read() not volatile
}