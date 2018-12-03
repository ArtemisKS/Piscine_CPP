/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:56 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 13:59:29 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CursesDisplay.hpp>
#include <GUIDisplay.hpp>

static void		putError( const char *err )
{
	std::cout << err << std::endl;
	std::cout << "usage: ./ft_gkrellm (-g|-c)" << std::endl;
}

static void			displayCurses( void )
{
	CursesDisplay	d;
	d.run();
}

static void			displayGUI( void )
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_Window *window  = SDL_CreateWindow("ft_gkrellm",
	0 , 0,
	WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window,
		-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	GUIDisplay	d(window, renderer);
}

int				main( int ac, char **av )
{
	pid_t			pid = fork();

	if ( pid == 0 ) {
		system("mkdir -p other");
		system("system_profiler -detailLevel mini > other/sysinfo");
		return 0;
	}
	if ( ac > 2 ) {
		putError("ERROR: too much arguments");
	}
	else if ( ac == 2 )
	{
		if ( !strcmp("-c", av[1]) )	displayCurses();
		if ( !strcmp("-g", av[1]) )	displayGUI();
		else	putError("ERROR: wrong second argument");
	}
	else {
		displayCurses();
	}

	return 0;
}
