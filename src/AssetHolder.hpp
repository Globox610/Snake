#ifndef AssetHolder_hpp
#define AssetHolder_hpp


#include <SFML/Graphics.hpp>

struct AssetHolder
{
    sf::RectangleShape food;
    sf::RectangleShape snakeBody;
    sf::RectangleShape snakeHead;

    AssetHolder(float cellSize)
    {
        food.setSize({ cellSize - 40.f, cellSize - 40.f});
        food.setFillColor(sf::Color::Blue);

        snakeBody.setSize({ cellSize, cellSize});
        snakeBody.setFillColor(sf::Color::Green);
        snakeBody.setOutlineColor(sf::Color::White);
        snakeBody.setOutlineThickness(2.f);

        snakeHead = snakeBody;
        snakeHead.setFillColor(sf::Color::Red);
    }
};
#endif // !AssetHolder_hpp