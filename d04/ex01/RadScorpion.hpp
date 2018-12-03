/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:09:46 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:09:47 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion( void );
	RadScorpion( RadScorpion const & enemy );
	virtual ~RadScorpion( void );

	RadScorpion&operator=( RadScorpion const & enemy );
};

#endif
