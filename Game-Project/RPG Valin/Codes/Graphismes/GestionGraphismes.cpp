#include "GestionGraphismes.h"


Graphismes::Graphismes()
{

}
Graphismes::Graphismes(int x,int y)
{
    m_x = x;
    m_y = y;

}
/*
*Fonction de base
*/
void Graphismes::doMyLife()
{
    sf::RenderWindow& mWindow = Window::getWindow();
    mWindow.draw(sprite);
}

void Graphismes::setImageTexture(std::string fileName)
{

    if(!texture.loadFromFile(fileName))
        std::cout<<"erreur chargement background"<<std::endl;

    else
    {
        sprite.setTexture(texture);
    }
}
void Graphismes::setPosition()
{

    sprite.setPosition(sf::Vector2f(m_x,m_y));

}
void Graphismes::doAllThings(std::string fileName, Graphismes &cible)
{
    cible.setImageTexture(fileName);
    if(m_x>0 || m_y>0)
    {
        cible.setPosition();
    }

}

bool Graphismes::spriteClick(sf::RenderWindow &window,sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        if(sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
        {
            std::cout << "Unit selected" << std::endl;

            return true;

        }
}
void Graphismes::lunchAnimation(int x,int y, int tailleSpriteX,int tailleSpriteY)
{

}

