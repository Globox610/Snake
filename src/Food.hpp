#ifndef Food_hpp
#define Food_hpp
#include "GameObject.hpp"
#include "GridData.hpp"
#include "CellTypes.hpp"
class Food
{
public:
	Food();
	~Food();
	const sf::Vector2i& GetFoodLocation() const;
	void randomizeSpawn(const GridData& grid);
private:
	sf::Vector2i foodCell;

};
#endif // !Food_hpp
