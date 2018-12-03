/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:54:58 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/01 21:57:10 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_H
# define PhoneBook_H

#include <iostream>
#include "Contact.Class.hpp"

void formatOutput(std::string str);

void search(Contact *contacts);

void add(Contact *contact);

#endif