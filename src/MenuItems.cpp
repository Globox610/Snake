#include "MenuItems.hpp"

MenuItem::MenuItem(sf::Vector2f position, ButtonType buttonType, sf::Font& font, const std::string& menuText)
	:text(font), buttonType(buttonType), buttonPosition(position)
{

	rectangle.setFillColor(sf::Color::Red);
	rectangle.setSize({ 300,100 });
	rectangle.setPosition(buttonPosition);
	text.setFont(font);
	text.setString(menuText);
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);
	text.setPosition(position);
}


