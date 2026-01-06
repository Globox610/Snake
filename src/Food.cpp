#include "Food.hpp"

Food::Food()
{
}

Food::~Food()
{
}



const sf::Vector2i& Food::GetFoodLocation() const
{
	return foodCell;
}

void Food::RandomizeSpawn(const GridData& grid)
{
	int x = std::rand() % grid.GetColumns();
	int y = std::rand() % grid.GetRows();
	foodCell = sf::Vector2i(x, y);

}
