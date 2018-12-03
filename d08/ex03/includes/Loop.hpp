/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:19:56 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 20:31:11 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HPP
#define LOOP_HPP

#include <ICommands.hpp>

class Loop : public ICommands {

public:
	Loop( void );
	Loop( std::list<int> &, std::list<int>::iterator &, std::string::iterator &, std::string::iterator & );
	Loop( const Loop &toCopy );
	virtual ~Loop( void );

	Loop			&operator=( const Loop &toCopy );

	virtual void	exec( void );

private:
	std::list<int>				*_st;
	std::list<int>::iterator	*_it;
	std::string					_raw;

};

void				parseRaw( std::list<int> &, std::list<int>::iterator &,
	std::queue<ICommands*> &, std::string & );
void				execQueue( std::queue<ICommands*> &Q );

#endif				// End of LOOP_HPP
