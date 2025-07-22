// sfml-formatter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
int main(){


    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Font font;
    sf::Text header;
    sf::Text subtitle;

    vector <sf::RectangleShape> btns;
    vector <sf::Text> btnsText;
    vector <sf::RectangleShape> fieldsBack;;
    vector <sf::Text> fields;
    vector <sf::Text> fieldsName;
    int activeField = 0;
    string names[5]{ "mm","sm","dm", "m", "km" };



    const sf::Vector2f SIZE_BTN(50.f, 30.f);
    const sf::Vector2f SIZE_FIELD(300.f, 30.f);

    for (int i = 0; i < 5; i++) {
        sf::RectangleShape back(SIZE_FIELD);
        sf::Text text;
        sf::Text textName;
        text.setFont(font);
        text.setCharacterSize(18);
        text.setString("0");
        text.setFillColor(sf::Color::Black);

        textName.setFont(font);
        textName.setCharacterSize(18);
        textName.setString(names[i]);
        textName.setFillColor(sf::Color::White);
        back.setPosition(sf::Vector2f(65, 150 + i * 50));
        fieldsBack.push_back(back);
        sf::Vector2f position = back.getPosition();
        text.setPosition(sf::Vector2f(position.x + 15, position.y + 6));
        textName.setPosition(sf::Vector2f(0, 150 + i * 50));

        fieldsName.push_back(textName);
        fields.push_back(text);
    }

    for (int i = 0; i < 12; i++){   
        sf::RectangleShape btn(SIZE_BTN);
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(18);
        if (i == 10) {
            text.setString(".");
        }
        else if (i == 11) {
            text.setString("C");
        }
        else {
            text.setString(to_string(i));
        }
        
        text.setFillColor(sf::Color::Black);

        btn.setPosition(sf::Vector2f(i * 60, 100));
        btns.push_back(btn);
        sf::Vector2f position = btn.getPosition();

        text.setPosition(sf::Vector2f(position.x + 15, position.y + 6));
        btnsText.push_back(text);
    }

    sf::RectangleShape btn(SIZE_BTN);
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(18);
    text.setString(".");
    text.setFillColor(sf::Color::Black);

    font.loadFromFile("./font/arialbd.ttf");

    subtitle.setFont(font);
    subtitle.setCharacterSize(18);
    subtitle.setString("input your value: ...");
    subtitle.setPosition(sf::Vector2f(0, 30));
    header.setFont(font);
    header.setString("values formatter");
    header.setCharacterSize(24);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto mousePosition = event.mouseButton;
                    for (int i = 0; i < btns.size(); i++) {
                        if (mousePosition.x >= btns[i].getPosition().x &&
                            mousePosition.x <= btns[i].getPosition().x + SIZE_BTN.x &&
                            mousePosition.y >= btns[i].getPosition().y &&
                            mousePosition.y <= btns[i].getPosition().y + SIZE_BTN.y) {

                            btns[i].setFillColor(sf::Color::Green);
                            auto currentString = fields[activeField].getString();
                            if (i == 10) {
                                fields[activeField].setString(currentString + ".");
                            }
                            else if (i == 11) {
                                fields[activeField].setString("0");
                            }
                            else {
                                text.setString(to_string(i));

                                auto num = btnsText[i].getString().toAnsiString();
                               
                                auto currentNum = stod(fields[activeField].getString().toAnsiString());
                                if (currentNum == 0) {
                                    currentString = "";
                                }
                                fields[activeField].setString(currentString + num);
                            }
                        }
                    }
                    for (int i = 0; i < fieldsBack.size(); i++) {
                        if (mousePosition.x >= fieldsBack[i].getPosition().x &&
                            mousePosition.x <= fieldsBack[i].getPosition().x + SIZE_FIELD.x &&
                            mousePosition.y >= fieldsBack[i].getPosition().y &&
                            mousePosition.y <= fieldsBack[i].getPosition().y + SIZE_FIELD.y) {

                            activeField = i;
                        }
                    }
                }
            }
            else {
                for (int i = 0; i < btns.size(); i++) {
                    btns[i].setFillColor(sf::Color::White);
                }
            }
        }
        auto activeNumber = stod(fields[activeField].getString().toAnsiString());
        for (int i = activeField - 1, index = 10; i >= 0; i--, index *= 10) {
            fields[i].setString(to_string(activeNumber * index));
        }
        for (int i = activeField + 1, index = 10; i < fields.size(); i++, index *= 10) {
            fields[i].setString(to_string(activeNumber / index));
        }

        for (int i = 0; i < fields.size(); i++) {
            auto num = activeNumber;
        }
        for (int i = 0; i < fieldsBack.size(); i++) {
            fieldsBack[i].setFillColor(sf::Color::White);
            fields[i].setFillColor(sf::Color::Black);
        }
        
        fieldsBack[activeField].setFillColor(sf::Color::Blue);
        fields[activeField].setFillColor(sf::Color::White);
     
        window.clear();
        window.draw(header);
        window.draw(subtitle);

        for (auto i : fieldsName) {
            window.draw(i);
        }
        for (auto i : btns) {
            window.draw(i);
        }
        for (auto i : btnsText) {
            window.draw(i);
        }
        for (auto i : fieldsBack) {
            window.draw(i);
        }
        for (auto i : fields) {
            window.draw(i);
        }
        window.display();

        
    }
}