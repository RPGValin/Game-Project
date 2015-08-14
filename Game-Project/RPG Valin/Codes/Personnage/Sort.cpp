#include <string>
#include "Sort.h"

/* Le constructeur prend comme paramètre le nom du sort, les degats magiques
 * qu'il fait et son cout en mana.
 * Si celui-ci est négatif, il prend une valeur de 0
 */

Sort::Sort(std::string nom, unsigned int degatsMagiques, unsigned int coutMana)
{
	m_nom = nom;
	m_degatsMagiques = degatsMagiques;
	m_coutMana = coutMana;
}

/* L'operateur () permet de lancer le sort facilement, il prend en paramètre
 * un pointeur sur le mana actuel du personnage, afin d'utiliser le sort
 * ou non
 */

unsigned int Sort::operator()(unsigned int* mana)
{
	if(*mana >= m_coutMana)
	{
		*mana -= m_coutMana;
		return m_degatsMagiques;
	}
	else
	{
		return 0;
	}
}
