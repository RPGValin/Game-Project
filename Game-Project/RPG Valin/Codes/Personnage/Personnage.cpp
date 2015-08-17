#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>
#include "Personnage.h"

/* Constructeurs
 * un où on choisit le nom
 * un autre où on choisit le nom et l'arme
 */

Personnage::Personnage(std::string nom)
{
	m_nom = nom;
	m_nomClasse = "";

	m_vie = 200;
	m_vieMax = 200;

	m_mana = 100;
	m_manaMax = 100;

	m_vitesse = 0;
	m_vitesseLimite = 100;

	m_degats = 0;
	m_defense = 0;

	m_nbPotions = 4;

	m_arme = new Arme();
	m_sort = Sort("", 0, 0);

	/* aleatoire */

	srand(time(nullptr));
}

Personnage::Personnage(std::string nom, std::string nomArme, int degatsArme)
{
	m_nom = nom;
	m_nomClasse = "";

	m_vie = 200;
	m_vieMax = 200;

	m_mana = 100;
	m_manaMax = 100;

	m_vitesse = 0;
	m_vitesseLimite = 0;

	m_degats = 0;
	m_defense = 0;

	m_nbPotions = 4;

	m_arme = new Arme(nomArme, degatsArme);
	m_sort = Sort("", 0, 0);
}

/* Destructeur
 * destruction de m_arme, qui est un pointeur sur
 * un objet Arme
 */

Personnage::~Personnage()
{
    delete m_arme;
}

/* Les 3 fonctions qui nous permettent de choisir sa classe
 * Appeler une de ces fonctions change les attributs de la classe
 * et change la fonction sort
 */

void Personnage::mage() //change le joueur en mage
{
	m_nomClasse = "Mage";

	m_vie = 220;
	m_vieMax = 220;

	m_mana = 260;
	m_manaMax = 260;

	m_defense = 5;

	m_vitesseLimite = 30;

	m_sort = Sort("Boule de feu", 40, 20);
}

void Personnage::guerrier() //change le joueur en guerrier
{
	m_nomClasse = "Guerrier";

	m_vie = 260;
	m_vieMax = 260;

	m_mana = 230;
	m_manaMax = 230;

	m_defense = 30;

	m_vitesseLimite = 15;

	m_sort = Sort("Coup tournoyant", 20, 15);
}

void Personnage::archer() //change le joueur en archer
{
	m_nomClasse = "Archer";

	m_vie = 230;
	m_vieMax = 230;

	m_mana = 230;
	m_manaMax = 230;

	m_defense = 15;

	m_vitesseLimite = 40;

	m_sort = Sort("Ruée de flèche", 30, 25);
}

/* estVivant() renvoie vrai si le personnage a plus de 0 pv
 * s'il en a 0, il renvoie faux
 */

bool Personnage::estVivant()
{
	if(m_vie > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* calcul de la vitesse
 * pour savoir qui commence à jouer
 */

void Personnage::calculVitesse()
{
	if(!estVivant())
	{
		m_vitesse = 0;
	}
	else
	{
		m_vitesse = rand()%(130-m_vitesseLimite+1) + m_vitesseLimite; //aleatoire entre m_vitesseLimite et 130
	}
}

/* boirePotion() utilise une potion
 * si possible et au besoin.
 * elle retourne true si une potion a été bue
 * et false sinon.
 */

bool Personnage::boirePotion()
{
	if(m_nbPotions > 0 && m_vie < m_vieMax)
	{
		m_vie += 40;

		if(m_vie > m_vieMax)
		{
			m_vie = m_vieMax;
		}

		m_nbPotions--;

		return true;
	}
	else
	{
		return false;
	}
}

/* recevoirDegats() enleve de la vie en fonction des degats recus
 * par une attaque adverse/
 * cette methode n'est appelée que par les methodes attaquer()
 * et utiliserSort()
 * retourne true si l'attaque a touché
 * et false sinon
 */

bool Personnage::recevoirDegats(unsigned int nbDegats)
{
	bool esquive = rand()%10 == 0; //1 chance sur 10

	if(!esquive)
	{
		nbDegats = (unsigned int)((double)m_defense/100 * nbDegats); //reduit les degats en % (egal à la defense)

		if(m_vie > nbDegats)
		{
			m_vie -= nbDegats;
		}
		else
		{
			m_vie = 0;
		}

		return true;
	}
	else
	{
		return false;
	}
}

/* tout simplement,
 * cette méthode change l'ancienne arme par la nouvelle
 */

void Personnage::changerArme(std::string nomArme, unsigned int degatsArme)
{
	m_arme->changerArme(nomArme, degatsArme);
}

/* la methode attaquer() calcule le nombre de degats
 * que le joueur inflige et les fait subir
 * à l'adversaire en appellant la methode recevoirDegats()
 * de la cible
 * retourne true si l'attaque est un coup critique
 * et false sinon
 */

bool Personnage::attaquer(Personnage& cible)
{
	unsigned int degats = rand()%(m_degats+m_arme->getDegats()-1) + m_arme->getDegats(); //aleatoire entre arme.getDegats() et arme.getDegats()+m_degats
	bool coupCritique;

	if(rand()%7 == 0)
	{
		degats += rand()%46 - 10;

		coupCritique = true;
	}
	else
	{
		coupCritique = false;
	}

	cible.recevoirDegats(degats);

	return coupCritique;
}

/* utiliserSort() lance le sort de classe sur l'ennemi
 * en appelant sa méthode recevoirDegats().
 * retourne true si le sort a été lancé
 * et false sinon (pas assez de mana)
 */

bool Personnage::utiliserSort(Personnage& cible)
{
	unsigned int degats = m_sort(&m_mana);

	cible.recevoirDegats(degats);

	if(degats > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/************************
 * liste des accesseurs *
 ************************
 *
 * nous aurons besoin des accesseurs
 * pour l'affichage graphique du statut
 * du personnage
 */

std::string Personnage::getNom()
{
	return m_nom;
}

std::string Personnage::getNomClasse()
{
	return m_nomClasse;
}

unsigned int Personnage::getVie()
{
	return m_vie;
}

unsigned int Personnage::getVieMax()
{
	return m_vieMax;
}

unsigned int Personnage::getMana()
{
	return m_mana;
}

unsigned int Personnage::getManaMax()
{
	return m_manaMax;
}

unsigned int Personnage::getVitesse()
{
	return m_vitesse;
}

unsigned int Personnage::getVitesseLimite()
{
	return m_vitesseLimite;
}

unsigned int Personnage::getDegats()
{
	return m_degats;
}

unsigned int Personnage::getDefense()
{
	return m_defense;
}

unsigned int Personnage::getNbPotions()
{
	return m_nbPotions;
}

std::string Personnage::getNomArme()
{
	return m_arme->getNom();
}

unsigned int Personnage::getDegatsArme()
{
	return m_arme->getDegats();
}
