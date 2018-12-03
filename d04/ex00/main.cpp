/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:25:08 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 23:00:59 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include <iostream>

int	main()
{
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");
		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}
	{
		Sorcerer merlin("Merlin", "the White Beard");
		Victim* victim = new Victim("Bella");
		Victim* peon = new Peon("Mike");

		std::cout << merlin << *victim << *peon;

		merlin.polymorph(*victim);
		merlin.polymorph(*peon);

		delete peon;
		delete victim;
	}
	return (0);
}
