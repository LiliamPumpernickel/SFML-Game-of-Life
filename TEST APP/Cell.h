#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Cell : public sf::Drawable, public sf::Transformable
{
private:

	float cellSize;
	sf::VertexArray vertices;

public:
	Cell(); 
	Cell(int* size);
	~Cell();

	//Drawable klases virtuali funkcija skirta piesti objekta
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
};

