/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThro.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:33 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:45 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKTHRO_HPP
#define NETWORKTHRO_HPP
#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class NetworkThro : public ACursesModule {

public:
	NetworkThro( void );
	NetworkThro( std::string, int );
	NetworkThro( std::string, int , int);
	NetworkThro( const NetworkThro & );
	~NetworkThro( void );

	NetworkThro		&operator=( const NetworkThro & );

	void			display( void ) const;
	virtual void	displaySDL(void) const;
	virtual void	putText(char const *, int, int) const;

private:


};

#endif
