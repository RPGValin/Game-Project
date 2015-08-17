#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include "../Gestion_Jeux/Game.h"
#include "../Divers/SingletonWindow.h"
#include <iostream>
class MainMenu
{
	public:

    void run();

	private:

    int checkHitBoxs();

    sf::RectangleShape cache;
    bool cacheActivated;

    void loadTexturesAndSetSprites();
    sf::Texture TBackground;
    sf::Sprite SBackground;

    sf::Texture TPlayButton;
    sf::Sprite SPlayButton;

    sf::Texture TOptionsButton;
    sf::Sprite SOptionsButton;

    sf::Texture TQuitButton;
    sf::Sprite SQuitButton;
};


#endif // MAINMENU_H_INCLUDED
