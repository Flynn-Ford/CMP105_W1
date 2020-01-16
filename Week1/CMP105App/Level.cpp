#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects

	//Red Rectangle

	rect.setSize(sf::Vector2f(50, 6));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);
	rect.setOrigin(25, 3); //Added after tutorial question completion (for point of rotation to be centered)

	//Layered Squares (Rectangles with equal dimensions)

	rect1.setSize(sf::Vector2f(60, 60));
	rect1.setPosition(300, 200);
	rect1.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(40, 40));
	rect2.setPosition(310, 210);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(20, 20));
	rect3.setPosition(320, 220);
	rect3.setFillColor(sf::Color::Blue);

	//Bottom Right Rectangle

	cornerRect.setSize(sf::Vector2f(50, 50));
	cornerRect.setFillColor(sf::Color::Red);

	//Circle

	circle.setRadius(50);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineThickness(5);
	circle.setOutlineColor(sf::Color::Red);

	//Text

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading Font\n";
	}
	text.setFont(font);
	text.setCharacterSize(24);
	text.setString("Hello World");	//You know, that thing that everyone writes as their first text when programming
	text.setFillColor(sf::Color::Red);
	text.setPosition(100, 5);		//5 Pixels off top for tidiness
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	cornerRect.setPosition(pos.x - 50, pos.y - 50);
	circle.setPosition((pos.x / 2) - 50, (pos.y / 2) - 50); //Pos / 2 gets center screen, - 50 since origin is top left
	rect.setRotation(rect.getRotation() + 1); //Added after tutorial question completion
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);
	window->draw(circle);
	window->draw(rect1);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(text);
	window->draw(cornerRect);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}