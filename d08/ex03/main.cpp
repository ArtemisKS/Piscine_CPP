/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:19:20 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 20:37:52 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ICommands.hpp>
#include <fstream>

#include <Plus.hpp>
#include <Minus.hpp>
#include <Pleft.hpp>
#include <Pright.hpp>
#include <Dot.hpp>
#include <Comma.hpp>
#include <Loop.hpp>

void			execQueue( std::queue<ICommands*> &Q )
{
	while ( !Q.empty() )
	{
		Q.front()->exec();
		delete Q.front();
		Q.pop();
	}
}
void			parseRaw( std::list<int> &stack, std::list<int>::iterator &it,
	std::queue<ICommands*> &Q, std::string &S )
{
	for ( std::string::iterator i = S.begin(); i != S.end(); i++ )
	{
		if ( *i == '+' )			Q.push( new Plus(it) );
		else if ( *i == '-' )		Q.push( new Minus(it) );
		else if ( *i == '>' )		Q.push( new Pright(stack, it) );
		else if ( *i == '<' )		Q.push( new Pleft(stack, it) );
		else if ( *i == '.' )		Q.push( new Dot(it) );
		else if ( *i == ',' )		Q.push( new Comma(it) );
		else if ( *i == ']' ) {
			std::cout << "NO MATCHING '[' FOUNDED" << std::endl;
			exit(3);
		}
		else if ( *i == '[' ) {

			std::string::iterator j = ++i;
			while ( j != S.end() && *j != ']' )
				j++;

			if ( j == S.end() ) {
				std::cout << "NO MATCHING ']' FOUNDED" << std::endl;
				exit(4);
			}
			Q.push( new Loop( stack, it, i, j) );
			i = j;
		}
	}
}
static void		errMessage( const char *mess )
{
	std::cout << mess << std::endl;
	std::cout << "Usage: ./mindopen <program_name.o>" << std::endl;
	exit (1);
}
int				main( int ac, const char **av )
{
	if ( ac != 2 )				errMessage("ERROR: wrong number of arguments");
	std::ifstream				file(av[1], std::ios_base::in);
	if ( !file.good() )			errMessage("ERROR: wrong filename");
	std::string					temp;
	std::queue<ICommands*>		Q;
	std::list<int>				stack(10, 0);
	std::list<int>::iterator	it(stack.begin());

	while( std::getline(file, temp) ) {
		parseRaw(stack, it, Q, temp);
	}

	execQueue(Q);

	return 0;
}
