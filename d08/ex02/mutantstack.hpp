/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:13:37 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 19:55:23 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		typedef std::stack<T> base;

	public:
		MutantStack(void) {}
		~MutantStack(void) {}
		MutantStack(MutantStack const & o): base(o) {}
		typedef typename	base::container_type::iterator iterator;
		using				base::operator=;

		iterator	begin() { return base::c.begin(); }
		iterator	end() { return base::c.end() ; }
};


#endif