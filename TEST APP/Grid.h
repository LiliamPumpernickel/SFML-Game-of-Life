#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Grid : public sf::Drawable, public sf::Transformable
{
private:

	//Drawable klases virtuali funkcija skirta piesti objekta
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	sf::VertexArray vertices;

	int size;
	void Update();


public:
	Grid();
	void SetSize(int* size); // Keicia lenteles dydi
	~Grid();
	
};

