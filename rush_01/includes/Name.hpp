/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:19 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:37 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_HPP
#define NAME_HPP

#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class Name : public ACursesModule {

public:
	Name( void );
	Name( std::string, int);
	Name( std::string, int, int);
	Name( const Name & );
	~Name( void );

	Name			&operator=( const Name & );

	virtual void			display( void ) const;
	virtual void			displaySDL(void) const;
	virtual void			putText(char *, int, int) const;

private:


};

#endif
