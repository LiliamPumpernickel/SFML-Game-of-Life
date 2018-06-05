#include "Board.h"
#include <SFML/Graphics.hpp>

Board::Board()
{
}

void Board::Initialize(int* boardSize, sf::RenderWindow& targetWindow)
{
	this->boardSize = *boardSize;
	grid.SetSize(boardSize);
	for (int i = 0; i < this->boardSize/10; i++)
	{
		for (int j = 0; j < this->boardSize/10; j++)
		{
			cellArray[i][j] = false;
			updatedCellArray[i][j] = false;
		}
	}
	isPaused = true;


}

bool  Board::UpdateCell(bool array[400][400], int* x, int* y)
{
	int livingNeighbour = 0;

	for (int i = *x - 1; i <= *x + 1; i++)
	{
		for (int j = *y - 1; j <= *y + 1; j++)
		{
			if (!(i == *x && j == *y))
				if (cellArray[i][j] == true)
					livingNeighbour++;
		}
	}

	switch (livingNeighbour) {
	case 0:
		return false;
		break;
	case 1:
		return false;
	case 2:
	{
		if (cellArray[*x][*y] == true)
			return true;
		else
			return false;
		break;
	}
	case 3:
		return true;
		break;
	case 4:
		return false;
		break;
	case 5:
		return false;
		break;
	case 6:
		return false;
		break;
	}
	return false;
}


void Board::UpdateGeneration()
{
	
	for (int i = 0; i < boardSize / 10; i++)
	{
		for (int j = 0; j < boardSize / 10; j++)
		{
			cellArray[i][j] = updatedCellArray[i][j];
		}
	}
}


void Board::DrawBoard(sf::RenderWindow& targetWindow)
{
	targetWindow.draw(grid);
	for (int i = 0; i < boardSize / 10; i++)
	{
		for (int j = 0; j < boardSize / 10; j++)
		{
			if (cellArray[i][j] == true)
			{

				cell.setPosition(sf::Vector2f(i * 10, j * 10));
				targetWindow.draw(cell);

			}
			updatedCellArray[i][j] = UpdateCell(cellArray, &i, &j);
		}
	}
	if (cellUpdateTimer.getElapsedTime().asSeconds() >= (float)0.3 && !isPaused)
	{
		UpdateGeneration();
		cellUpdateTimer.restart();
	}
	
}

void Board::PutNewCell(int* x, int* y)
{
	cellArray[*x / 10][*y / 10] = true;
}

void Board::SetIsPaused()
{
	isPaused = !isPaused;
}

Board::~Board()
{
}
