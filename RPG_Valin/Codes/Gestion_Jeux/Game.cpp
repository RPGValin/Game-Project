#include "Game.h"

void Game::run()
{
    sf::RenderWindow& mWindow = Window::getWindow();
    ClassSelection selection;
    selection.start();
    while(mWindow.isOpen())
    {
        sf::Event event;
        while(mWindow.pollEvent(event))
        {
            if(event.type == event.Closed)
                Window::closeWindow();
        }
        mWindow.clear();
        mWindow.display();
    }

}
