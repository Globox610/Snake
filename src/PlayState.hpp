#ifndef PlayState_hpp
#define PlayState_hpp
#include <SFML/Graphics.hpp>
#include "CellTypes.hpp"
#include "Gamestate.hpp"
#include "GridData.hpp"
#include "Food.hpp"
#include "SnakeBody.hpp"
#include "GridBuilder.hpp"
#include "AssetHolder.hpp"


class PlayState : public GameState
{
private:

	//Data structures
	GridData grid;
	Food food;
	SnakeBody snake;

	//Time values
	float updateTime = 2.5f;
	sf::Clock clock;
	sf::Time elapsedTime;

	//Sprites
	GridView gridView;
	AssetHolder assetHolder;

	//Toggle states
	bool toggleState = false;


	void DrawGrid(sf::RenderWindow& renderWindow);
	void DrawFood(sf::RenderWindow& renderWindow);
	void DrawSnake(sf::RenderWindow& renderWindow);
	void ResetGame();
public:
	PlayState(sf::RenderWindow& window);
	void KeyboardEvent(sf::Keyboard::Scancode scanCode) override;
	void MouseEvent(sf::Mouse::Button click) override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
	bool Toggle() override;
};


#endif // !PlayState_hpp
