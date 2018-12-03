#include "Hero.hpp"
#include "Window.hpp"

Hero::Hero( void ) : AObject(){
	_val = '>';
	lives = 5;
}

Hero::Hero(Hero const & src) : AObject(src.getX(), src.getY()){}

bool 	Hero::move( int timeFrame) {
	if (timeFrame == 0)
		return 1;
	return 0;
}

Hero::Hero(int x, int y) : AObject(x, y){
	_val = '>';
	lives = 5;
}

void 	Hero::move( int const input, int timeFrame) {
	if (timeFrame){
		if (input == KEY_UP && _y > (STARTY + 1))
			_y--;
		else if (input == KEY_DOWN && _y < (STARTY + WINH - 2))
			_y++;
		else if (input == KEY_LEFT && _x > (STARTX + 1))
			_x--;
		else if (input == KEY_RIGHT && _x < (STARTX + WINW - 2))
			_x++;
	}
}

Hero::~Hero( void ) {}