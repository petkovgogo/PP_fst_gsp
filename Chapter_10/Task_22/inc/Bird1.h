#ifndef BIRD_1_H
#define BIRD_1_H

#include <iostream>

namespace bird1
{
    class Bird
    {
    private:
        const char *m_species;

    public:
        Bird(const char *species);

        const char *getSpecies() const;
        void makeNest() const;
    };

    inline Bird::Bird(const char *species) : m_species(species) {}

    inline const char *Bird::getSpecies() const { return m_species; }

    inline void Bird::makeNest() const
    {
        std::cout << "Making a nest..." << std::endl;
    }
} // namespace bird1

#endif // BIRD_1_H