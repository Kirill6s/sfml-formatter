// sfml-formatter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
int main()
{
    

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::RectangleShape btn(sf::Vector2f(50.f, 30.f));
    
    sf::Font font;
    sf::Text header;
    sf::Text subtitle;
   
    font.loadFromFile("./font/arialbd.ttf");

    vector <sf::RectangleShape> btns;
    vector <sf::Text> btnsText;

    for (int i = 0; i < 10; i++)
    {
        sf::RectangleShape btn(sf::Vector2f(50.f, 30.f));
        sf::Text text;

        text.setFont(font);
        text.setCharacterSize(18);
        text.setString(to_string(i));
        text.setFillColor(sf::Color::Black);

        
        btn.setPosition(sf::Vector2f(i*60, 100));
        btns.push_back(btn);
        sf::Vector2f position = btn.getPosition();

        text.setPosition(sf::Vector2f(position.x+10, 110));
        btnsText.push_back(text);

       
    }
   

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
        for (auto i : btns) {
            window.draw(i);
        }
        for (auto i : btnsText) {
            window.draw(i);
        }
        window.display();

    }
}
