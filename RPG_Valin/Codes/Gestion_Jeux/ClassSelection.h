#ifndef CHARSELECTION_H_INCLUDED
#define CHARSELECTION_H_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "SFML/Graphics.hpp"
#include "../Personnage/Personnage.h"

class ClassSelection
{
public:
    Personnage start();
private:

    int choice;
    bool confirmed;

    void loadTexturesAndSetSprites();

    void checkHitBoxs();

    sf::Texture TBackground;
    sf::Sprite SBackground;

    sf::Texture TMage, TGuerrier, TArcher;
    sf::Sprite SMage, SGuerrier, SArcher;

    sf::Texture TRandomButton;
    sf::Sprite SRandomButton;

    sf::Font FArial;
    sf::Text TxClassSelection;

    sf::Texture TConfirmButton;
    sf::Sprite SConfirmButton;

};

#endif // CHARSELECTION_H_INCLUDED
