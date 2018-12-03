/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:54:55 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 00:42:39 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdlib.h>

void formatOutput(std::string str) {

    int i = -1;

    while (++i < 10)
    {
        if (str[i])
            (i < 9) ? std::cout <<  str[i] : std::cout <<  ".";
        else
            std::cout << " ";
    }
}

void add(Contact *contact) {

    std::string details[11];
    if (contact->getNbContacts() > 7){
		std::cout << "There are no space left on the device for another contact!" \
		<< std::endl;
		return ;
	}
    else {
        std::cout << "Enter the contact's first name: ";
        std::getline(std::cin, details[0]);
        std::cout << "Enter the contact's last name: ";
        std::getline(std::cin, details[1]);
        std::cout << "Enter the contact's nickname: ";
        std::getline(std::cin, details[2]);
        std::cout << "Enter the contact's login: ";
        std::getline(std::cin, details[3]);
        std::cout << "Enter the contact's postal address: ";
        std::getline(std::cin, details[4]);
        std::cout << "Enter the contact's email address: ";
        std::getline(std::cin, details[5]);
        std::cout << "Enter the contact's phone number: ";
        std::getline(std::cin, details[6]);
        std::cout << "Enter the contact's birthday date: ";
        std::getline(std::cin, details[7]);
        std::cout << "Enter the contact's favorite meal: ";
        std::getline(std::cin, details[8]);
        std::cout << "Enter the contact's underwear color: ";
        std::getline(std::cin, details[9]);
        std::cout << "Enter the contact's darkest secret: ";
        std::getline(std::cin, details[10]);
        contact[contact->getNbContacts()].add(details);
        std::cout << "Contact saved" << std::endl;
    }
    std::cout << std::endl;
}

void search(Contact *contacts) {

    int i = 0;
    std::string input;
    int index = -1;

    if (i < contacts[0].getNbContacts()) {
       std::cout << "|" << std::left << std::setw(10) << "Index" << "|"
	   << std::left << std::setw(10) << "First name" << "|"
	   << std::left << std::setw(10) << "Last name" << "|"
	   << std::left << std::setw(10) << "Nickname" << "|" << std::endl;
        while (i < contacts[0].getNbContacts()) {
            contacts[i].displayInfos(i);
            i++;
        }
        std::cout << "Which entry do you want ? ";
        std::getline(std::cin, input);
        if (input.length() == 1)
            index = atoi(input.data());
        else
            std::cout << "Please, input entry from 0 to 7" << std::endl;
        if (index >= 0 and index < contacts[0].getNbContacts())
            contacts[index].displayAllInfos();
        else
            std::cout << "Sorry, this entry does not exist";
        std::cout << std::endl;
    }
    else {
        std::cout << "No entry" << std::endl;
    }
    return;
}
