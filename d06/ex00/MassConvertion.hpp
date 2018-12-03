/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MassConvertion.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:25:37 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:18:35 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASSCONVERTION_HPP
#define MASSCONVERTION_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

class MassConvertion {

private:
	void						checkFloat( double toCheck ) const;

public:
	MassConvertion( void );
	MassConvertion( const MassConvertion & );
	~MassConvertion( void );

	MassConvertion			&operator=( const MassConvertion & );

	char					convToChar( double toConv );
	int						convToInt( double toConv );
	float					convToFloat( double toConv );
	double					convToDouble( double toConv );


	class nonDisplayable : std::exception {

	public:
		nonDisplayable( void );
		nonDisplayable( const nonDisplayable & );
		virtual ~nonDisplayable( void ) throw();

		nonDisplayable			&operator=( const nonDisplayable & );

		virtual const char		*what( void ) const throw();

	};

	class impossible : std::exception {

	public:
		impossible( void );
		impossible( const impossible & );
		virtual ~impossible( void ) throw();

		impossible				&operator=( const impossible & );

		virtual const char		*what( void ) const throw();

	};

};

#endif
