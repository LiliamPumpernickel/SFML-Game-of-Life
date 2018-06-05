#include "Cell.h"



Cell::Cell()
{
	cellSize = 10;
	
	
	vertices.setPrimitiveType(sf::TriangleStrip);
	vertices.resize(4);

	vertices[0] = sf::Vector2f(0, 0);
	vertices[0].color = sf::Color::Black;
	vertices[1] = sf::Vector2f(cellSize, 0);
	vertices[1].color = sf::Color::Black;
	vertices[2] = sf::Vector2f(0, cellSize);
	vertices[2].color = sf::Color::Black;
	vertices[3] = sf::Vector2f(cellSize, cellSize);
	vertices[3].color = sf::Color::Black;
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(vertices, states);
}

Cell::Cell(int* size)
{
	cellSize = (float)*size;

	vertices.setPrimitiveType(sf::TriangleStrip);
	vertices.resize(4);

	vertices[0] = sf::Vector2f(0, 0);
	vertices[0].color = sf::Color::Black;
	vertices[1] = sf::Vector2f(cellSize, 0);
	vertices[1].color = sf::Color::Black;
	vertices[2] = sf::Vector2f(0, cellSize);
	vertices[2].color = sf::Color::Black;
	vertices[3] = sf::Vector2f(cellSize, cellSize);
	vertices[3].color = sf::Color::Black;
}





Cell::~Cell()
{
}
