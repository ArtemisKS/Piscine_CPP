/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MassConvertion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:25:31 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/09 19:25:33 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MassConvertion.hpp>

MassConvertion::MassConvertion( void )
{
	return ;
}

MassConvertion::MassConvertion( const MassConvertion &toCopy )
{
	*this = toCopy;
}

MassConvertion::~MassConvertion( void )
{
	return ;
}

MassConvertion				&MassConvertion::operator=( const MassConvertion &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}



void						MassConvertion::checkFloat( double toCheck ) const
{
	const int		classification = fpclassify(toCheck);

	if (	classification == FP_SUBNORMAL ||
			classification == FP_INFINITE ||
			classification == FP_NAN )
	{
		throw MassConvertion::impossible();
	}
}
char						MassConvertion::convToChar( double toConv )
{
	if ( toConv > static_cast<double>(CHAR_MAX) || toConv < static_cast<double>(CHAR_MIN) ) {
		throw MassConvertion::impossible();
	}
	char c = static_cast<char>(toConv);
	if ( !isprint(c) ) {
		throw MassConvertion::nonDisplayable();
	}

	return c;
}
int							MassConvertion::convToInt( double toConv )
{
	if ( toConv > static_cast<double>(INT_MAX) || toConv < static_cast<double>(INT_MIN) ) {
		throw MassConvertion::impossible();
	}

	return static_cast<int>(toConv);
}
float						MassConvertion::convToFloat( double toConv )
{
	float f = static_cast<float>(toConv);
	checkFloat(toConv);

	return f;
}
double						MassConvertion::convToDouble( double toConv )
{
	double d = static_cast<double>(toConv);
	checkFloat(toConv);

	return d;
}



MassConvertion::nonDisplayable::nonDisplayable( void )
{
	return ;
}
MassConvertion::nonDisplayable::nonDisplayable( const nonDisplayable &toCopy )
{
	*this = toCopy;
}
MassConvertion::nonDisplayable::~nonDisplayable( void ) throw()
{
	return ;
}
MassConvertion::nonDisplayable		&MassConvertion::nonDisplayable::operator=( const nonDisplayable &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}
const char					*MassConvertion::nonDisplayable::what( void ) const throw()
{
	return "Non displayable";
}



MassConvertion::impossible::impossible( void )
{
	return ;
}
MassConvertion::impossible::impossible( const impossible &toCopy )
{
	*this = toCopy;
}
MassConvertion::impossible::~impossible( void ) throw()
{
	return ;
}
MassConvertion::impossible		&MassConvertion::impossible::operator=( const impossible &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}
const char					*MassConvertion::impossible::what( void ) const throw()
{
	return "impossible";
}
