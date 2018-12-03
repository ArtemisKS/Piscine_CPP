/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:54:16 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 19:26:40 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

std::vector<std::string>		ft_explode( const std::string &s, const char delim )
{
	std::vector<std::string>	result;
	std::istringstream			iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		if ( !token.empty() )	result.push_back( ft_trim(token) );
	}

	return result;
}

std::string						&ft_trim( std::string &s )
{
	std::string::iterator	it;

	for ( it = s.begin(); it != s.end() && isspace(*it); it++ );
	s.erase(s.begin(), it);

	for ( it = s.end(); it != s.begin() && isspace(*it); it-- );
	s.erase(it, s.end());

	return s;
}

std::string		exec( const char *cmd )
{
	char			buffer[BUFF_SIZE];
	std::string		result = "";
	FILE*			pipe = popen(cmd, "r");

	if ( !pipe ) throw std::runtime_error("popen() failed!");
	try {
		while (!feof(pipe)) {
			if (fgets(buffer, BUFF_SIZE, pipe) != NULL)
				result += buffer;
		}
	}
	catch (...) {
		pclose(pipe);
		throw;
	}
	pclose(pipe);
	return result;
}

std::string		strExec( const char *cmd )
{
	std::string		result = "";

	try {
		result = exec(cmd);
	}
	catch(...) {
		result = "ERROR";
	}
	return result;
}
