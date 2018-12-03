/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACursesModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:51:09 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 22:41:45 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ACursesModule.hpp>

ACursesModule::ACursesModule( void ) :
	motto(""),
	numCol(2)
{
	_mode = 0;
	init();
}
ACursesModule::ACursesModule( std::string &str, int nbColums ) :
	motto(str),
	numCol(nbColums)
{
	_mode = 0;
	init();
}

ACursesModule::ACursesModule( std::string &str, int nbColums, int fuck)
{
	fuck = 0;
	numCol = nbColums;
	motto = str;
	_mode = 1;
	initGUI();
}

ACursesModule::ACursesModule( const ACursesModule &toCopy )
{
	*this = toCopy;
}
ACursesModule::~ACursesModule( void )
{
	if (!_mode)
	{
		decInitYX();
		wborder(_w, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
		wrefresh(_w);
		delwin(_w);
	}
	else
	{
		initial_y = 30;
		initial_x = 50;
		make_x_frame = 0;
		make_y_frame = 0;
	}
}
ACursesModule				&ACursesModule::operator=( const ACursesModule &toCopy )
{
	_w = toCopy._w;
	motto = toCopy.motto;
	numCol = toCopy.numCol;
	init_y = toCopy.init_y;
	init_x = toCopy.init_x;

	return *this;
}


void			ACursesModule::refBord( void ) const
{
	wattron(_w, COLOR_PAIR(BORDER_COLOR));
	wborder(_w, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wattroff(_w, COLOR_PAIR(BORDER_COLOR));
}
void			ACursesModule::init( void )
{
	static int			initial_y = 0;
	static int			initial_x = 0;

	init_y = &initial_y;
	init_x = &initial_x;
	_w = newwin(size_y, size_x, initial_y, initial_x);
	this->refBord();
	initial_x += size_x;
	if ( initial_x == (size_x * numCol) ) {
		initial_y += size_y;
		initial_x = 0;
	}
	this->refresh();
}
void			ACursesModule::display( void ) const
{
	return ;
}


void			ACursesModule::refresh( void ) const
{
	wattron( _w, COLOR_PAIR(HEADING) | A_BOLD );
	mvwprintw(this->_w, 1, alignCenter(motto), "%s", motto.c_str());
	wattroff( _w, COLOR_PAIR(HEADING) | A_BOLD );

	this->refBord();

	wrefresh(_w);
}
int				ACursesModule::alignCenter( const std::string &str ) const
{
	const int		len = (size_x - str.length()) / 2;

	if ( len > bordLayer ) {
		return len;
	}
	else {
		return bordLayer;
	}
}
int				ACursesModule::alignCenter( const int slen ) const
{
	const int		len = (size_x - slen) / 2;

	if ( len > bordLayer ) {
		return len;
	}
	else {
		return bordLayer;
	}
}
int				ACursesModule::alignRight( const std::string &str ) const
{
	const int		len = size_x - str.length() - bordLayer;

	if ( len > bordLayer ) {
		return len;
	}
	else {
		return bordLayer;
	}
}
int				ACursesModule::alignRight( const int slen ) const
{
	const int		len = size_x - slen - bordLayer;

	if ( len > bordLayer ) {
		return len;
	}
	else {
		return bordLayer;
	}
}
void			ACursesModule::decInitYX( void )
{
	*init_y = 0;
	*init_x = 0;
}
void			ACursesModule::clearLine( int line ) const
{
	std::string		spaces( size_x - (bordLayer * 2), ' ' );

	mvwprintw(this->_w, line, bordLayer, "%s", spaces.c_str());
}
void			ACursesModule::clearWindow( void ) const
{
	const int	bottom = size_y - bordLayer;

	for ( int i = bordLayer; i < bottom; i++ ) {
		this->clearLine(i);
	}
}


															
WINDOW			*ACursesModule::getWin( void ) const
{
	return this->_w;
}

//GUI

void			ACursesModule::initGUI( void )
{
	_y = ACursesModule::initial_y;
	_x = ACursesModule::initial_x;
	frame_y = ACursesModule::make_y_frame;
	frame_x = ACursesModule::make_x_frame;

	ACursesModule::initial_y += numCol * s_y_sdl + 30;
	ACursesModule::make_y_frame += numCol * s_y_sdl + 30;
}
void			ACursesModule::displaySDL( void ) const
{
	return ;
}

int			ACursesModule::initial_y = 30;
int			ACursesModule::initial_x = 50;
int			ACursesModule::make_y_frame = 0;
int			ACursesModule::make_x_frame = 0;