#include "Laser.hpp"

Bullet::Bullet(int x, int y) : AObject(x, y) {_val = '-';}

Bullet::Bullet( void ) : AObject() {_val = '-';}

Bullet::~Bullet( void ) {}

bool 	Bullet::move( int timeFrame) {
	if (_x > WINW - 3 + STARTX)
			return FALSE;
	if (timeFrame % 1 == 0){
		_x++;
	} 
	return TRUE;
}

Bullet::Bullet(Bullet const & src) : AObject(src.getX(), src.getY()) {}
