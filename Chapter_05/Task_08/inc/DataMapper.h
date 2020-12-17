#ifndef DATA_MAPPER_H
#define DATA_MAPPER_H

class DataMapper
{
private:
    int m_privIntVar;
    double m_privDoubleVar;

protected:
    char m_protCharVar;
    bool m_protBoolVar;

public:
    float m_pubFloatVar;
    long m_pubLongVar;

    void showMap();
};

#endif // DATA_MAPPER_H