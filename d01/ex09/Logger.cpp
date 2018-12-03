/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:34:33 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:34:34 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger( std::string const & fileName ) : _fs(fileName, std::ios::app)
{
	return ;
}

Logger::~Logger( void )
{
	return ;
}


const std::string	Logger::makeLogEntry( std::string const & rudeLog ) const
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char		buffer[25];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime (buffer, 25, "[%Y%m%d_%H%M%S] ", timeinfo);

	std::string	log(buffer);
	log += rudeLog;
	return log;
}

void				Logger::logToConsole( std::string const & log )
{
	std::cout << log << std::endl;
}

void				Logger::logToFile( std::string const & log )
{
	Logger::_fs << log << std::endl;
}



void				Logger::log(std::string const & dest, std::string const & message)
{
	void		(Logger::*p[2])( std::string const & ) = {
		&Logger::logToConsole,
		&Logger::logToFile
	};
	std::string	s[2] = {
		"logToConsole",
		"logToFile"
	};

	for ( int i = 0; i < 2; i++ ) {
		if ( s[i] == dest ) {
			(this->*p[i])( this->makeLogEntry(message) );
			break ;
		}
	}
}
