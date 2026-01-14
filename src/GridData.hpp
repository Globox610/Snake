#ifndef Grid_hpp
#define Grid_hpp
#include "CellTypes.hpp"
#include "SFML/Graphics.hpp"

class GridData
{
private:
    const int gridColumns = 10; //Amount of cells in grid
    const int gridRows = 10; // Amount of cells in grid
    const float cellPitch = 80.f; // For calculations
    const sf::Vector2f origin = { 0.f, 0.f };


public:
    GridData();
    sf::Vector2f GridToWorld(sf::Vector2i cell) const;

    const int GetColumns() const;
    const int GetRows() const;
    const float GetCellPitch() const;
};
#endif // !Grid_hpp
