// sfml-formatter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
int main()
{


    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Font font;
    sf::Text header;
    sf::Text fieldMm;
    sf::Text fieldSm;
    sf::Text fieldDm;
    sf::Text fieldM;
    sf::Text fieldKm;
    sf::Text subtitle;

    vector <sf::RectangleShape> btns;
    vector <sf::Text> btnsText;

    const sf::Vector2f SIZE_BTN(50.f, 30.f);

    sf"

    for (int i = 0; i < 10; i++)
    {   sf::RectangleShape btn(SIZE_BTN);
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(18);
        text.setString(to_string(i));
        text.setFillColor(sf::Color::Black);

        btn.setPosition(sf::Vector2f(i * 60, 100));
        btns.push_back(btn);
        sf::Vector2f position = btn.getPosition();

        text.setPosition(sf::Vector2f(position.x + 15, position.y + 6));
        btnsText.push_back(text);
    }
    font.loadFromFile("./font/arialbd.ttf");

    subtitle.setFont(font);
    subtitle.setCharacterSize(18);
    subtitle.setString("input your value: ...");
    subtitle.setPosition(sf::Vector2f(0, 30));
    header.setFont(font);
    header.setString("values formatter");
    header.setCharacterSize(24);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    auto mousePosition = event.mouseButton;

                    for (int i = 0; i < btns.size(); i++) {
                    
                        if (mousePosition.x >= btns[i].getPosition().x &&
                            mousePosition.x <= btns[i].getPosition().x + SIZE_BTN.x &&
                            mousePosition.y >= btns[i].getPosition().y &&
                            mousePosition.y <= btns[i].getPosition().y + SIZE_BTN.y) {
                            
                           
                            btns[i].setFillColor(sf::Color::Green);
                            cout << btnsText[i].getString().toAnsiString();
                       
                         
                        
                        }
                     
                    }
                    
                }
            }
            else {
                for (int i = 0; i < btns.size(); i++)
                {
                    btns[i].setFillColor(sf::Color::White);
                }
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
}