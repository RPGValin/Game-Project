#include "SingletonWindow.h"

sf::RenderWindow fenetre;
bool Window::alreadyCreated = false;

sf::RenderWindow& Window::getWindow()
{
    if(!alreadyCreated)
    {
        fenetre.create(sf::VideoMode(800,600),"RPG Valin",sf::Style::Resize == false |sf::Style::Fullscreen==false |sf::Style::Titlebar |sf::Style::Close);
        alreadyCreated = true;
        fenetre.setFramerateLimit(60); //on limite les fps à 60
    }
    return fenetre;
}
void Window::closeWindow()
{
    fenetre.close();
    return;
}
//sf::RenderWindow& mWindow = Window::getWindow(); pour récupérer la fenetre
