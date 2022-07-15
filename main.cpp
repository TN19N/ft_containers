/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/15 17:16:14 by mannouao         ###   ########.fr       */
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
	A()  { std::cout << "A()" << std::endl; };
	~A() { std::cout << "~A()" << std::endl; }

};
std::ostream& operator << (std::ostream& _cout , const A& a) { (void)a; _cout << "_:)_"; return(_cout); }


int main()
{
	ft::vector<A> v(3);
	std::cout << " -------------------------- " << std::endl;
	std::cout << " -------------------------- " << std::endl;
}