/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIDisplay.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:49:23 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/14 23:37:14 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GUIDisplay.hpp"
#include <iostream>

GUIDisplay::GUIDisplay(SDL_Window *window, SDL_Renderer *renderer) :
	isUser(true),
	isOs(true),
	isDate(true),
	isCPUInfo(true),
	isRAMInfo(true),
	isNetInfo(true),
	isNetInter(true),
	isKatskiy(true),
	numCol(2)
{
	GUIDisplay::_window = window;
	GUIDisplay::_renderer = renderer;
	if (!(GUIDisplay::_font = TTF_OpenFont("font.ttf", 24)))
		std::cout << TTF_GetError();
	if (!(GUIDisplay::_frame = IMG_LoadTexture(GUIDisplay::_renderer, "art.jpg")))
		std::cout << "Error";
	this->init();
}

GUIDisplay::~GUIDisplay(void)
{
	this->deleteAll();
	if (_renderer)
	{
		SDL_DestroyRenderer(_renderer);
	}
	if (_window)
	{
		SDL_DestroyWindow(_window);
	}
	TTF_Quit();
	SDL_Quit();
}

GUIDisplay::GUIDisplay(GUIDisplay const &rhs)
{
	*this = rhs;
}

GUIDisplay &GUIDisplay::operator=(GUIDisplay const &other)
{
	isUser = other.isUser;
	isOs = other.isOs;
	isDate = other.isDate;
	isCPUInfo = other.isCPUInfo;
	isRAMInfo = other.isRAMInfo;
	isNetInfo = other.isNetInfo;
	isNetInter = other.isNetInter;
	isKatskiy = other.isKatskiy;
	_modules = other._modules;
	numCol = other.numCol;

	return *this;
}

void						GUIDisplay::allocateAll( void )
{
	if ( isUser )			_modules.push_back(new Name("1. User info", 2, 1));
	if ( isOs )		_modules.push_back(new OS("2. OS info", 5, 1));
	if ( isCPUInfo )			_modules.push_back(new CPU("4. CPU info", 7, 1));
	if ( isRAMInfo )			_modules.push_back(new RAM("5. RAM info", 9, 1));
	if ( isNetInfo )	_modules.push_back(new NetworkThro("6. Network info", 8, 1));
	if ( isNetInter )	_modules.push_back(new NetworkInfo("7. Network interfaces", 9, 1));
	SDL_SetWindowSize(_window, WIN_X, ACursesModule::make_y_frame);
}

void						GUIDisplay::deleteAll( void )
{
	for ( ; _modules.size(); )
	{
		delete _modules.front();
		_modules.erase(_modules.begin());
	}
}

void						GUIDisplay::reAllocate( void )
{
	this->deleteAll();
	this->allocateAll();
	SDL_RenderClear(_renderer);
}

void						GUIDisplay::refresh( void ) const
{
	for (	std::vector<int>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		_modules[i]->displaySDL();
	}
}

void	GUIDisplay::run(void)
{
	SDL_bool		done = SDL_FALSE;
	SDL_Event		event;
	clock_t			t1, t2;

	t2 = clock() / 50000;
	while (!done)
	{
		t1 = clock() / 50000;
		if (t1 > t2)
		{
			SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
			SDL_RenderClear(_renderer);
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					done = SDL_TRUE;
				if(event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_1)
							this->switchName();
					if (event.key.keysym.sym == SDLK_2)
						this->switchOSinfo();
					if (event.key.keysym.sym == SDLK_3)
						this->switchCPU();
					if (event.key.keysym.sym == SDLK_4)
						this->switchRAM();
					if (event.key.keysym.sym == SDLK_5)
						this->switchNetworkThro();
					if (event.key.keysym.sym == SDLK_6)
						this->switchNetworkInfo();
					if (event.key.keysym.sym == SDLK_ESCAPE)
						done = SDL_TRUE;
				}
			}
			this->refresh();
			SDL_RenderPresent(_renderer);
			t2 = clock() / 50000;
		}
	}
}

void	GUIDisplay::init(void)
{
	this->allocateAll();
	this->run();
}

void						GUIDisplay::switchName( void )
{
	isUser = !isUser;
	this->reAllocate();
}
void						GUIDisplay::switchOSinfo( void )
{
	isOs = !isOs;
	this->reAllocate();
}
void						GUIDisplay::switchTime( void )
{
	isDate = !isDate;
	this->reAllocate();
}
void						GUIDisplay::switchCPU( void )
{
	isCPUInfo = !isCPUInfo;
	this->reAllocate();
}
void						GUIDisplay::switchRAM( void )
{
	isRAMInfo = !isRAMInfo;
	this->reAllocate();
}
void						GUIDisplay::switchNetworkThro( void )
{
	isNetInfo = !isNetInfo;
	this->reAllocate();
}
void						GUIDisplay::switchNetworkInfo( void )
{
	isNetInter = !isNetInter;
	this->reAllocate();
}
void						GUIDisplay::switchCat( void )
{
	isKatskiy = !isKatskiy;
	this->reAllocate();
}

void						GUIDisplay::switchCols( int nbColums )
{
	numCol = nbColums;
	this->reAllocate();
}

SDL_Window *GUIDisplay::_window = 0;
SDL_Renderer *GUIDisplay::_renderer = 0;
TTF_Font *GUIDisplay::_font = 0;
SDL_Texture *GUIDisplay::_texture = 0;
SDL_Texture *GUIDisplay::_frame = 0;