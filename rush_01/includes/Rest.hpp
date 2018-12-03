/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rest.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:30:30 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 23:30:51 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REST_HPP
#define REST_HPP

#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class Rest : public ACursesModule {

public:
	Rest( void );
	Rest( std::string, int);
	Rest( std::string, int, int);
	Rest( const Rest & );
	~Rest( void );

	Rest			&operator=( const Rest & );

	void			display( void ) const;

};

#endif