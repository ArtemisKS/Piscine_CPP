#ifndef ENLASER_HPP
 #define ENLASER_HPP

#include "AObject.hpp"
#include "Window.hpp"

class EnemyBullet : public AObject
{
public:
	EnemyBullet(void);
	EnemyBullet(int x, int y);
	EnemyBullet(EnemyBullet const & src);
	~EnemyBullet();
	using AObject::operator=;
	bool colision(AObject const & elem);
	bool	move( int );
};

#endif
