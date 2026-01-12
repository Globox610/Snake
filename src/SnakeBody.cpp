#include "SnakeBody.hpp"
#include <iostream>

SnakeBody::SnakeBody()
{
	bodyRect.setSize(sf::Vector2f(78, 78));
	bodyRect.setOutlineColor(sf::Color::White);
	bodyRect.setFillColor(sf::Color::Transparent);
	bodyRect.setOutlineThickness(2.f);

	bodyPositions.push_back(sf::Vector2i(5, 5));
	direction = Direction::North;
	
}

SnakeBody::~SnakeBody()
{
}

std::deque<sf::Vector2i>& SnakeBody::GetBodyPositions()
{
	return bodyPositions;
}




void SnakeBody::SetDirection(Direction direction)
{
	if (CheckOpposite(direction))
	{
		this->direction = direction;

	}

}

bool SnakeBody::GetGrowOnNextUpdate()
{
	return growOnNextUpdate;
}

void SnakeBody::SetGrowOnNextUpdate(bool grow)
{
	this->growOnNextUpdate = grow;
}


void SnakeBody::MoveBy(sf::Vector2i& delta)
{
	const sf::Vector2i newHead = bodyPositions.front() + delta;
	bodyPositions.push_front(newHead);

	if (growOnNextUpdate)
	{
		growOnNextUpdate = false;

	}
	else
	{
		bodyPositions.pop_back();

	}

}

bool SnakeBody::CheckOpposite(Direction direction)
{
	if (direction == Direction::North && this->direction == Direction::South ||
		direction == Direction::East && this->direction == Direction::West ||
		direction == Direction::South && this->direction == Direction::North ||
		direction == Direction::West && this->direction == Direction::East)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool SnakeBody::HandleCollision(GridData& grid)
{

	if (
		bodyPositions[0].x < 0 ||
		bodyPositions[0].x >= grid.GetColumns() ||
		bodyPositions[0].y < 0 ||
		bodyPositions[0].y >= grid.GetRows()
		)
	{
		ResetSnake();
		return true;
	}

	for (int i = 1; i < bodyPositions.size(); i++)
	{
		if (bodyPositions[0] == bodyPositions[i])
		{
			ResetSnake();
			return true;
		}
	}


	return false;
}

void SnakeBody::ResetSnake()
{
	int sizeOfDequeue = bodyPositions.size();
	for (int i = 1; i < sizeOfDequeue; i++)
	{
		bodyPositions.pop_back();
	}

	bodyPositions.at(0) = {sf::Vector2i(5,5)};
}

void SnakeBody::Update()
{
	sf::Vector2i delta = { 0,0 };
	switch (direction)
	{
	case Direction::North:
		delta = { 0,1 };
		break;
	case Direction::East:
		delta = { 1,0 };

		break;
	case Direction::South:
		delta = { 0,-1 };
		break;
	case Direction::West:
		delta = { -1,0 };
		break;

	}

	MoveBy(delta);
}

