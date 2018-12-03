/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:09:01 by akupriia          #+#    #+#             */
/*   Updated: 2018/06/22 22:09:08 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist( void );
	PowerFist( PowerFist const & weapon );
	virtual ~PowerFist( void );
	PowerFist&operator=( PowerFist const & weapon );

	virtual void	attack( void ) const;
};


#endif