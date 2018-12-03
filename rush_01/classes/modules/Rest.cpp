/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rest.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:29:33 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 23:39:29 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Rest.hpp>

Rest::Rest( void )
{
	return ;
}
Rest::Rest( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
Rest::Rest( std::string a, int b, int c) : ACursesModule(a, b, c)
{
	return ;
}
Rest::Rest( const Rest &toCopy )
{
	*this = toCopy;
}
Rest::~Rest( void )
{
	return ;
}

Rest			&Rest::operator=( const Rest &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}

void			Rest::display( void ) const
{
	const std::string		disk1 = strExec("top -l 1 | head -n 7 | tail -n 3 | head -n 1");
	const std::string		disk2 = strExec("top -l 1 | head -n 7 | tail -n 3 | head -n 2 | tail -n 1");
	const std::string		disk3 = strExec("top -l 1 | head -n 7 | tail -n 3 | tail -n 1");
	int						y = _winStStr;

	mvwprintw(this->_w, y++, 1, "%s", disk1.c_str());
	mvwprintw(this->_w, y++, 1, "%s", disk2.c_str());
	mvwprintw(this->_w, y++, 1, "%s", disk3.c_str());
	this->refresh();
}
