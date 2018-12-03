#include "Star.hpp"
#include <ncurses.h>

Star::Star( void ) : AObject() {_val = '.';}

Star::~Star( void ) {}

Star::Star(Star const & src) : AObject(src.getX(), src.getY()){}

Star::Star(int x, int y) : AObject(x, y) {_val = '.';}

bool 	Star::move( int timeFrame ) {
	if (_x >= 11)
	{
		if (timeFrame % 3 == 0)
			_x--;
		return TRUE;
	}
	else
		return FALSE;
}
