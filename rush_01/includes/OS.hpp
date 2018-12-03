/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:40 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:49 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_HPP
#define OS_HPP
#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class OS : public ACursesModule {

public:
	OS( void );
	OS( std::string, int );
	OS( std::string, int, int);
	OS( const OS & );
	~OS( void );

	OS			&operator=( const OS & );

	void			display( void ) const;
	virtual void	displaySDL(void) const;
	virtual void	putText(char const *, int, int) const;


private:


};

#endif
