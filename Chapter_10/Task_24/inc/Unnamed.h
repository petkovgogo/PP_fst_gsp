#ifndef UNNAMED_H
#define UNNAMED_H

namespace anonymous
{
    class Arm { /* ... */ };
    class Leg { /* ... */ };
    class Head { /* ... */ };

    class Robot
    {
    public:
        Arm arm[4];
        Leg leg[16];
        Head head[3];
        // ...
    } xanthan;

    int i, j, k;
} // namespace anonymous

#endif // UNNAMED_H