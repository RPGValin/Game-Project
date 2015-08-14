#ifndef GRAPHISMES_JEUX_H_INCLUDED
#define GRAPHISMES_JEUX_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "GestionGraphismes.h"

class GameGraphics
{
public:
    GameGraphics();

    void initializeGraphicStart();
    void drawSprite(sf::RenderWindow &window);

private:
 Graphismes m_GraphicObjectA;
 Graphismes m_GraphicObjectB;

};

#endif // GRAPHISMES_JEUX_H_INCLUDED
