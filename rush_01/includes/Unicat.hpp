/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unicat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:17:52 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:17:58 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <ACursesModule.hpp>

class Unicat : public ACursesModule {

public:
	Unicat( void );
	Unicat( std::string, int );
	Unicat( const Unicat & );
	~Unicat( void );

	Unicat			&operator=( const Unicat & );

	void		display( void ) const;

private:
	std::vector<std::string>		_katskiy;

	void				katskiyInit( void );

};

#endif
