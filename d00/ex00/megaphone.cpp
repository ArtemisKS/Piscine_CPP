/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:57:23 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 00:47:05 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

int			main( int ac, char **av ) {

	int		length;

	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for ( size_t i = 1; i < ac; i++ ) {

		length = strlen(av[i]);
		for ( size_t g = 0; g < length; g++ ) {
			av[i][g] = toupper( av[i][g] );
		}
		std::cout << av[i];
	}
	std::cout << std::endl;

	return 0;

}