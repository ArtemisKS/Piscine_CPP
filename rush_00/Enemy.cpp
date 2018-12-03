#include "Enemy.hpp"

Enemy::Enemy( void ) : AObject() {
	char	val[2] = {'O', 'X'};
	_val = val[rand() % 2];
}

Enemy::Enemy(Enemy const & src) : AObject(src.getX(), src.getY()) {}

Enemy::Enemy(int x, int y) : AObject(x, y) {
	char	val[2] = {'O', 'X'};
	_val = val[rand() % 2];
}

bool 	Enemy::move( int timeFrame ) {
	if (_x >= 10) {
		if (timeFrame % 2 == 0){ 
			_x--;
		}
		return TRUE;
	}
	return FALSE;
}

Enemy::~Enemy( void ) {} 