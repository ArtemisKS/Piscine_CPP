#ifndef window_HPP
# define window_HPP

#define STARTX 5
#define STARTY 5
#define WINH 60
#define WINW 150
#define WIN_SCORE 300
#define NEXTLVL 50
#define TIME_VAL(t1, t2) (((t2).tv_sec * 1000000 + (t2).tv_usec) - ((t1).tv_sec * 1000000 + (t1).tv_usec))

#include "Hero.hpp"
#include "EnLaser.hpp"
#include "Enemy.hpp"
#include "Star.hpp"
#include "AObject.hpp"
#include "Laser.hpp"
#include <sys/time.h>
#include <ncurses.h>
#include <iostream>

class Window
{
	public:
		Window();
		Window(Window const &);
		~Window();

		Window const &	operator=(Window const &);
		int		pause();
		void	play();

	private:
		int				sound;
		int 			score;
		int				level;
		unsigned int	delay;
		Hero			hero;
		int				input;
		int				lastInput;
		AObject*	 	elements[100];
		AObject*	 	ebullets[1000];
		AObject*	 	stars[100];
		AObject*	 	bullets[1000];
		unsigned long	timeFrame;
		struct timeval	curr_time;
		struct timeval	start_time;
		WINDOW			*window;
		const int		HEIGHT;
		const int		WIDTH;
		const int		WSTARTX;
		const int		WSTARTY;

		void			printScreen();
		void			shoot_yeah(int x, int y);
		void			enemyBullets(int x, int y);
		int				checkTime();
		void			moveScreenObj(AObject* elements[], int n);
		void			initEnemy();
		void			delScreen();
		int				collide_bullets();
		int				collide_enemies();
		int				collide();
		void			check_result(int lose, int win);
		void			moveElems(int const input);
};

#endif

