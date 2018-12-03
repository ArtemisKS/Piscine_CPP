/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unicat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:17:43 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:17:44 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Unicat.hpp>

Unicat::Unicat( void ) : _katskiy()
{
	katskiyInit();
}
Unicat::Unicat( std::string a, int b ) : ACursesModule(a, b), _katskiy()
{
	katskiyInit();
}
Unicat::Unicat( const Unicat &toCopy )
{
	*this = toCopy;
}
Unicat::~Unicat( void )
{
	return ;
}
Unicat			&Unicat::operator=( const Unicat &toCopy )
{
	ACursesModule::operator=(toCopy);
	_katskiy = toCopy._katskiy;

	return *this;
}


void		Unicat::katskiyInit( void )
{
	_katskiy.push_back("     ,     ,\n");
	_katskiy.push_back("     |\\.\"./|\n");
	_katskiy.push_back("    /       \\\n");
	_katskiy.push_back("   /  _   _  \\   ______\n");
	_katskiy.push_back("   \\==  Y  ==/\"'`      `.\n");
	_katskiy.push_back("   /`-._^_.-'\\     ,-  . \\\n");
	_katskiy.push_back("  /     `     \\   /     \\ \\\n");
	_katskiy.push_back("  \\  \\.___./  /_ _\\     / /\n");
	_katskiy.push_back("   `, \\   / ,'  (,-----' /\n");
	_katskiy.push_back("     \"\"' '\"\"     '------'");
	_katskiy.push_back("     ,     ,\n");
	_katskiy.push_back("     |\\.\"./|\n");
	_katskiy.push_back("    / _   _ \\\n");
	_katskiy.push_back("   / {|} {|} \\   ______\n");
	_katskiy.push_back("   \\==  Y  ==/\"'`      `.\n");
	_katskiy.push_back("   /`-._^_.-'\\     ,-  . \\\n");
	_katskiy.push_back("  /     `     \\   /     \\ \\\n");
	_katskiy.push_back("  \\  \\.___./  /_ _\\     / /\n");
	_katskiy.push_back("   `, \\   / ,'  (,-----' / \n");
	_katskiy.push_back("     \"\"' '\"\"     '------' ");
}
void		Unicat::display( void ) const
{
	int					y = _winStStr + 1;

	static const std::vector<std::string>::size_type	part = _katskiy.size() / 2;
	static std::vector<std::string>::size_type			start = 0;
	static std::vector<std::string>::size_type			end = part;

	for (	std::vector<std::string>::size_type i = start;
			i < end;
			i++ )
	{	
		clearLine(y);
		mvwprintw(this->_w, y++, 1, "%s", _katskiy[i].c_str());
	}

	if ( end != _katskiy.size() ) {
		start += part;
		end += part;
	}
	else {
		start = 0;
		end = part;
	}

	this->refresh();
}
