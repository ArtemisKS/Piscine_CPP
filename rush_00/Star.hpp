#ifndef STAR_HPP
 #define STAR_HPP

#include "AObject.hpp"

class Star : public AObject
{
public:
	Star(void);
	Star(int x, int y);
	Star(Star const & src);
	~Star();
	using AObject::operator=;
	bool	move( int );

};

#endif
