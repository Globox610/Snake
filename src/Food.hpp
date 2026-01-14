#ifndef Food_hpp
#define Food_hpp
#include "GridData.hpp"
#include "SnakeBody.hpp"


class Food
{
public:
	Food();
	~Food();
	const sf::Vector2i& GetFoodLocation() const;
	void RandomizeSpawn(const GridData& grid, SnakeBody& snake);
private:
	sf::Vector2i foodCell;

};
#endif // !Food_hpp
