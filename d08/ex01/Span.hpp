/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:13:06 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 18:44:16 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{

public:

	Span();
	Span(unsigned int n);
	Span(Span const &);
	~Span();
	Span &	operator=(Span const &);

	class LimitException : public std::exception
	{
		public:
			
			LimitException(void);
			LimitException(LimitException const &obj);
			virtual ~LimitException(void) throw();
			LimitException &operator=(LimitException const &r);
			virtual const char* what() const throw();
	};

	class NotEnoughValuesException : public std::exception
	{
		public:
			
			NotEnoughValuesException(void);
			NotEnoughValuesException(NotEnoughValuesException const &obj);
			virtual ~NotEnoughValuesException(void) throw();
			NotEnoughValuesException &operator=(NotEnoughValuesException const &r);
			virtual const char* what() const throw();
	};

	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();

private:	
	std::vector<int>	_v;
};

#endif