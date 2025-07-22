#pragma once
#include <SFML/Graphics.hpp>
class Button

{private:
	sf::RectangleShape shape;
	sf::Text text;
	sf::Font font;
public:
	Button(sf::Vector2f size, sf::String string);
	void setColor(sf::Color);
	void setPosition()
};

