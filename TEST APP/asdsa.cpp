#include <SFML/Graphics.hpp>
#include <iostream>


class Grid : public sf::Drawable, sf::Transformable
{
private:
	int windowHeight, windowWidth;
	std::vector<sf::Vertex> vertices;


public:
	Grid(int& height, int& width);
};

Grid::Grid(int& height, int& width)
{
	
	int count(0);
	for (int i = 0; i < width; i + 10)
	{
		vertices.push_back((sf::Vertex(sf::Vector2f(i, 0), sf::Color::Black)));
		vertices.push_back((sf::Vertex(sf::Vector2f(i, height), sf::Color::Black)));
		count += 2;
	}
}