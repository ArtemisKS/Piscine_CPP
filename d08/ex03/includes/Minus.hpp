/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minus.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:19:58 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 20:19:49 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINUS_HPP
#define MINUS_HPP

#include <ICommands.hpp>

class Minus : public ICommands {

public:
	Minus( void );
	Minus( std::list<int>::iterator & );
	Minus( const Minus &toCopy );
	virtual ~Minus( void );

	Minus				&operator=( const Minus &toCopy );

	virtual void		exec( void );

private:
	std::list<int>::iterator	*_it;

};

#endif				// End of MINUS_HPP
