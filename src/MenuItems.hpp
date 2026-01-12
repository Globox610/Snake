#pragma once
#include "SFML/Graphics.hpp"
#include <string>

enum ButtonType
{
	Start,
	Exit,
	Highscores
};

class MenuItem
{
private:
	sf::RectangleShape rectangle;
	sf::Vector2f buttonPosition;
	ButtonType buttonType;
	sf::Text text;
public:
	MenuItem(sf::Vector2f position, ButtonType buttonType, sf::Font& font, const std::string& menuString);
	sf::RectangleShape& GetRectangle() { return rectangle; }
	sf::Text& GetMenuText() { return text; }
	ButtonType GetButtonType() { return buttonType;  }

};
