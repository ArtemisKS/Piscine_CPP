/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:26:08 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/11 19:29:41 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T, typename F >
void	iter( T *array, unsigned int length, F function)
{
	for (unsigned int i = 0; i < length; i++)
		function(array[i]);
}

void	print_int( int a ) { std::cout << "int " << a << std::endl; }
void	print_char( char c ) { std::cout << "char " << c << std::endl; }
void	set_number( int &a )
{
	static int counter = 1;
	std::cout << "Setting int to " << counter << std::endl;
	a = counter;
	counter++;
}

void	to_upper( char &c )
{
	std::cout << "toupper(" << c << ")"<< std::endl;
	c = toupper(c);
}

int main( void )
{
	int	array[5];
	iter(array, 5, set_number);
	iter(array, 5, print_int);

	char hello[] = "Hello world!";
	iter(hello, 12, to_upper);
	iter(hello, 12, print_char);
}
