#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Cell.h"

class Board
{
private:
	int boardSize;
	bool cellArray[400][400];
	bool updatedCellArray[400][400];
	Grid grid;
	Cell cell;
	
	bool isPaused;

	sf::Clock cellUpdateTimer;

	bool UpdateCell(bool array[400][400], int* x, int* y);
	void UpdateGeneration();

	

public:
	Board();

	void PutNewCell(int* x, int* y);

	void SetIsPaused();

	void DrawBoard(sf::RenderWindow& targetWindow);

	void Initialize(int* boardSize, sf::RenderWindow& targetWindow);
	~Board();
};

