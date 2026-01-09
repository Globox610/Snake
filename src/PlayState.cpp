#include "PlayState.hpp"
#include <iostream>


PlayState::PlayState(sf::RenderWindow& window)
{
	grid = new GridData();
	food = new Food();
	snake = new SnakeBody();

	gridView = new GridView(grid->GetCellPitch());
	assetHolder = new AssetHolder(grid->GetCellPitch());
	clock.start();
	window.setTitle("PlayState");
	food->RandomizeSpawn(*grid, *snake);



	keyBindings[sf::Keyboard::Scancode::W] = [this]()
		{
			snake->SetDirection(Direction::South);
		};

	keyBindings[sf::Keyboard::Scancode::D] = [this]()
		{
			snake->SetDirection(Direction::East);
		};

	keyBindings[sf::Keyboard::Scancode::S] = [this]()
		{
			snake->SetDirection(Direction::North);
		};

	keyBindings[sf::Keyboard::Scancode::A] = [this]()
		{
			snake->SetDirection(Direction::West);
		};
}

PlayState::~PlayState()
{
	delete grid;
	delete food;
	delete snake;
	delete gridView;
	delete assetHolder;
}


void PlayState::DrawGrid(sf::RenderWindow& window)
{

	for (int y = 0; y < grid->GetRows(); ++y)
		for (int x = 0; x < grid->GetColumns(); ++x)
		{
			gridView->cellOutline.setPosition(
				grid->GridToWorld({ x, y })
			);
			window.draw(gridView->cellOutline);
		}
	

}
void PlayState::DrawFood(sf::RenderWindow& window)
{
	
		auto foodCell = food->GetFoodLocation();
		assetHolder->food.setPosition(
		grid->GridToWorld(foodCell)
		+ sf::Vector2f(
			(grid->GetCellPitch() - assetHolder->food.getSize().x) * 0.5f,
			(grid->GetCellPitch() - assetHolder->food.getSize().y) * 0.5f
		)
	);

		window.draw(assetHolder->food);
}

void PlayState::DrawSnake(sf::RenderWindow& window)
{

	const auto& cells = snake->GetBodyPositions();

	bool isHead = true;
	for (const auto& cell : cells)
	{
		auto& shape = isHead ? assetHolder->snakeHead : assetHolder->snakeBody;
		shape.setPosition(grid->GridToWorld(cell));
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

	if (auto it = keyBindings.find(scanCode); it != keyBindings.end())
	{
		it->second();
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
		snake->Update();
		dead = snake->HandleCollision(*grid);


		if (snake->GetBodyPositions()[0] == food->GetFoodLocation())
		{
			food->RandomizeSpawn(*grid, *snake);
			snake->SetGrowOnNextUpdate(true);
		}



		if (dead)
		{
			toggleState = true;
		}





		elapsedTime = clock.reset();
		clock.start();
	}

}