#include "PlayState.hpp"
#include <iostream>


PlayState::PlayState(sf::RenderWindow& window)
	: gridView(grid.GetCellPitch()), assetHolder(grid.GetCellPitch())
{


	clock.start();
	window.setTitle("PlayState");

	food.randomizeSpawn(grid);
}


void PlayState::DrawGrid(sf::RenderWindow& window)
{

	for (int y = 0; y < grid.GetRows(); ++y)
		for (int x = 0; x < grid.GetColumns(); ++x)
		{
			gridView.cellOutline.setPosition(
				grid.GridToWorld({ x, y })
			);
			window.draw(gridView.cellOutline);
		}


}
void PlayState::DrawFood(sf::RenderWindow& window)
{
	
		auto foodCell = food.GetFoodLocation();
		assetHolder.food.setPosition(
		grid.GridToWorld(foodCell)
		+ sf::Vector2f(
			(grid.GetCellPitch() - assetHolder.food.getSize().x) * 0.5f,
			(grid.GetCellPitch() - assetHolder.food.getSize().y) * 0.5f
		)
	);

		window.draw(assetHolder.food);
	

}

void PlayState::DrawSnake(sf::RenderWindow& window)
{

	const auto& cells = snake.GetBodyPositions();

	bool isHead = true;
	for (const auto& cell : cells)
	{
		auto& shape = isHead ? assetHolder.snakeHead : assetHolder.snakeBody;
		shape.setPosition(grid.GridToWorld(cell));
		window.draw(shape);
		isHead = false;
	}



}

void PlayState::ResetGame()
{

}



void PlayState::Render(sf::RenderWindow& window)
{
	DrawGrid(window);
	DrawFood(window);
	DrawSnake(window);
}

bool PlayState::Toggle()
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





void PlayState::KeyboardEvent(sf::Keyboard::Scancode scanCode)
{

	switch (scanCode)
	{
	case sf::Keyboard::Scancode::W:
		snake.SetDirection(Direction::South);
		break;
	case sf::Keyboard::Scancode::D:
		snake.SetDirection(Direction::East);

		break;
	case sf::Keyboard::Scancode::S:
		snake.SetDirection(Direction::North);

		break;
	case sf::Keyboard::Scancode::A:
		snake.SetDirection(Direction::West);

		break;
	}
	
}



void PlayState::MouseEvent(sf::Mouse::Button click)
{
	switch (click)
	{
	case sf::Mouse::Button::Left:
		break;

	}

}

void PlayState::Update()
{
	elapsedTime += clock.getElapsedTime();
	bool dead = false;
	if (elapsedTime >= sf::seconds(updateTime))
	{

		snake.Update();
		dead = snake.CheckIfDead(grid);
		elapsedTime = clock.reset();
		clock.start();

		if (dead)
		{
			toggleState = true;
		}
	}

}





