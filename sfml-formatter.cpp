﻿// sfml-formatter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::CircleShape circle(20.f);
    circle.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
  
        sf::Event event;
        while (window.pollEvent(event))
        {
    
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(circle);
     
        window.display();
    }

    return EXIT_SUCCESS;
}