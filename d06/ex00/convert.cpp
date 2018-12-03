/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:25:20 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/09 19:25:21 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MassConvertion.hpp>

void			printChar( MassConvertion &m, double d )
{
	try {
		std::cout << "char: ";
		const char		c = m.convToChar(d);
		std::cout << "'" << c << "'" << std::endl;
	}
	catch ( MassConvertion::impossible &e ) {
		std::cout << e.what() << std::endl;
	}
	catch ( MassConvertion::nonDisplayable &e ) {
		std::cout << e.what() << std::endl;
	}
}

void			printInt( MassConvertion &m, double d )
{
	try {
		std::cout << "int: ";
		std::cout << m.convToInt(d) << std::endl;
	}
	catch ( MassConvertion::impossible &e ) {
		std::cout <<  e.what() << std::endl;
	}
}

void			printFloat( MassConvertion &m, double d, int precision )
{
	try {
		std::cout << "float: ";
		std::cout << std::setprecision(precision) << std::fixed << m.convToFloat(d) << "f" << std::endl;
	}
	catch ( MassConvertion::impossible &e ) {
		std::cout << d << "f" << std::endl;
	}
}

void			printDouble( MassConvertion &m, double d, int precision )
{
	try {
		std::cout << "double: ";
		std::cout << std::setprecision(precision) << std::fixed << m.convToDouble(d) << std::endl;
	}
	catch ( MassConvertion::impossible &e ) {
		std::cout << d << std::endl;
	}
}

int				checkPrecision( double d, bool isFloat )
{
	int					decimal_places = 0;
	static const int	mantissa = \
	( isFloat ) ? std::numeric_limits<float>::digits10 : std::numeric_limits<double>::digits10;

	do {
		d *= 10;
		decimal_places++;
	} while ( decimal_places < mantissa && d != static_cast<long long>(d) );

	return decimal_places;
}

int				main( int ac, char **av )
{
	if ( ac != 2 || !strlen(av[1]) ) {
		std::cerr << "Some error occurred: not valid arguments" << std::endl;
		std::cerr << "usage: ./convert <string_that_reprethens_the_value_to_convert>" << std::endl;
		return 1;
	}

	MassConvertion	m;
	double			d;
	int				precision;

	d = atof(av[1]);
	printChar(m, d);
	printInt(m, d);
	precision = checkPrecision(d, true);
	printFloat(m, d, precision);
	precision = checkPrecision(d, false);
	printDouble(m, d, precision);

	return 0;
}
