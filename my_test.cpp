/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_test.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/31 12:31:03 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifdef FT

#include "type_traits.hpp"
#include "algorithm.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "utility.hpp"
#include "set.hpp"

# elif STD

#include <type_traits>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <chrono>
#include <memory>
#include <limits.h>

namespace ft = std;

# endif

#include <iostream>

struct A
{
	int* a;
	A() { a = new int[100]; }
	A(const A& other)
	{
		(void)other;
		a = new int[100];
	}
	~A() { delete a; }
};

int main()
{
	ft::map<int, A> 				map;
	ft::vector<ft::pair<int, A> > 	v(100);

	for (size_t i = 0; i < v.size(); ++i)
		v[i].first = i;
	v.push_back(ft::make_pair(1337, A()));

	map[1337];
	ft::map<int, A>::const_iterator iter = map.begin();
	map.insert(v.begin(), v.end());

	std::cout << "size : " << v.size() << std::endl;
	
	unsigned long long count = 0;
	for (; iter != map.begin() ; --iter)
		count += iter->first;

	for (; iter != map.end(); ++iter)
		count += iter->first;

	std::cout << " => " << count << std::endl;
	system("leaks run");
}