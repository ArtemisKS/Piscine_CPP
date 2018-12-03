/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:25:51 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/10 21:47:11 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <ctime>

struct Data 
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void			*serialize( void )
{
	char			*d = new char[20];
	const char		alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	const std::size_t	l = strlen(alphanum);
	int					i = 0;

	while ( i < 8 ) {
		d[i++] = alphanum[rand() % l];
	}
	while ( i < 12 ) {
		d[i++] = rand() % std::numeric_limits<unsigned char>::max();
	}
	while ( i < 20 ) {
		d[i++] = alphanum[rand() % l];
	}
	return reinterpret_cast<void *>(d);
}

Data			*deserialize( void *raw )
{
	Data	*d = new Data();
	char	*r = reinterpret_cast<char *>(raw);
	int		i = 0;

	while ( i < 8 ) {
		d->s1 += r[i++];
	}
	d->n = 0;
	while ( i < 12 ) {
		d->n <<= 8;
		d->n |= r[i++];
	}
	while ( i < 20 ) {
		d->s2 += r[i++];
	}
	return d;
}

int				main( void )
{
	Data		*d;

	srand(time(NULL));
	for ( int i = 0; i < 4; i++ ) {
		d = deserialize( serialize() );
		std::cout << d->s1 << std::endl;
		std::cout << d->n << std::endl;
		std::cout << d->s2 << std::endl;
		std::cout << std::endl;
	}
}
