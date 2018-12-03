/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:51 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:19:20 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
#define CPU_HPP

#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class CPU : public ACursesModule {

public:
	CPU( std::string, int );
	CPU( std::string, int, int);
	CPU( const CPU & );
	~CPU( void );

	CPU				&operator=( const CPU & );

	virtual void	display( void ) const;
	virtual void	displaySDL(void) const;
	virtual void	putText(char const *, int, int) const;

};

#endif
