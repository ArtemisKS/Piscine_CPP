/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:33:51 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/03 22:04:49 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

int		main( int ac, char **av )
{
	if ( ac != 4 || !strlen(av[1]) || !strlen(av[2]) || !strlen(av[3]) )
	{
		std::cerr << "Some error occurred: not valid arguments" << std::endl;
		std::cerr << "usage: ./replace file_name string_to_find string_to_replace_with" << std::endl;
		return 1;
	}

	const std::string		fileName(av[1]);
	const std::string		toFind(av[2]);
	const std::string		toReplace(av[3]);
	std::ifstream			fileToFindIn(fileName);
	std::ofstream			fileToWriteReplacements(fileName + ".replace");
	if ( !fileToFindIn || !fileToWriteReplacements )
	{
		std::cerr << "Some error occurred: not valid arguments" << std::endl;
		std::cerr << "usage: ./replace file_name string_to_find string_to_replace_with" << std::endl;
		return 2;
	}

	fileToFindIn.seekg(0, fileToFindIn.end);
	const size_t			length(fileToFindIn.tellg());
	if (length == std::string::npos) {
		std::cerr << "Some error occurred: cannot count length of file" << std::endl;
		return 3;
	}
	fileToFindIn.seekg(0, fileToFindIn.beg);
	char*					buffer = new char[length];
	fileToFindIn.read(buffer, length);
	std::string				s(buffer);

	for ( 
		size_t pos = s.find(toFind);
		pos != std::string::npos;
		pos = s.find(toFind, pos + toReplace.length())
	)
	{
		s.replace( pos, toFind.length(), toReplace );
	}

	fileToWriteReplacements	<< s;

	delete [] buffer;

	return 0;
}
