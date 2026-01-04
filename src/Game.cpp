#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "MenuState.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({800u, 800u}), "The best snake of your loijf", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    //Initializers for unique ptrs
    std::unique_ptr play = std::make_unique<PlayState>(window);
    std::unique_ptr menu = std::make_unique<MenuState>(window);

    //Usable ptrs
    GameState* currentState = play.get();
    GameState* playState = play.get();
    GameState* menuState = menu.get();


    while (window.isOpen())
    {
        while (const auto& event = window.pollEvent())
        {
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                currentState->KeyboardEvent(keyPressed->scancode);
            }

            if (event->is<sf::Event::MouseButtonPressed>())
            {
                currentState->MouseEvent(event->getIf<sf::Event::MouseButtonPressed>()->button);
            }

            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }           
        }


        window.clear();
        currentState->Render(window);
        currentState->Update();
        window.display();
        if (currentState->Toggle())
        {
            currentState = (currentState == playState) ? menuState : playState;
        }
    }
}
