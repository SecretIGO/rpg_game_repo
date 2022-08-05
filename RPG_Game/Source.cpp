#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

int main()
{
    //- - - - - - - - - I N I T I A L I Z A T I O N - - - - - - - - -
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My Game");

    //- - - - - - - - ~ I N I T I A L I Z A T I O N - - - - - - - - -
    
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("assets/sprites/walk_cycle/sprite_sheet.png"))
    {
        std::cout << "Player texture loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);

        int x_ind = 0;
        int y_ind = 0;
        playerSprite.setTextureRect(sf::IntRect(x_ind*40, y_ind*83+15, 40, 83));
    }
    else
        std::cout << "Player texture was not found!";


    while (window.isOpen())
    {
        //- - - - - - - - - - - U P D A T E - - - - - - - - - - - - -

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            /*if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::D)
                {
                    sf::Vector2f currPos = playerSprite.getPosition();
                    playerSprite.setPosition(currPos + sf::Vector2f(5, 0));
                }
            }*/
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sf::Vector2f currPos = playerSprite.getPosition();
            playerSprite.setPosition(currPos + sf::Vector2f(0, -0.5));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sf::Vector2f currPos = playerSprite.getPosition();
            playerSprite.setPosition(currPos + sf::Vector2f(-0.5, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sf::Vector2f currPos = playerSprite.getPosition();
            playerSprite.setPosition(currPos + sf::Vector2f(0, 0.5));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sf::Vector2f currPos = playerSprite.getPosition();
            playerSprite.setPosition(currPos + sf::Vector2f(0.5, 0));
        }
        //- - - - - - - - - - ~ U P D A T E - - - - - - - - - - - - -
        
        //- - - - - - - - - - D I S P L A Y - - - - - - - - - - - - -
        
        window.clear(sf::Color::White);
        window.draw(playerSprite);
        window.display();

        //- - - - - - - - - ~ D I S P L A Y - - - - - - - - - - - - -
    }

    return 0;
}