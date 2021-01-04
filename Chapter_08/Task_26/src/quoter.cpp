#include <cstdlib>
#include <ctime>
#include "../inc/Quoter.h"

Quoter::Quoter()
{
    lastquote = -1;
    srand(time(0));
}

int Quoter::lastQuote() const
{
    return lastquote;
}
const char *Quoter::quote() const
{
    static const char *quotes[] = {
        "Are we having fun yet?",
        "Doctors always know best",
        "Is it ... Atomic?",
        "Fear is obscene",
        "There is no scientific evidence "
        "to support the idea "
        "that life is serious",
        "Things that make us happy, make us wise",
    };

    const int qsize = sizeof quotes / sizeof *quotes;

    int qnum = rand() % qsize;

    while (lastquote >= 0 && qnum == lastquote)
    {
        qnum = rand() % qsize;
    }

    return quotes[lastquote = qnum];
}