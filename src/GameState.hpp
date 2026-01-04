#ifndef GameState_hpp
#define GameState_hpp
#include <SFML/Graphics.hpp>


class GameState
{
public:
	GameState() = default;
	~GameState() = default;
	virtual void Update() = 0;
	virtual bool Toggle() = 0;
	virtual void Render(sf::RenderWindow& window) = 0;
	virtual void KeyboardEvent(sf::Keyboard::Scancode scanCode) = 0;
	virtual void MouseEvent(sf::Mouse::Button click) = 0;
};
#endif // !GameState.hpp