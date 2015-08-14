#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <string>

/* La classe sort nous permet de créer des sorts et de les utiliser
 * facilement
 */

class Sort
{
	public:

		Sort(std::string, unsigned int, unsigned int);

		unsigned int operator()(unsigned int*);

	private:

		std::string m_nom;

		unsigned int m_degatsMagiques;
		unsigned int m_coutMana;
};

#endif
