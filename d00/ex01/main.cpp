/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:54:48 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 09:29:46 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.Class.hpp"
#include "PhoneBook.hpp"

int     main()
{
	std::string input;
	Contact contacts[8];

	while (std::cin) {
		std::cout << "Your INPUT, por favor: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			return 1;
		else if (input == "SEARCH")
			search(contacts);
		else if (input == "ADD")
			add(contacts);
	}
	(std::operator<<(std::cout, "^D")).operator<<(std::endl);
	return 0;
}

