#ifndef GridBuilder_hpp
#define GridBuilder_hpp


#include <SFML/Graphics.hpp>

struct GridBuildingBlock
{
    sf::RectangleShape cellOutline;

    GridBuildingBlock(float cellSize)
    {
        cellOutline.setSize({ cellSize - 2.f, cellSize - 2.f });
        cellOutline.setFillColor(sf::Color::Transparent);
        cellOutline.setOutlineThickness(2.f);
        cellOutline.setOutlineColor(sf::Color::White);
    }
};


#endif // !GRIDBUILDER.HPP
