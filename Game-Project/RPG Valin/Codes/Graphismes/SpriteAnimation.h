#ifndef SPRITEANIMATION_H_INCLUDED
#define SPRITEANIMATION_H_INCLUDED
#include "GestionGraphismes.h"

class Animation
{
    public:
    Animation();
    ~Animation();

   void lunchAnimation(sf::Sprite &sprite ,int x,int y, int tailleX,int tailleY);
    private:

sf::Sprite sprite;
};

#endif // SPRITEANIMATION_H_INCLUDED
