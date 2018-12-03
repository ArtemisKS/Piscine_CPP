#ifndef HERO_HPP
# define HERO_HPP

#include "AObject.hpp"
#include <ncurses.h> //KEY_*

class Hero : public AObject
{
public:
	int		lives;
	Hero(void);
	Hero(int x, int y);
	Hero(Hero const & src);
	~Hero();
	using AObject::operator=;
	void	move( int const, int const);
	bool	move( int );
};

#endif
