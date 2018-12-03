/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:26:05 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/10 22:29:30 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {

public:
	Base( void );
	Base( const Base & );
	virtual ~Base( void );

	Base			&operator=( const Base & );

private:


};

class A : public Base {

public:
	A( void );
	A( const A & );
	~A( void );

	A			&operator=( const A & );

private:


};

class B : public Base {

public:
	B( void );
	B( const B & );
	~B( void );

	B			&operator=( const B & );

private:


};

class C : public Base {

public:
	C( void );
	C( const C & );
	~C( void );

	C			&operator=( const C & );

private:


};


#endif
