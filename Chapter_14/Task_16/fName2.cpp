#include <iostream>
#include <fstream>
#include <string>

class FName2 : public std::ifstream
{
private:
    std::string m_fileName;
    bool isNamed;

public:
    FName2() : isNamed(false) {}
    FName2(const std::string &fname)
        : std::ifstream(fname.c_str()), m_fileName(fname), isNamed(true) {}

    std::string name() const { return m_fileName; }

    void name(const std::string &newName)
    {
        if (isNamed)
        {
            return; // Don't overwrite
        }

        m_fileName = newName;
        isNamed = true;
    }
};

int main()
{
    FName2 file("fName2.cpp");

    std::cout << "name: " << file.name() << std::endl;
    std::string s;

    if (file.is_open()) // works fine
    {
        while (getline(file, s))
        {
            std::cout << s << '\n';
        }
    }

    file.clear();                        // clears the state of the file
    file.seekg(0, std::ios::beg);        // jumps to the beginning of the file
    std::streampos begin = file.tellg(); // returns the current position in the file

    file.seekg(0, std::ios::end); // jumps to the end of the file
    std::streampos end = file.tellg();

    std::cout << "\nsize is: " << (end - begin) << " bytes." << std::endl;

    file.close();

    return 0;
}