/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:12:37 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 16:12:39 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>

template < typename T >
int		easyfind( T & x, int y)
{
	typename T::iterator	it = std::find(x.begin(), x.end(), y);
	if (it != x.end())
			return *it;
	throw std::logic_error("No occurence found.");
}

#endif