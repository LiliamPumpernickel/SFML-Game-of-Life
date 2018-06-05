#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include "Board.h"
#include "Test.h"




//Programos pradinis taskas
int main()
{
	Test* t1 = new Test(0, 1, 2);
	Test* t2 = new Test(1, 2, 3);

	std::cout << (t1 == t2);


	//Sukuriams lango objektas bei nustatomas jo dydis ir stilius
	sf::RenderWindow window(sf::VideoMode(500, 500), "GameOfLife", sf::Style::Close); 
	
	//Nustatomas kadrø per minutæ limitas
	window.setFramerateLimit(60);
	//Nustatoma kad laikant mygtuka tai nebutu skaiciuojama kaip skirtingi paspaudimai
	window.setKeyRepeatEnabled(false);


		
	int size = 500;
	Board board;
	board.Initialize(&size,window);




	//zaidimo ciklas (Game loop)
	while (window.isOpen())
	{
		sf::Event event;
		//SFML zaidimo ciklo(game loop) metu laukia mygtukø paspaudimø
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					board.PutNewCell(&localPosition.x, &localPosition.y);
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::P)
				{
					board.SetIsPaused();
				}
			}
		}


		// iðvalo langà (t.y. kiekvienà pixelá nudaþo balta spalva)
		window.clear(sf::Color::White);
	
		board.DrawBoard(window);

		//atvaizduoja langà
		window.display();

	}

		

	return 0;
}