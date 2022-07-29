/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/29 14:21:54 by mannouao         ###   ########.fr       */
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

#include <stack>
#include "stack.hpp"

#include <utility>
#include "utility.hpp"

#include <map>
#include "map.hpp"

#include <set>
#include "set.hpp"

#include <memory>
#include <chrono>


class A
{
	int* a;
	public:
		A() { a = new int[1]; }
		A(const A& other) { a = new int[1]; *a = *(other.a); }
		~A() {  delete a; }
};

void ft_main()
{
	ft::vector<A> alloc(100);
	std::vector<A> a;
}

int main()
{
	ft_main();
	system("leaks run");
}  