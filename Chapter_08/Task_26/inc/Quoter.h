#ifndef QUOTER_H
#define QUOTER_H

class Quoter
{
    mutable int lastquote;

public:
    Quoter();

    int lastQuote() const;
    const char *quote() const;
};

#endif // QUOTER_H