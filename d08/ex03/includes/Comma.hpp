/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Comma.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:19:48 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 20:18:44 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMA_HPP
#define COMMA_HPP

#include <ICommands.hpp>

class Comma : public ICommands {

public:
	Comma( void );
	Comma( std::list<int>::iterator & );
	Comma( const Comma &toCopy );
	virtual ~Comma( void );

	Comma				&operator=( const Comma &toCopy );

	virtual void		exec( void );


private:
	std::list<int>::iterator	*_it;

};

#endif				// End of COMMA_HPP
