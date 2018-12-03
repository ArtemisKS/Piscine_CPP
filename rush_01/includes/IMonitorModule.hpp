/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:08 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:33 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>
#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule {

public:
	virtual ~IMonitorModule( void ) { return ; };

	virtual void			display( void ) const = 0;
	virtual void			displaySDL( void ) const = 0;
protected:

};

#endif
