/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACursesModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:28 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 23:14:02 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACURSESMODULE_HPP
# define ACURSESMODULE_HPP

# include <IMonitorModule.hpp>

class ACursesModule : public virtual IMonitorModule {

public:
	ACursesModule( void );
	ACursesModule( std::string &, int );
	ACursesModule( std::string &, int, int); // SDL[GUI]
	ACursesModule( const ACursesModule & );
	virtual ~ACursesModule( void );

	ACursesModule			&operator=( const ACursesModule & );

	void					refresh( void ) const;
	virtual void			display( void ) const;
	virtual void			displaySDL( void ) const;
	
	WINDOW					*getWin( void ) const;

	static int			make_y_frame;
	static int			make_x_frame;

protected:
	WINDOW				*_w;
	std::string			motto;
	int					numCol;
	int					*init_y;
	int					*init_x;
	static const int	bordLayer = 1;
	static const int	_winStStr = 3;
	static const int	size_y = 20;
	static const int	size_x = 60;

	void				init( void );
	void				decInitYX( void );

	int					alignCenter( const std::string & ) const;
	int					alignCenter( const int ) const;
	int					alignRight( const std::string &str ) const;
	int					alignRight( const int slen ) const;

	void				refBord( void ) const;
	void				clearLine( int ) const;
	void				clearWindow( void ) const;


	//GUI
	static const int	s_y_sdl = 30;
	static int			initial_x;
	static int			initial_y;
	int					frame_x;
	int					frame_y;
	int					_x;
	int					_y;
	int 				_mode;
	
	void				initGUI(void);

};

#endif
