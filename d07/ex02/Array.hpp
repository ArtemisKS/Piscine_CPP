/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:25:48 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/10 23:26:27 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class Array
{
public:
	Array<T>( void ): _size(0)
	{
		this->_array = 0;
	}

	Array<T>( unsigned int size ): _size(size)
	{
		this->_array = new T[size]();
	}

	Array<T>( Array<T> const &copy )
	{
		this->_size = copy.size();
		this->_array = new T[copy.size()]();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = copy[i];
	}

	Array<T> operator=( Array<T> const &copy )
	{
		this->_size = copy.size();
		this->_array = new T[copy.size()]();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = copy[i];
		return *this;
	}

	T &operator[]( unsigned int index ) const
	{
		if (index >= this->_size)
			throw std::exception();
		return this->_array[index];
	}

	unsigned int size( void ) const { return this->_size; }

private:
	T				*_array;
	unsigned int	_size;
};

#endif
