class Simple {};
class PrivHeir : private Simple {};
class ProtHeir : protected Simple {};

void func(Simple &) {}

int main()
{
    PrivHeir privHeirObj;
    ProtHeir protHeirObj;

    // func(privHeirObj); // error: ‘Simple’ is an inaccessible base of ‘PrivHeir’
    // func(protHeirObj); // error: ‘Simple’ is an inaccessible base of ‘ProtHeir’

    return 0;
}