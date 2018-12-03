/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:10:28 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:10:33 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant( void );
	SuperMutant( SuperMutant const & enemy );
	virtual ~SuperMutant( void );

	SuperMutant	& operator=( SuperMutant const & enemy );
	virtual void takeDamage( int damage );
};

#endif
