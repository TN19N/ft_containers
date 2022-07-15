/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/15 18:36:21 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <type_traits>
#include "type_traits.hpp"

#include <algorithm>
#include "algorithm.hpp"

#include <iterator>
#include "iterator.hpp"

#include <vector>
#include "vector.hpp"

struct A
{
	A(const A& a) {(void)a; std::cout << "A(A& a)" << std::endl; }
	A()  { std::cout << "A()" << std::endl; };
	~A() { std::cout << "~A()" << std::endl; }
};
std::ostream& operator << (std::ostream& _cout , const A& a) { (void)a; _cout << "_:)_"; return(_cout); }

int main()
{
	ft::vector<A> a(2, A());
	
	std::cout << " ------------------------- " << std::endl;
	
	a.reserve(10);

	std::cout << " -------------------------- " << std::endl;
}