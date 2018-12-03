/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIDisplay.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:49:42 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/14 23:36:16 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIDISPLAY_HPP
# define GUIDISPLAY_HPP
#include <IMonitorDisplay.hpp>
#include <Name.hpp>
#include <OS.hpp>
#include <CPU.hpp>
#include <RAM.hpp>
#include <NetworkInfo.hpp>
#include <NetworkThro.hpp>
#include <Unicat.hpp>

class	GUIDisplay : public IMonitorDisplay
{
	public:
		GUIDisplay(SDL_Window *window, SDL_Renderer *renderer);
		virtual ~GUIDisplay(void);
		GUIDisplay(GUIDisplay const &rhs);
		GUIDisplay &operator=(GUIDisplay const &rhs);
		void	run(void);
		static SDL_Window *_window;
		static SDL_Renderer *_renderer;
		static TTF_Font *_font;
		static SDL_Texture *_texture;
		static SDL_Texture *_frame;
	protected:
		bool		isUser;
		bool		isOs;
		bool		isDate;
		bool		isCPUInfo;
		bool		isRAMInfo;
		bool		isNetInfo;
		bool		isNetInter;
		bool		isKatskiy;

		std::vector<IMonitorModule*>	_modules;
		int			numCol;
		
		virtual void					allocateAll( void );
		virtual void					deleteAll( void );
		virtual void					reAllocate( void );

		virtual void					switchTime( void );
		virtual void					switchName( void );
		virtual void					switchOSinfo( void );
		virtual void					switchCPU( void );
		virtual void					switchRAM( void );
		virtual void					switchNetworkThro( void );
		virtual void					switchNetworkInfo( void );
		virtual void					switchCat( void );
		virtual void					switchCols( int );

		virtual void					refresh( void ) const;
		virtual void					init( void );
	private:
		GUIDisplay(void);
};

#endif

