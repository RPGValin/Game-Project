#include "Animations.h"

void Animations::run(std::string classe)
{
    if(classe == "Mage")
    {
        if(!TAnimations.loadFromFile("Ressources/Images/Animations.png"))
            std::cout<<"erreur chargement animations classe mage"<<std::endl;
    }
    else if(classe == "Guerrier")
    {
        //Chargement classe Guerrier
    }
    else if(classe == "Archer")
    {
        //Chargement classe Archer
    }
    else
        std::cout << "Erreur chargement animations pour la classe : " << classe << std::endl;

    SAnimation.setTextureRect(sf::IntRect(0, 32*animationID, 32, 32));
}

void Animations::setAnimation(int ID)
{
    animationID = ID;
}

void Animations::doMyLife()
{
    ++tick;
    switch(tick)
    {
        case 10:
            SAnimation.setTextureRect(sf::IntRect(0, 32*animationID, 32, 32));
            break;
        case 20:
            SAnimation.setTextureRect(sf::IntRect(32, 32*animationID, 32, 32));
            break;
        case 30:
            SAnimation.setTextureRect(sf::IntRect(64, 32*animationID, 32, 32));
            break;
        case 40:
            SAnimation.setTextureRect(sf::IntRect(32, 32*animationID, 32, 32));
            tick = 0;
            break;
        default :
            break;
    }
    SAnimation.setTexture(TAnimations);
}

sf::Sprite Animations::getSprite()
{
    return SAnimation;
}
