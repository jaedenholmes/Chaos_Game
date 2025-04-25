// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	
			    if(vertices.size() < 3)
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			    else if(points.size() == 0)
			    {
					///fourth click
					///push back to points vector;
					points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));

			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
			for(int i = 0; i < 1000; i++)
			{
				//generating a random number 1-3 to choose a random vertex
				
				Vector2f randomVertex = vertices[rand() % 3];

				///calculate halfway between the randomly selected
				///vertex and the current point i.e. the last point
				///in the vector
				Vector2f lastPoint = points.back();

				Vector2f midPoint((lastPoint.x + randomVertex.x) / 2.0f, (lastPoint.y + randomVertex.y) / 2.0f);

				//add the midPoint to the vecter
				points.push_back(midPoint);
			}
		}
	
		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();
		for(int i = 0; i < vertices.size(); i++)
		{
		    RectangleShape rect(Vector2f(1,1));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    rect.setFillColor(Color::Red);
		    window.draw(rect);
		}
		///TODO:  Draw points

		for(int i = 0; i < points.size(); i++)
		{
			CircleShape circ(1);
			circ.setPosition(Vector2f(points[i].x, points[i].y));
			circ.setFillColor(Color::Red);
			window.draw(circ);
		}

		window.display();
	}
}
