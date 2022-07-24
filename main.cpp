/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/24 17:02:39 by mannouao         ###   ########.fr       */
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
	std::map<int, int> m;
	m[0] = 1337;
	m[1] = 1337;
	m[2] = 1337;
	m[3] = 1337;
	m[4] = 1337;
	m[5] = 1337;
	m[6] = 1337;
	m[7] = 1337;
	m[8] = 1337;
	m[9] = 1337;
	m[10] = 1337;
	m[11] = 1337;

	m.insert(m.find(11), std::make_pair(-1, 1337));

	std::cout << "size : " << m.size() << std::endl;

	for (std::map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		std::cout << "[" << iter->first  <<  "]" << " => " << iter->second << std::endl;
}