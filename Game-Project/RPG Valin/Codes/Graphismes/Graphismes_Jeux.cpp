#include "Graphismes_Jeux.h"


GameGraphics::GameGraphics()
{

}

void GameGraphics::initializeGraphicStart()
{
    Graphismes backGroundMenu,jouerButton(247,310);
    m_GraphicObjectA= backGroundMenu;
    m_GraphicObjectB = jouerButton;
    jouerButton.setImageTexture("jouer_bouton.png");
    backGroundMenu.setImageTexture("Background.png");

    jouerButton.setPosition();
}
void GameGraphics::drawSprite(sf::RenderWindow &window)
{
    m_GraphicObjectA.doMyLife();
    m_GraphicObjectB.doMyLife();
}
