#include "Button.h"

Button::Button(sf::Vector2f size, sf::String string):shape(size)
{
    text.setFont(font);
    text.setCharacterSize(18);
    text.setString(string);
    text.setFillColor(sf::Color::Black);
}
