/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:19:51 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 20:19:21 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOT_HPP
#define DOT_HPP

#include <ICommands.hpp>

class Dot : public ICommands {

public:
	Dot( void );
	Dot( std::list<int>::iterator & );
	Dot( const Dot &toCopy );
	virtual ~Dot( void );

	Dot					&operator=( const Dot &toCopy );

	virtual void		exec( void );

private:
	std::list<int>::iterator	*_it;

};

#endif				// End of DOT_HPP
