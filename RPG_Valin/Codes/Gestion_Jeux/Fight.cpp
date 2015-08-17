#include "Fight.h"

void start()
{
    sf::RenderWindow& mWindow = Window::getWindow();

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
