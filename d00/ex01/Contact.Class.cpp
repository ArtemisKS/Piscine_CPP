/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:54:12 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 00:42:24 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.Class.hpp"
#include "PhoneBook.hpp"


Contact::Contact(void) {
    return;
}

Contact::~Contact(void) {
    return;
}


void Contact::displayAllInfos() {

    std::cout << std::endl << this->firstName << std::endl << this->lastName
    << std::endl << this->nickName << std::endl << this->login << std::endl
    << this->postalAdress << std::endl << this->email << std::endl
    << this->phoneNumber << std::endl << this->birthDate << std::endl
    << this->favoriteMeal << std::endl << this->underwearColor << std::endl
    << this->darkestSecret;
}

void Contact::displayInfos(int i) {
    
    std::cout << "|" << std::right << i << std::setw(10) << "|"
    << std::left << std::setw(10) << cropName(this->firstName)
    << "|" << std::left << std::setw(10) << cropName(this->lastName)
    << "|" << std::left << std::setw(10) << cropName(nickName) << "|"
    << std::endl;
}

std::string Contact::cropName( std::string str )
{
    if (str.length() > 10) {
		str.resize(9);
		str.resize(10, '.');
	}
    return (str);
}

void Contact::add(std::string *details) {
    this->firstName = details[0];
    this->lastName = details[1];
    this->nickName = details[2];
    this->login = details[3];
    this->postalAdress = details[4];
    this->email = details[5];
    this->phoneNumber = details[6];
    this->birthDate = details[7];
    this->favoriteMeal = details[8];
    this->underwearColor = details[9];
    this->darkestSecret = details[10];
    Contact::nbContacts += 1;
    return;
}

int Contact::getNbContacts(void) {
    return Contact::nbContacts;
}

int Contact::nbContacts = 0;
