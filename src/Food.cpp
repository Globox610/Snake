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

void Food::RandomizeSpawn(const GridData& grid, SnakeBody& snake)
{
    sf::Vector2i candidate;
    bool collision;

    do
    {
        collision = false;

        candidate.x = std::rand() % grid.GetColumns();
        candidate.y = std::rand() % grid.GetRows();

        auto body = snake.GetBodyPositions(); 
        while (!body.empty())
        {
            if (body.front() == candidate)
            {
                collision = true;
                break;
            }
            body.pop_front();
        }

    } while (collision);

    foodCell = candidate;

}