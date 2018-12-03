/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:54:19 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 00:37:41 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_Class_H
# define Contact_Class_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>


class Contact {
public:
    Contact(void);

    ~Contact(void);

    void add(std::string *);
    void displayInfos(int i);
    void displayAllInfos(void);
    std::string cropName(std::string);
    static int getNbContacts(void);

private:

    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string login;
    std::string postalAdress;
    std::string email;
    std::string phoneNumber;
    std::string birthDate;
    std::string favoriteMeal;
    std::string underwearColor;
    std::string darkestSecret;
    static int nbContacts;
};

#endif