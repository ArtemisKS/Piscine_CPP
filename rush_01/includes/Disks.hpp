/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disks.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:19 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 23:00:23 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISKS_HPP
#define DISKS_HPP

#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class Disks : public ACursesModule {

public:
	Disks( void );
	Disks( std::string, int);
	Disks( std::string, int, int);
	Disks( const Disks & );
	~Disks( void );

	Disks			&operator=( const Disks & );

	void			display( void ) const;

};

#endif
