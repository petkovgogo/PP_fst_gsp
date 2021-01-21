#ifndef MIRROR_H
#define MIRROR_H

class Mirror
{
private:
    Mirror *m_mirror;
    bool m_state;

public:
    Mirror();
    Mirror(Mirror &mirror);

    bool test() const;
};

#endif // MIRROR_H