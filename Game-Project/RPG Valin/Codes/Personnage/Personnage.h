#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include <functional>
#include "Arme.h"
#include "Sort.h"

class Personnage
{
	public:

		Personnage(std::string);
		Personnage(std::string, std::string, int);

        ~Personnage();

		void mage();
		void guerrier();
		void archer();

		bool estVivant();

		void calculVitesse();
		bool boirePotion();
		bool recevoirDegats(unsigned int);
		void changerArme(std::string, unsigned int);

		bool attaquer(Personnage&);
		bool utiliserSort(Personnage&);

		std::string getNom();
		std::string getNomClasse();
		unsigned int getVie();
		unsigned int getVieMax();
		unsigned int getMana();
		unsigned int getManaMax();
		unsigned int getVitesse();
		unsigned int getVitesseLimite();
		unsigned int getDegats();
		unsigned int getDefense();
		unsigned int getNbPotions();
		std::string getNomArme();
		unsigned int getDegatsArme();

	private:

		std::string m_nom;
		std::string m_nomClasse;

		unsigned int m_vie;
		unsigned int m_vieMax;

		unsigned int m_mana;
		unsigned int m_manaMax;

		unsigned int m_vitesse;
		unsigned int m_vitesseLimite;

		unsigned int m_degats;
		unsigned int m_defense;

		unsigned int m_nbPotions;

		Arme* m_arme;
		std::function<unsigned int(unsigned int*)> m_sort;
};

#endif
