#ifndef MenuState_hpp
#define MenuState_hpp
#include "MenuItems.hpp"
#include "GameState.hpp"
#include "PlayState.hpp"
#include <SFML/Graphics.hpp>


class MenuState : public GameState
{
private:
	bool toggleState = false;
public:
	MenuState(sf::RenderWindow& window);
	~MenuState() = default;
	void Update() override;
	bool Toggle() override;
	void KeyboardEvent(sf::Keyboard::Scancode scanCode) override;
	void MouseEvent(sf::Mouse::Button click) override;
	void Render(sf::RenderWindow& window) override;
};





#endif // !MenuState_hpp
