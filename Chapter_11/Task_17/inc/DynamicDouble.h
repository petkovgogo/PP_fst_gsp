#ifndef DYNAMIC_DOUBLE_H
#define DYNAMIC_DOUBLE_H

class DynamicDouble
{
private:
    double *m_num;

public:
    DynamicDouble(double num);

#ifdef FIXED

    DynamicDouble(DynamicDouble &original);

#endif // FIXED

    ~DynamicDouble();

    void print() const;
};

#endif // DYNAMIC_DOUBLE_H