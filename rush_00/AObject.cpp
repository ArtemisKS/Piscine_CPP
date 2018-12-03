#include "AObject.hpp"

AObject::AObject( void ) : _x(10), _y(14), _val(' ') {}

AObject::~AObject( void ) {
	this->del();
}

AObject const &	AObject::operator=(AObject const & rhs) {
		_val = rhs._val;
		_x = rhs._x;
		_y = rhs._y;
	return *this;
}

AObject::AObject(int x, int y) : _x(x), _y(y),  _val(' ') {}

AObject::AObject(AObject const & src) : _x(src._x), _y(src._y), _val(src._val) {}

void	AObject::printO(char *val) {
	attron(COLOR_PAIR(5));
	mvprintw(this->_y, this->_x, val);
	attroff(COLOR_PAIR(5));
}
void	AObject::printS(char *val) {
	attron(COLOR_PAIR(1));
	mvprintw(this->_y, this->_x, val);
	attroff(COLOR_PAIR(1));

}
void	AObject::printX(char *val) {
	attron(COLOR_PAIR(3));
	mvprintw(this->_y, this->_x, val);
	attroff(COLOR_PAIR(3));
}
void	AObject::printH(char *val) {mvprintw(this->_y, this->_x, val);}


void	AObject::print() {
	char	val[2] = {_val, 0};
	void	(AObject::*ft[4])(char *) = {&AObject::printO, &AObject::printS, &AObject::printX, &AObject::printH};
	char	sym[3] = {'O', '*', 'X'};
	int i = -1;
	while (++i < 3){
		if (val[0] == sym[i])
		{
			(this->*ft[i])(val);
			return ;
		}
	}
	(this->*ft[3])(val);
}

int		AObject::getX( void ) const {	return this->_x;}

void	AObject::del() { mvprintw(this->_y, this->_x, " ");}

int		AObject::getY( void ) const {	return this->_y;}

bool	AObject::colision(AObject*& elem) {return ((_x == elem->getX() && _y == elem->getY()) || (_x + 1 == elem->getX() && _y == elem->getY()));}
