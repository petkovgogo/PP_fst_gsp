#include <iostream>

class GameBoard
{
public:
    GameBoard() { std::cout << "GameBoard()" << std::endl;; }

    GameBoard(const GameBoard &)
    {
        std::cout << "GameBoard(const GameBoard&)" << std::endl;;
    }

    GameBoard &operator=(const GameBoard &)
    {
        std::cout << "GameBoard::operator=()" << std::endl;;
        return *this;
    }

    ~GameBoard() { std::cout << "~GameBoard()" << std::endl; }
};

class Game
{
private:
    GameBoard gb; // Composition

public:
    // Default GameBoard constructor called:
    Game() { std::cout << "Game()" << std::endl;; }

    // You must explicitly call the GameBoard
    // copy-constructor or the default constructor
    // is automatically called instead:
    Game(const Game &g) : gb(g.gb)
    {
        std::cout << "Game(const Game&)" << std::endl;;
    }

    Game(int) { std::cout << "Game(int)" << std::endl;; }

    Game &operator=(const Game &g)
    {
        // You must explicitly call the GameBoard
        // assignment operator or no assignment at
        // all happens for gb!
        gb = g.gb;
        std::cout << "Game::operator=()" << std::endl;;

        return *this;
    }

    ~Game() { std::cout << "~Game()" << std::endl;; }
};

class Chess : public Game
{
public:
    // Default Game constructor called:
    Chess() { std::cout << "Chess()" << std::endl;; }
    Chess(const Chess &chess) : Game(chess) { std::cout << "Chess(const Chess &)" << std::endl;; }

    Chess &operator=(const Chess &chess)
    {
        Game::operator=(chess);
        std::cout << "Chess::operator=()" << std::endl;;

        return *this;
    }
};

int main()
{
    Chess d1;     // Default constructor - calls Game's default constructor, which calls GameBoard's default constructor
    Chess d2(d1); // Copy-constructor - cals Game's CC, which calls GameBoard's CC
    d1 = d2;      // All three operator=() are called

    return 0;
}