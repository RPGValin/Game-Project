#include <string>
#include "Arme.h"

/* Deux constructeurs:
 * un sans paramètre
 * et un avec le nom et les degats provoqués par l'arme
 */

Arme::Arme()
{
	m_nom = "Épée de bronze";
	m_degats = 10;
}

Arme::Arme(std::string nom, unsigned int degats)
{
	m_nom = nom;
	m_degats = degats;
}

/* La fonction changerArme() affecte un nouvelle valeur
 * à chaque attribut de la classe Arme
 */

void Arme::changerArme(std::string nom, unsigned int degats)
{
	m_nom = nom;
	m_degats = degats;
}


std::string Arme::getNom() const
{
	return m_nom;
}

unsigned int Arme::getDegats() const
{
	return m_degats;
}
