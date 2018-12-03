/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:12:56 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 19:16:00 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <random>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter a positive value greater than 0 (the size of our container)" << std::endl;
		return (0);
	}

	unsigned int i = atoi(av[1]);
	srand(time(0));

	if (i <= 0)
	{
		std::cout << "Please enter a positive value greater than 0" << std::endl;
		return (0);
	}

	Span test(i);
	unsigned int x = 0;
	int y = 0;

	std::cout << "Generated a storage vector size of " << i << std::endl <<
		"Now filling vector with values:" << std::endl;
	while (x < i)
	{
		y = rand() % 100000;
		test.addNumber(y);
		std::cout << "[" << y << "] ";
		if (x % 13 == 0)
			std::cout << std::endl;
		x++;
	}

	std::cout << std::endl << std::endl << "Total Iterations: " << x;

	try
	{
		std::cout << std::endl << std::endl << "Smallest span in storage: " << test.shortestSpan() << std::endl <<
		"Largest span in storage: " << test.longestSpan() << std::endl << std::endl <<
		"Now adding one more to show error handling" << std::endl;
	}
	catch (Span::NotEnoughValuesException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Not enough values to find any span." << std::endl;
	}

	try
	{
		test.addNumber(rand() % 10000);
	}
	catch (Span::LimitException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "WTF?" << std::endl;
	}

	return (0);
}

// int main()
// {
// 	Span sp = Span(5);

// 	try {
// 		sp.addNumber(5);
// 		sp.addNumber(3);
// 		sp.addNumber(17);
// 		sp.addNumber(9);
// 		sp.addNumber(11);
// 	}
// 	catch (std::overflow_error e) {

// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	Span sp2 = Span(15000);

// 	try {
// 		for (int i = 0; i < 15000; ++i)
// 		{
// 			sp2.addNumber(i * 10);
// 		}
// 	}
// 	catch (std::overflow_error e) {

// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << sp2.shortestSpan() << std::endl;
// 	std::cout << sp2.longestSpan() << std::endl;
	

// 	return 0;
// }