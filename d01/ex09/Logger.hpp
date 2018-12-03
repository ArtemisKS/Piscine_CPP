/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:34:38 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/02 21:34:39 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>

class Logger {

public:
	Logger( std::string const & fileName );
	~Logger( void );

	void				log(std::string const & dest, std::string const & message);

private:
	std::ofstream		_fs;

	void				logToConsole( std::string const & log );
	void				logToFile( std::string const & log );
	const std::string	makeLogEntry( std::string const & rudeLog ) const;

};


#endif
