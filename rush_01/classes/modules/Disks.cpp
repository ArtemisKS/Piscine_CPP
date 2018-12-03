/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disks.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:51:44 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 23:25:09 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Disks.hpp>

Disks::Disks( void )
{
	return ;
}
Disks::Disks( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
Disks::Disks( std::string a, int b, int c) : ACursesModule(a, b, c)
{
	return ;
}
Disks::Disks( const Disks &toCopy )
{
	*this = toCopy;
}
Disks::~Disks( void )
{
	return ;
}

Disks			&Disks::operator=( const Disks &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}

void			Disks::display( void ) const
{
	const std::string		disk1 = strExec("df -h | tail -n 3 | head -n 1 | awk '{print $1\"  \"$2\"  \"$3\"  \"$4\"  \"$5\"  \"$9;}'");
	const std::string		disk2 = strExec("df -h | tail -n 2 | head -n 1 | awk '{print $1\"  \"$2\"  \"$3\"  \"$4\"  \"$5\"  \"$9;}'");
	const std::string		disk3 = strExec("df -h | tail -n 1 | awk '{print $1\"  \"$2\"  \"$3\"  \"$4\"  \"$5\"  \"$9;}'");
	int						y = _winStStr;

	mvwprintw(this->_w, y++, 1, "%s", disk1.c_str());
	mvwprintw(this->_w, y++, 1, "%s", disk2.c_str());
	mvwprintw(this->_w, y++, 1, "%s", disk3.c_str());
	this->refresh();
}
