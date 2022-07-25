/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/25 14:26:23 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */








#include <iostream>
#include <type_traits>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stack>
#include <utility>
#include <map>
#include <memory>
#include <chrono>

# if 1
#include "type_traits.hpp"
#include "algorithm.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "utility.hpp"
#include "map.hpp"

# endif

int main()
{
	ft::map<int, int> m;

	m[0] = 1337;
	m[1] = 1337;
	m[-1] = 1337;
	m.insert(m.find(1), ft::make_pair(2, 1337));

	for (ft::map<int, int>::const_reverse_iterator iter = m.rbegin(); iter != m.rend(); ++iter)
		std::cout << "[" << iter->first << "] => " << iter->second << std::endl;
}