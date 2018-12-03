/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:29:48 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:29:50 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	memoryLeak( void )
{
	std::string*		panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;

	delete panthere;
}

int		main( void )
{
	memoryLeak();

	system("leaks -q a.out");
	return 0;
}
