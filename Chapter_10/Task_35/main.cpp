extern "C" int puts(const char *str);

int main()
{
    const char *message = "Lorem ipsum dolor sit amet.";

    puts(message);

    return 0;
}