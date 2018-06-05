#include "Grid.h"



Grid::Grid()
{
	size = 0;
	Update();
}


void Grid::SetSize(int* size)
{
	this->size = *size;
	Update();
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(vertices, states);
}


//Sukuria lenteles taðkus ir sudeda juos i vektoriu 
void Grid::Update()
{
	vertices.setPrimitiveType(sf::Lines);
	vertices.resize(((size*size) / 10 )+4);

	int count(0);
	for (int i = 0; i <= size; i += 10)
	{
		vertices[count++].position = sf::Vector2f(i, 0);
		vertices[count].color = sf::Color::Black;
		vertices[count++].position = sf::Vector2f(i, size);
		vertices[count].color = sf::Color::Black;
	}
	for (int i = 0; i <= size; i += 10)
	{
		vertices[count].color = sf::Color::Black;
		vertices[count++].position = sf::Vector2f(0, i);
		
		vertices[count].color = sf::Color::Black;
		vertices[count++].position = sf::Vector2f(size, i);
		
	}

}


Grid::~Grid()
{
}
