#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;

	sf::RectangleShape rect; //Initial Rectangle
	sf::CircleShape circle; //Circle in center of screen
	sf::RectangleShape rect1; //Lowest layered rectangle
	sf::RectangleShape rect2; //Mid layered rectangle
	sf::RectangleShape rect3; //Highest layered rectangle
	sf::RectangleShape cornerRect; //Rectangle in bottom right corner

	sf::Font font;
	sf::Text text;
};