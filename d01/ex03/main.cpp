/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:30:38 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/03 21:12:54 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int		main( void )
{
	ZombieHorde		horde(10);

	horde.announce();

	system("leaks -q a.out");
	return 0;
}
