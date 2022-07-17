/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/17 12:46:36 by mannouao         ###   ########.fr       */
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
	A(const A&) { std::cout << "A(A&)" << std::endl; }
	A() { std::cout << "A()" << std::endl; }
	~A() { std::cout << "~A()" << std::endl; }
};

int main()
{
	ft::vector<std::string> v(3, "HELOO");

	v.erase(v.begin(), v.begin() + 1);

	for (size_t i = 0; i < v.size(); ++i)
		std::cout << "=> " << v[i] << std::endl;
}