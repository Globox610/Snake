#include "MenuState.hpp"

MenuState::MenuState(sf::RenderWindow& window)
{
	window.setTitle("Menu");

}

void MenuState::MouseEvent(sf::Mouse::Button click)
{
	switch (click)
	{
	case sf::Mouse::Button::Left:
		toggleState = true;
		break;
	}
}

void MenuState::KeyboardEvent(sf::Keyboard::Scancode scanCode)
{

}

void MenuState::Render(sf::RenderWindow& window)
{
}

void MenuState::Update()
{


}

bool MenuState::Toggle()
{
	if (!toggleState)
	{
		return false;
	}
	else
	{
		toggleState = false;
		return true;
	}
}
