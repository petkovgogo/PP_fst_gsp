#ifndef STATIC_MEMBERS_H
#define STATIC_MEMBERS_H

class StaticMembers
{
private:
    static double m_dNum;
    static long m_lNum;

public:
    static void printValues();
};

#endif // STATIC_MEMBERS_H