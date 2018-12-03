/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:31:12 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:31:13 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main( void )
{
	const std::string	brain("HI THIS IS BRAIN");
	const std::string*	brainPtr = &brain;
	const std::string&	brainRef = brain;

	std::cout << "Display string via pointer: " << *brainPtr << std::endl;
	std::cout << "Display string via reference: " << brainRef << std::endl;

	return 0;
}