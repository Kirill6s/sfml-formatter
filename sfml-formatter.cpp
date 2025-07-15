// sfml-formatter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
int main()
{
    

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  
    sf::Font font;
    sf::Text header;
    sf::Text subtitle;
    font.loadFromFile("./font/arialbd.ttf");
    

    header.setFont(font);
    header.setString("values formatter");
    header.setCharacterSize(24);

    subtitle.setFont(font);
    subtitle.setString("input your value: ...");
    subtitle.setCharacterSize(18);
    subtitle.setPosition(sf::Vector2f(0,30));

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        window.draw(header);
        window.draw(subtitle);

        window.display();

    }
}
