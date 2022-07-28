/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/28 15:04:24 by mannouao         ###   ########.fr       */
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
#include <set>

# if 1
#include "algorithm.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "utility.hpp"
#include "type_traits.hpp"
# endif

int main()
{
	ft::map<int, int> m;

	for (int i = 0; i < 1000000; ++i)
		m[i] = i;
	
 	m.erase(m.begin(), m.end());

	std::cout << "size : " << m.size() << std::endl;
} 