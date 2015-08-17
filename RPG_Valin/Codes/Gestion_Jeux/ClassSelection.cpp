#include "ClassSelection.h"

Personnage ClassSelection::start()
{
    sf::RenderWindow& mWindow = Window::getWindow();
    this->loadTexturesAndSetSprites();

    srand(time(NULL));
    Personnage personnage("Test");
    choice = 0;
    confirmed = false;
    while(mWindow.isOpen())
    {
        sf::Event event;
        while(mWindow.pollEvent(event))
        {
            if(event.type == event.Closed)
                Window::closeWindow();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->checkHitBoxs();
        }
        mWindow.clear();
        mWindow.draw(SBackground);
        if(choice != 0)
        {
            switch(choice)
            {
            case 1:
                TxClassSelection.setString("Etes-vous sur de vouloir choisir la classe Mage ?");
                break;
            case 2:
                TxClassSelection.setString("Etes-vous sur de vouloir choisir la classe Guerrier ?");
                break;
            case 3:
                TxClassSelection.setString("Etes-vous sur de vouloir choisir la classe Archer ?");
                break;
            }
            mWindow.draw(SConfirmButton);
        }
        mWindow.draw(SMage);
        mWindow.draw(SGuerrier);
        mWindow.draw(SArcher);
        mWindow.draw(SRandomButton);
        mWindow.draw(TxClassSelection);
        mWindow.display();
        if(confirmed)
        {
            switch(choice)
            {
            case 1:
                personnage.mage();
                break;
            case 2:
                personnage.guerrier();
                break;
            case 3:
                personnage.archer();
                break;
            }
            break;
        }
    }
    return personnage;
}
void ClassSelection::checkHitBoxs()
{
    sf::RenderWindow& mWindow = Window::getWindow();
    if(SMage.getGlobalBounds().contains(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow))))
        choice = 1;
    if(SGuerrier.getGlobalBounds().contains(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow))))
        choice = 2;
    if(SArcher.getGlobalBounds().contains(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow))))
        choice = 3;
    if(SRandomButton.getGlobalBounds().contains(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow))))
        choice = 1+rand()%3;
    if(choice != 0)
        if(SConfirmButton.getGlobalBounds().contains(mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow))))
            confirmed = true;
}
void ClassSelection::loadTexturesAndSetSprites()
{
    //Background
    if(!TBackground.loadFromFile("Ressources/Images/ClassSelectionBackground.png"))
        std::cout<<"erreur chargement background(ClassSelection)"<<std::endl;
    else
        SBackground.setTexture(TBackground);
    //Bouton choix mage
    if(!TMage.loadFromFile("Ressources/Images/MageIcon.png"))
        std::cout<<"erreur chargement image bouton jouer(ClassSelection)"<<std::endl;
    else
        SMage.setTexture(TMage);
    SMage.setPosition(sf::Vector2f(190,190));
    //Bouton choix guerrier
    if(!TGuerrier.loadFromFile("Ressources/Images/GuerrierIcon.png"))
        std::cout<<"erreur chargement image bouton options(ClassSelection)"<<std::endl;
    else
        SGuerrier.setTexture(TGuerrier);
    SGuerrier.setPosition(sf::Vector2f(360,190));
    //Bouton choix archer
    if(!TArcher.loadFromFile("Ressources/Images/ArcherIcon.png"))
        std::cout<<"erreur chargement image bouton quitter(ClassSelection)"<<std::endl;
    else
        SArcher.setTexture(TArcher);
    SArcher.setPosition(sf::Vector2f(538,190));
    //Police et texte
    if (!FArial.loadFromFile("Ressources/Polices/Augusta.ttf"))
        std::cout<<"erreur chargement police (ClassSelection)"<<std::endl;
    else
    {
        TxClassSelection.setFont(FArial);
    }
    TxClassSelection.setPosition(130,440);
    TxClassSelection.setCharacterSize(24);
    TxClassSelection.setString("Veuillez choisir votre classe ...");
    //Bouton Confirmer
    if (!TConfirmButton.loadFromFile("Ressources/Images/ConfirmButton.png"))
        std::cout<<"erreur chargement image bouton confirmer (ClassSelection)"<<std::endl;
    else
        SConfirmButton.setTexture(TConfirmButton);
    SConfirmButton.setPosition(360,480);
    //Bouton Aléatoire
    if (!TRandomButton.loadFromFile("Ressources/Images/RandomButton.png"))
        std::cout<<"erreur chargement image bouton aléatoire (ClassSelection)"<<std::endl;
    else
        SRandomButton.setTexture(TRandomButton);
    SRandomButton.setPosition(110,370);
}
