#include "EnLaser.hpp"

EnemyBullet::EnemyBullet(EnemyBullet const & src) : AObject(src.getX(), src.getY()) {}

bool 	EnemyBullet::move( int timeFrame) {
	if (_x < STARTX + 3)
			return FALSE;
	if (timeFrame % 1 == 0){
		_x--;
	} 
	return TRUE;
}

EnemyBullet::EnemyBullet(int x, int y) : AObject(x, y) {_val = '*';}

EnemyBullet::EnemyBullet( void ) : AObject() {_val = '*';}

EnemyBullet::~EnemyBullet( void ) {}