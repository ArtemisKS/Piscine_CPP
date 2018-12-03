/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:13:01 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 19:05:39 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <numeric>

#include <iostream>

Span::Span() {
	_v.reserve(0);
}

Span::Span( unsigned int n ) {

	_v.reserve(n);
}

Span::Span( Span const & src ) {

	*this = src;
}

Span::~Span() {}

Span &	Span::operator=( Span const & rhs ) {

	this->_v = rhs._v;
	return *this;
}

void	Span::addNumber( int n ) {

	if ( this->_v.size() < this->_v.capacity() )
		this->_v.push_back(n);
	else
		throw std::overflow_error("Error : container is full.");
}

void displayInt(int i) {
	std::cout << i << std::endl;
}

int	Span::shortestSpan() {

	std::vector<int> 	cpy = _v;

    std::sort(cpy.begin(), cpy.end());
	std::adjacent_difference(cpy.begin(), cpy.end(), cpy.begin() - 1);
	cpy.pop_back();
    return (cpy[std::distance(cpy.begin(), std::min_element(cpy.begin(), cpy.end()))]);
}

int	Span::longestSpan() {

	std::vector<int>::iterator	min = std::min_element(_v.begin(), _v.end());
	std::vector<int>::iterator	max = std::max_element(_v.begin(), _v.end());

	return (_v[std::distance(_v.begin(), max)] - _v[std::distance(_v.begin(), min)]);
}

Span::LimitException::LimitException(void)
{
	return;
}

Span::LimitException::LimitException(LimitException const &obj)
{
	*this = obj;
	return;
}

Span::LimitException::~LimitException(void) throw()
{
	return;
}

Span::LimitException &Span::LimitException::operator=(LimitException const &r) 
{
	(void)r;
	return (*this);
}

const char* Span::LimitException::what() const throw()
{
	return ("Error: capacity is full.");
}



/*
** NotEnoughValuesException Nested Class
*/

Span::NotEnoughValuesException::NotEnoughValuesException(void)
{
	return;
}

Span::NotEnoughValuesException::NotEnoughValuesException(NotEnoughValuesException const &obj)
{
	*this = obj;
	return;
}

Span::NotEnoughValuesException::~NotEnoughValuesException(void) throw()
{
	return;
}

Span::NotEnoughValuesException &Span::NotEnoughValuesException::operator=(NotEnoughValuesException const &r) 
{
	(void)r;
	return (*this);
}

const char* Span::NotEnoughValuesException::what() const throw()
{
	return ("Error: too little values in storage to determine span");
}
