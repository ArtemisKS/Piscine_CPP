/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:25 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:42 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKINFO_HPP
#define NETWORKINFO_HPP
#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class NetworkInfo : public ACursesModule {

public:
	NetworkInfo( void );
	NetworkInfo( std::string, int );
	NetworkInfo( std::string, int, int);
	NetworkInfo( const NetworkInfo & );
	~NetworkInfo( void );

	NetworkInfo			&operator=( const NetworkInfo & );

	void				display( void ) const;
	virtual void	displaySDL(void) const;
	virtual void	putText(char const *, int, int) const;

private:


};

#endif
