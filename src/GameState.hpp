#ifndef GameState_hpp
#define GameState_hpp
#include <SFML/Graphics.hpp>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "HighscoreManager.hpp"

class GameState
{
private:
	int currentScore = 0;
	HighScoreManager highscoreManager;
public:
	GameState() = default;
	~GameState() = default;
	virtual void Update() {}
	virtual bool Toggle() = 0;
	virtual void Render(sf::RenderWindow& window) = 0;
	virtual void KeyboardEvent(sf::Keyboard::Scancode scanCode) {}
	virtual void MouseEvent(sf::Mouse::Button click, sf::Vector2i mousePosition, sf::RenderWindow& window) {}
	int GetScore() { return currentScore; }
	void IncreaseScore() { currentScore++; }
	void ResetScore() { currentScore = 0; }
	void SetNewHighscore();
	std::string GetDateTime();
	std::string GetAllHighscores();
};
#endif // !GameState.hpp