/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:34:44 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:34:45 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int		main( void )
{
	Logger	L("file.log");

	L.log("logToConsole", "asd");
	L.log("logToFile", "asd");

	return 0;
}
