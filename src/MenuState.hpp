#pragma once
#include "MenuItems.hpp"
#include "GameState.hpp"
#include "PlayState.hpp"
#include <SFML/Graphics.hpp>


class MenuState : public GameState
{
private:
	bool toggleState = false;
	std::vector<std::unique_ptr<MenuItem>> menuItems;
	sf::Font font;
	bool showingHighscores;
	sf::Vector2f highscoresOriginalButtonPosition{ 250, 250 };
	sf::Vector2f highscoresCurrentButtonPosition;
	sf::Text highscoreText;

public:
	MenuState(sf::RenderWindow& window);
	~MenuState() = default;
	void Update() override;
	bool Toggle() override;
	void KeyboardEvent(sf::Keyboard::Scancode scanCode) override;
	void MouseEvent(sf::Mouse::Button click, sf::Vector2i mousePosition, sf::RenderWindow& window) override;
	void Render(sf::RenderWindow& window) override;
};


