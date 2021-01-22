#ifndef DOG_H
#define DOG_H

class Dog
{
private:
    const char *m_sound;

public:
    Dog();

    void changeSound(const char *newSound);
    void sniff() const;
    void bark() const;

};

#endif // DOG_H