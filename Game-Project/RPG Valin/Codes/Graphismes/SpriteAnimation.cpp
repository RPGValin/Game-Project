#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteAnimation.h"

Animation::Animation()
{

}
Animation::~Animation()
{

}

void Animation::lunchAnimation(sf::Sprite &sprite,int x,int y, int tailleX,int tailleY)
{
    sprite.setTextureRect(sf::IntRect(x,y,tailleX,tailleY));


}
