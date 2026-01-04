#ifndef SnakeBody_hpp
#define SnakeBody_hpp
#include <SFML/Graphics.hpp>
#include <deque>
#include "Direction.hpp"
#include "GridData.hpp"
#include "Food.hpp"

class SnakeBody
{
public:
	SnakeBody();
	~SnakeBody();
	void Update();

	//Getters n Setters
	std::deque<sf::Vector2i>& GetBodyPositions();
	sf::RectangleShape GetBodySprite();
	sf::RectangleShape GetHeadSprite();
	void SetDirection(Direction direction);
	bool GetGrowOnNextUpdate();
	void SetGrowOnNextUpdate(bool grow);
	bool CheckIfDead(GridData& grid);
	void ResetSnake();
private:
	sf::RectangleShape bodyRect;
	std::deque<sf::Vector2i> bodyPositions;
	Direction direction;
	bool growOnNextUpdate = false;
	void MoveBy(sf::Vector2i& position);
	bool CheckOpposite(Direction direction);



};


#endif // !SnakeBody_hpp
