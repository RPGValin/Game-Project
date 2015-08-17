#ifndef GESTIONGRAPHISMES_H_INCLUDED
#define GESTIONGRAPHISMES_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../Divers/SingletonWindow.h"

class Graphismes
{
public:
    Graphismes();
    Graphismes(int x,int y);

    void doMyLife();

    void setImageTexture(std::string fileName);
    void setPosition();
    void setSpriteTexture();

    void doAllThings(std::string fileName, Graphismes &cible);// utilise les méthodes dérnières
    void lunchAnimation(int x,int y, int tailleX,int tailleY);//anim le perso
    void draw(sf::RenderWindow &window); //draw le sprite
    bool spriteClick(sf::RenderWindow &window,sf::Event &event);

private:

   sf::Texture texture;
   sf::Sprite sprite;
   int m_x=0; //position x
   int m_y=0; //position y

};

#endif // GESTIONGRAPHISMES_H_INCLUDED
