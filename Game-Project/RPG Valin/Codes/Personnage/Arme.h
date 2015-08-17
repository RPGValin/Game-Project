#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED

#include <string>

/* La classe Arme nous permet de créer facilement une arme et d'en changer,
 * c'est un attribut de personnage
 */

class Arme
{
	public:

		Arme();
		Arme(std::string, unsigned int);

		void changerArme(std::string, unsigned int);

		std::string getNom() const;
		unsigned int getDegats() const;

	private:

		std::string m_nom;
		unsigned int m_degats;
};

#endif
