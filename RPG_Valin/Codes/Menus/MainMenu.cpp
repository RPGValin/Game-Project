#include "MainMenu.h"

void MainMenu::run()
{
    cacheActivated = false;
    sf::RenderWindow& mWindow = Window::getWindow();
    this->loadTexturesAndSetSprites();

    while(mWindow.isOpen())
    {
        sf::Event event;
        while(mWindow.pollEvent(event))
        {
            if(event.type == event.Closed)
                Window::closeWindow();
        }

        switch(this->checkHitBoxs())
        {
        case 0:
            cacheActivated = false;
            break;

        case 1:
            cacheActivated = true;
            cache.setPosition(450, 300);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Game game;
                game.run();
            }
            break;

        case 2:
            cacheActivated = true;
            cache.setPosition(450, 375);
            //ajouter ici le lancement de la page des options
            break;

        case 3:
            cacheActivated = true;
            cache.setPosition(450, 450);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                Window::closeWindow();
            break;

        default:
            cacheActivated = false;
            break;

        }

        mWindow.clear();
        mWindow.draw(SBackground);
        mWindow.draw(SPlayButton);
        mWindow.draw(SOptionsButton);
        mWindow.draw(SQuitButton);
        if(cacheActivated)
            mWindow.draw(cache);
        mWindow.display();

    }
}
int MainMenu::checkHitBoxs()
{
    sf::RenderWindow& mWindow = Window::getWindow();
    if(SPlayButton.getGlobalBounds().contains(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow))))
        return 1;
    if(SOptionsButton.getGlobalBounds().contains(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow))))
        return 2;
    if(SQuitButton.getGlobalBounds().contains(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow))))
        return 3;

    return 0;
}
void MainMenu::loadTexturesAndSetSprites()
{
    //Background
    if(!TBackground.loadFromFile("Ressources/Images/NewBackground.jpg"))
        std::cout<<"erreur chargement background(MainMenu)"<<std::endl;
    else
        SBackground.setTexture(TBackground);
    //Bouton jouer
    if(!TPlayButton.loadFromFile("Ressources/Images/PlayButton.png"))
        std::cout<<"erreur chargement image bouton jouer(MainMenu)"<<std::endl;
    else
        SPlayButton.setTexture(TPlayButton);
    SPlayButton.setPosition(sf::Vector2f(440,295));
    //Bouton Options
    if(!TOptionsButton.loadFromFile("Ressources/Images/OptionsButton.png"))
        std::cout<<"erreur chargement image bouton options(MainMenu)"<<std::endl;
    else
        SOptionsButton.setTexture(TOptionsButton);
    SOptionsButton.setPosition(sf::Vector2f(440,370));
    //Bouton Quitter
    if(!TQuitButton.loadFromFile("Ressources/Images/QuitButton.png"))
        std::cout<<"erreur chargement image bouton quitter(MainMenu)"<<std::endl;
    else
        SQuitButton.setTexture(TQuitButton);
    SQuitButton.setPosition(sf::Vector2f(440,445));

    //Cache
    sf::Vector2f cacheSize(70, 32);
    cache.setFillColor(sf::Color(0, 0, 0, 50));
    cache.setSize(cacheSize);
}
