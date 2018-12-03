#ifndef ENEMY_HPP
 #define ENEMY_HPP

#include "AObject.hpp"
#include <iostream> // rand

class Enemy : public AObject {
public:
	Enemy(void);
	Enemy(int x, int y);
	Enemy(Enemy const & src);
	~Enemy();
	using AObject::operator=;
	bool	move( int );
};

#endif
