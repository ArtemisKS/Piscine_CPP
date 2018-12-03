/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:03 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:29 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include <main.hpp>

class IMonitorDisplay {

public:
	virtual ~IMonitorDisplay( void ) { return ; };

protected:
	virtual void					refresh( void ) const = 0;
	virtual void					init( void ) = 0;

	/* Module switchers */
	virtual void					switchName( void ) = 0;
	virtual void					switchOSinfo( void ) = 0;
	virtual void					switchTime( void ) = 0;
	virtual void					switchCPU( void ) = 0;
	virtual void					switchRAM( void ) = 0;
	virtual void					switchNetworkThro( void ) = 0;
	virtual void					switchNetworkInfo( void ) = 0;
	virtual void					switchCat( void ) = 0;
	virtual void					switchCols( int ) = 0;

};

#endif
