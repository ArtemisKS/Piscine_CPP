/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICommands.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:19:53 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 20:19:33 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

#include <list>
#include <queue>
#include <string>
#include <iostream>

class ICommands {

public:
	virtual ~ICommands( void ) {}

	virtual void	exec( void ) = 0;

};

#endif				// End of ICOMMAND_HPP
