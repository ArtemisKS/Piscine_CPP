/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:25:40 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/11 21:19:37 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main( void )
{
	unsigned int i;

	Array<int> array = Array<int>(6);
	for (i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << "- change values -" << std::endl;
	std::cout << "array[2] = 4" << std::endl;
	array[2] = 4;
	std::cout << "array[3] = 2" << std::endl;
	array[3] = 2;
	std::cout << "array[6] = 1 ";
	try
	{
		array[6] = 1;
		std::cout << "OK" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "ERROR" << std::endl;
	}

	std::cout << "-- testing copying --" << std::endl;
	std::cout << "-- Copying through copy constructor --" << std::endl;
	Array<int> copy = Array<int>(array);
	for (i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
	std::cout << "- change values -" << std::endl;
	std::cout << "copy[3] = 1488" << std::endl;
	copy[3] = 1488;
	std::cout << "- initial array -" << std::endl;
	for (i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << "- copied and altered array -" << std::endl;
	for (i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;

	std::cout << "-- Copying through assignment --" << std::endl;
	copy = array;
	for (i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
	std::cout << "copy[3] = 1488" << std::endl;
	std::cout << "- change values -" << std::endl;
	copy[3] = 1488;
	std::cout << "- initial array -" << std::endl;
	for (i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << "- copied and altered array -" << std::endl;
	for (i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
}
