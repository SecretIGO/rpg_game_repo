#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //- - - - - - - - - I N I T I A L I Z A T I O N - - - - - - - - -

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My Game");

    float shapeSize_height = 400.f;
    float shapeSize_length = 250.f;
    float shapeOrigin_height = shapeSize_height / 2;
    float shapeOrigin_length = shapeSize_length / 2;

    sf::RectangleShape shape(sf::Vector2f(shapeOrigin_height, shapeOrigin_length));

    shape.setFillColor(sf::Color::Black);
    shape.setOutlineThickness(3.3f);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOrigin(shapeOrigin_height, shapeOrigin_length);
    shape.setPosition(sf::Vector2f(640.0f,540.0f));
    shape.setRotation(75);

    //- - - - - - - - ~ I N I T I A L I Z A T I O N - - - - - - - - -
    
    while (window.isOpen())
    {
        //- - - - - - - - - - - U P D A T E - - - - - - - - - - - - -

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //- - - - - - - - - - ~ U P D A T E - - - - - - - - - - - - -
        
        //- - - - - - - - - - D I S P L A Y - - - - - - - - - - - - -

        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();

        //- - - - - - - - - ~ D I S P L A Y - - - - - - - - - - - - -
    }

    return 0;
}