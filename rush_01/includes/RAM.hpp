/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:45 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:53 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
#define RAM_HPP

#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class RAM : public ACursesModule {

public:
	RAM( void );
	RAM( std::string, int );
	RAM( std::string, int, int );
	RAM( const RAM & );
	~RAM( void );

	RAM			&operator=( const RAM & );

	void		display( void ) const;
	virtual void	displaySDL(void) const;
	virtual void	putText(char const *, int, int) const;

private:


};

#endif
