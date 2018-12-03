/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:04:53 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:05:00 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
public:
	Enemy( int hp, std::string const & type );
	Enemy( Enemy const & enemy );
	Enemy( void );
	virtual ~Enemy( void );

	Enemy	& operator=( Enemy const & enemy );

	std::string		getType( void ) const;
	int				getHP( void ) const;
	virtual void	takeDamage( int damage );

protected:
	int				_hp;
	std::string		_type;
};


#endif
