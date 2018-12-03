/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:13 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 22:29:31 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Frameworks/SDL2.framework/Headers/SDL.h"
#include "../Frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include "../Frameworks/SDL2_image.framework/Headers/SDL_image.h"
#ifndef MAIN_HPP
# define MAIN_HPP

#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

#define BUFF_SIZE 1024

#define EXIT_KEY1	27
#define EXIT_KEY2	'q'
#define EXIT_KEY3	'Q'

#define KEY_ONE		'1'
#define KEY_TWO		'2'
#define KEY_THREE	'3'
#define KEY_FOUR	'4'
#define KEY_FIVE	'5'
#define KEY_SIX		'6'
#define KEY_SEVEN	'7'
#define KEY_EIGHT	'8'
#define KEY_NINE	'9'
#define KEY_TEN		'0'

// Colls view
#define COL_ONE		'!'
#define COL_TWO		'@'
#define COL_THREE	'#'
#define COL_FOUR	'$'
#define COL_FIVE	'%'
#define COL_SIX		'^'
#define COL_SEVEN	'&'
#define COL_EIGHT	'*'
#define COL_NINE	'('
#define COL_TEN		')'

// Collor pairs
#define CAT1			41
#define CAT2			42
#define HEADING			43
#define BORDER_COLOR	44

#define WIN_X	420
#define WIN_Y	1400

std::string					exec( const char * );
std::string					strExec( const char * );
std::vector<std::string>	ft_explode( const std::string &, const char );
std::string					&ft_trim( std::string & );

#endif
