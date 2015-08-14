#include "lancementCombat.h"
#include <iostream>
#include "../Graphismes/SpriteAnimation.h"


void combat()//lancement du combat
{
    sf::RenderWindow& mWindow = Window::getWindow();
    Graphismes combatBackgound;
    combatBackgound.doAllThings("Ressources/Images/combat_background.png",combatBackgound);

    Graphismes player(203,371);
    player.doAllThings("Ressources/Images/i2.png",player);


    while(mWindow.isOpen())
    {


        sf::Event event;
        while(mWindow.pollEvent(event))
        {
            if(event.type == event.Closed)
                mWindow.close();

            player.lunchAnimation(0,32,32,32);

        }
        mWindow.clear();
        combatBackgound.doMyLife();
        player.doMyLife();
        mWindow.display();
    }

}
