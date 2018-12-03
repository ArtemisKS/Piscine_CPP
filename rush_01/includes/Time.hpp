/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:50 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:00:40 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HPP
#define TIME_HPP
#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class Time : public ACursesModule {

public:
	Time( void );
	Time( std::string, int );
	Time( const Time & );
	~Time( void );

	Time			&operator=( const Time & );

	void			display( void ) const;
private:


};

#endif
