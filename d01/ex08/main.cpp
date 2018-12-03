/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:34:26 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:34:28 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main( void )
{
	Human	H;

	H.action("asd", "people");
	H.action("asdsaasfasd", "people");
	H.action("asdsfghfgdhfg", "people");
	H.action("meleeAttack", "baby");
	H.action("intimidatingShout", "boy");
	H.action("rangedAttack", "girl");
	H.action("", "people");

	return 0;
}
