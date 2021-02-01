#ifndef HEN_H
#define HEN_H

class Hen
{
public:
    class Nest
    {
        friend class Hen;

    private:
        int m_eggCount;

    public:
        class Egg
        {
            friend class Nest;

        private:
            const char *m_colour;

        public:
            Egg(const char *colour);
        };

        Nest();

        void addEgg();
        void display(Egg &egg);
    };

    void display(Nest &nest);
};

#endif