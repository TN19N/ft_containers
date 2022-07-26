/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/26 18:19:27 by mannouao         ###   ########.fr       */
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
	for (int i = 0; i <= 7; ++i)
		m.insert(ft::make_pair(i, i));

	m.erase(0);

	std::cout << "size: " << m.size() << std::endl;
	for (ft::map<int, int>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		std::cout << "[" << iter->first << "] => " << iter->second << std::endl;
}