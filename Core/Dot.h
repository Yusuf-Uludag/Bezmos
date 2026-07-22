#include <SFML/Graphics.hpp>
#include <iostream>

namespace Core
{
    enum class DotOrder
    {
        First,
        Middle,
        Last
    };

    struct Dot
    {
        sf::Vector2i position;
        bool isSelected;

        Dot(int x, int y)
            : position(x, y)
        {}

        int getX() { return position.x; }
        int getY() { return position.y; }
        sf::Vector2i getPosition() { return position; }
        void changePos(int x, int y)
        {
            sf::Vector2i newPos(x, y);
            position = newPos;
        }
        void Select() { isSelected = true; }
    };
} // namespace Core
