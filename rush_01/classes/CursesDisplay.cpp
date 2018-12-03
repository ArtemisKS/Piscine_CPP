/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesDisplay.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:22 by akupriia          #+#    #+#             */
/*   Updated: 2018/12/03 08:20:27 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CursesDisplay.hpp>

CursesDisplay::CursesDisplay( void ) : 
	isUser(true),
	isOs(true),
	isDate(true),
	isCPUInfo(true),
	isRAMInfo(true),
	isNetInfo(true),
	isNetInter(true),
	isKatskiy(true),
	isRest(true),
	isDisks(true),
	_modules(0),
	numCol(2)
{
	this->init();
}
CursesDisplay::CursesDisplay( const CursesDisplay &toCopy )
{
	*this = toCopy;
}
CursesDisplay::~CursesDisplay( void )
{
	this->deleteAll();
	endwin();

	system("echo '\t\t\t\t\t\tTWAS NICE TO SEE YOU, BICHES of FlOriDa!!'");
}
CursesDisplay				&CursesDisplay::operator=( const CursesDisplay &toCopy )
{
	isUser = toCopy.isUser;
	isOs = toCopy.isOs;
	isDate = toCopy.isDate;
	isCPUInfo = toCopy.isCPUInfo;
	isRAMInfo = toCopy.isRAMInfo;
	isNetInfo = toCopy.isNetInfo;
	isNetInter = toCopy.isNetInter;
	isKatskiy = toCopy.isKatskiy;
	isDisks = toCopy.isDisks;
	isRest = toCopy.isRest;
	_modules = toCopy._modules;
	numCol = toCopy.numCol;

	return *this;
}

void						CursesDisplay::run( void )
{
	time_t			t = time(NULL);
	int				c;

	while (true)
	{
		c = getch();
		if ( c == KEY_ONE )				this->switchName();
		else if ( c == KEY_TWO )		this->switchOSinfo();
		else if ( c == KEY_THREE )		this->switchTime();
		else if ( c == KEY_FOUR )		this->switchCPU();
		else if ( c == KEY_FIVE )		this->switchRAM();
		else if ( c == KEY_SIX )		this->switchNetworkThro();
		else if ( c == KEY_SEVEN )		this->switchNetworkInfo();
		else if ( c == KEY_EIGHT )		this->switchCat();
		else if ( c == KEY_NINE )		this->switchDisks();
		else if ( c == KEY_TEN )		this->switchRest();

		else if ( c == COL_ONE )		this->switchCols(1);
		else if ( c == COL_TWO )		this->switchCols(2);
		else if ( c == COL_THREE )		this->switchCols(3);
		else if ( c == COL_FOUR )		this->switchCols(4);
		else if ( c == COL_FIVE )		this->switchCols(5);
		else if ( c == COL_SIX )		this->switchCols(6);
		else if ( c == COL_SEVEN )		this->switchCols(7);
		else if ( c == COL_EIGHT )		this->switchCols(8);
		else if ( c == COL_NINE )		this->switchCols(9);
		else if ( c == COL_TEN )		this->switchCols(10);

		else if ( c == EXIT_KEY1 || c == EXIT_KEY2 || c == EXIT_KEY3 )
			break ;

		if ( t != time(NULL) ) {
			this->refresh();
			t = time(NULL);
		}
	}
}

void						CursesDisplay::init( void )
{
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	clear();
	noecho();
	cbreak();

	start_color();
	init_pair(CAT1, COLOR_CYAN, COLOR_BLACK);
	init_pair(CAT2, COLOR_WHITE, COLOR_BLACK);
	init_pair(HEADING, COLOR_RED, COLOR_BLACK);
	init_pair(BORDER_COLOR, COLOR_CYAN, COLOR_CYAN);

	this->allocateAll();
}
void						CursesDisplay::deleteAll( void )
{
	for ( ; _modules.size(); )
	{
		delete _modules.front();
		_modules.erase(_modules.begin());
	}
}
void						CursesDisplay::allocateAll( void )
{
	if ( isUser )			_modules.push_back(new Name("1. User info", numCol));
	if ( isOs )				_modules.push_back(new OS("2. OS info", numCol));
	if ( isDate )			_modules.push_back(new Time("3. Date info", numCol));
	if ( isCPUInfo )		_modules.push_back(new CPU("4. CPU info", numCol));
	if ( isRAMInfo )		_modules.push_back(new RAM("5. RAM info", numCol));
	if ( isNetInfo )		_modules.push_back(new NetworkThro("6. Network info", numCol));
	if ( isNetInter )		_modules.push_back(new NetworkInfo("7. Network interfaces", numCol));
	if ( isKatskiy )		_modules.push_back(new Unicat("8. Zaz's pet", numCol));
	if ( isDisks )		_modules.push_back(new Disks("9. Disks info", numCol));
	if ( isRest )		_modules.push_back(new Rest("10. Residuary info", numCol));
}
void						CursesDisplay::reAllocate( void )
{
	this->deleteAll();

	this->allocateAll();

	clear();
}
void						CursesDisplay::refresh( void ) const
{
	for (	std::vector<int>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		_modules[i]->display();
	}
}

void						CursesDisplay::switchName( void )
{
	isUser = !isUser;
	this->reAllocate();
}
void						CursesDisplay::switchOSinfo( void )
{
	isOs = !isOs;
	this->reAllocate();
}
void						CursesDisplay::switchTime( void )
{
	isDate = !isDate;
	this->reAllocate();
}
void						CursesDisplay::switchCPU( void )
{
	isCPUInfo = !isCPUInfo;
	this->reAllocate();
}
void						CursesDisplay::switchRAM( void )
{
	isRAMInfo = !isRAMInfo;
	this->reAllocate();
}
void						CursesDisplay::switchNetworkThro( void )
{
	isNetInfo = !isNetInfo;
	this->reAllocate();
}
void						CursesDisplay::switchNetworkInfo( void )
{
	isNetInter = !isNetInter;
	this->reAllocate();
}
void						CursesDisplay::switchCat( void )
{
	isKatskiy = !isKatskiy;
	this->reAllocate();
}

void						CursesDisplay::switchRest( void )
{
	isRest = !isRest;
	this->reAllocate();
}

void						CursesDisplay::switchDisks( void )
{
	isDisks = !isDisks;
	this->reAllocate();
}

void						CursesDisplay::switchCols( int nbColums )
{
	numCol = nbColums;
	this->reAllocate();
}
