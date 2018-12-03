/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:27:41 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:27:42 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Pony.hpp"
#include <iostream>
#include <cstdlib>

static void	ponyOnTheHeap( void )
{
	const Pony*	Karl = new Pony(true);

	std::cout << "Karl is " << (Karl->isUnicorn ? "unicorn" : "pony") << std::endl;

	delete Karl;
}

static void	ponyOnTheStack( void )
{
	const Pony	Piter;

	std::cout << "Piter is " << (Piter.isUnicorn ? "unicorn" : "pony") << std::endl;
}

int		main( void )
{
	ponyOnTheHeap();
	ponyOnTheStack();

	system("leaks -q a.out");
	return 0;
}
