#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
sf::Vector2f Normalize(sf::Vector2f _vec)
{
    float mag = sqrt(_vec.x * _vec.x + _vec.y * _vec.y);
    return sf::Vector2f(_vec.x / mag, _vec.y / mag);
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800),"Pong");
    sf::CircleShape bila(10.f);
    sf::Clock cloc;
    sf::RectangleShape square(sf::Vector2(10.f,10.f));
    sf::Vector2 squarePos(500.f,500.f);
    sf::Vector2f vel(1.f,1.f);
    sf::Vector2f dir(1.f,1.f);
    square.setPosition(squarePos);
    bila.setPosition(window.getSize().x/2,window.getSize().y/2);
    float o=1.f;
    float speed=20.f;
    while (window.isOpen())
    {
        const float deltaTime = cloc.getElapsedTime().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(bila.getPosition().x>=square.getPosition().x&&bila.getPosition().y>=square.getPosition().y){
        dir = bila.getPosition()-squarePos;
        dir.x*=-1;
        }
        speed+=1;
        dir=Normalize(dir);
        vel=Normalize(dir)*speed;
        bila.move(vel*deltaTime);
        cloc.restart();
        window.clear();
        window.draw(bila);
        window.draw(square);
        window.display();
    }

    return 0;
}