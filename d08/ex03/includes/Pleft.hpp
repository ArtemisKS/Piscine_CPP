/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pleft.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:20:01 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 20:19:57 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLEFT_HPP
#define PLEFT_HPP

#include <ICommands.hpp>

class Pleft : public ICommands {

public:
	Pleft( void );
	Pleft( std::list<int> &, std::list<int>::iterator & );
	Pleft( const Pleft &toCopy );
	virtual ~Pleft( void );

	Pleft				&operator=( const Pleft &toCopy );

	virtual void		exec( void );

private:
	std::list<int>				*_st;
	std::list<int>::iterator	*_it;

};

#endif				// End of PLEFT_HPP
