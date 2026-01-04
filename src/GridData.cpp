#include "GridData.hpp"

GridData::GridData()
{
	



}

sf::Vector2f GridData::GridToWorld(sf::Vector2i cell) const
{
	return { origin.x + cell.x * cellPitch, origin.y + cell.y * cellPitch };
}



const int GridData::GetColumns() const
{
	return gridColumns;
}

const int GridData::GetRows() const
{
	return gridRows;
}




const float GridData::GetCellPitch() const
{
	return cellPitch;
}

