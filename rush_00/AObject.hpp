#ifndef AOBJECT_HPP
# define AOBJECT_HPP

#include <ncurses.h> // mwprintw attron

class AObject {
public:
	AObject(void);
	AObject(int x, int y);
	AObject(AObject const & src);
	virtual ~AObject();
	
	AObject const &	operator=(AObject const & rdh);
	virtual bool			move( int ) = 0;

	bool 			colision(AObject*&);
	void			printO(char *val);
	void			printS(char *val);
	void			printX(char *val);
	void			printH(char *val);
	virtual void	print();
	virtual void	del();
	int				getX( void ) const ;
	int				getY( void ) const ;

protected:
	int _x;
	int _y;
	char _val;
};

#endif
