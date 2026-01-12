#include "MenuState.hpp"
#include <iostream>

MenuState::MenuState(sf::RenderWindow& window)
	:showingHighscores(false), highscoreText(font)
{
	highscoreText.setCharacterSize(20);
	if (!font.openFromFile("Assets/Fonts/fontshit.ttf"))
	{
		throw std::runtime_error("Could not load font");
	}
	window.setTitle("Menu");
	menuItems.push_back(std::make_unique<MenuItem>(sf::Vector2f(250, 50), ButtonType::Start, font, "Start Game"));
	menuItems.push_back(std::make_unique<MenuItem>(sf::Vector2f(highscoresOriginalButtonPosition), ButtonType::Highscores, font, "Show Highscores"));
	menuItems.push_back(std::make_unique<MenuItem>(sf::Vector2f(250, 450), ButtonType::Exit, font, "Exit Game"));


}

void MenuState::MouseEvent(sf::Mouse::Button click, sf::Vector2i mousePosition, sf::RenderWindow& window)
{
	sf::Vector2f mousePos(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	if (click == sf::Mouse::Button::Left)
	{
		for (int i = 0; i < menuItems.size(); i++)
		{
			if (menuItems[i]->GetRectangle().getGlobalBounds().contains(mousePos))
			{
				std::string buttonTitle;
				switch (menuItems[i]->GetButtonType())
				{
				case ButtonType::Start:
					toggleState = true;
					break;
				case ButtonType::Highscores:
					showingHighscores = !showingHighscores;
					highscoresCurrentButtonPosition = showingHighscores ? sf::Vector2f(0, 0) : highscoresOriginalButtonPosition;
					menuItems[1]->GetMenuText().setPosition(highscoresCurrentButtonPosition);
					menuItems[1]->GetRectangle().setPosition(highscoresCurrentButtonPosition);
					 buttonTitle = showingHighscores ? "Return Menu" : "Show Highscores";
					menuItems[1]->GetMenuText().setString(buttonTitle);
					break;
				case ButtonType::Exit:
					window.close();

					break;
				}
			}
		}
	}

	
}

void MenuState::KeyboardEvent(sf::Keyboard::Scancode scanCode)
{
	if (sf::Keyboard::Scancode::Escape == scanCode)
	{
		toggleState = true;
	}

}

void MenuState::Render(sf::RenderWindow& window)
{
	if (showingHighscores)
	{

		highscoreText.setString(GameState::GetAllHighscores());
		highscoreText.setPosition(sf::Vector2f(100, 300));
		window.draw(menuItems[1]->GetRectangle());
		window.draw(menuItems[1]->GetMenuText());
		window.draw(highscoreText);
	}
	else
	{
		for (size_t i = 0; i < menuItems.size(); i++)
		{
			window.draw(menuItems[i]->GetRectangle());
			window.draw(menuItems[i]->GetMenuText());
		}

	}
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
