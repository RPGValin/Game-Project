#ifndef ANIMATIONS_H_INCLUDED
#define ANIMATIONS_H_INCLUDED

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "../Divers/SingletonWindow.h"

class Animations
{
	public:
	    void run(std::string classe);
        void doMyLife();
        sf::Sprite getSprite();
        void setAnimation(int ID);
	private:
	    int animationID;
	    int tick;
        sf::Texture TAnimations;
        sf::Sprite SAnimation;


};


#endif // ANIMATIONS_H_INCLUDED
