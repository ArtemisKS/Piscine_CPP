#ifndef LASER_HPP
 #define LASER_HPP

#include "AObject.hpp"
#include "Window.hpp"

class Bullet : public AObject {
public:
	Bullet(void);
	Bullet(int x, int y);
	Bullet(Bullet const & src);
	~Bullet();
	using AObject::operator=;
	bool	move( int );
	bool colision(AObject const & elem);
};

#endif
