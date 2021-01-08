#ifndef STRING_HOLDER_H
#define STRING_HOLDER_H

#define FIELD(a)                         \
    const char *a##_string;              \
    int a##_size;                        \
    int a##_index;                       \
                                         \
public:                                  \
    const char *get_##a##_string() const \
    {                                    \
        return a##_string;               \
    }                                    \
                                         \
private:

// end of FIELD(a)

class StringHolder
{
    FIELD(first);
    FIELD(second);
    FIELD(third);

    void init(
        const char *m_str,
        int &m_size,
        int &m_index,
        int &index
    );

public:
    StringHolder();
};

#undef FIELD

#endif // STRING_HOLDER_H