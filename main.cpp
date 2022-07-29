/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/29 17:05:27 by mannouao         ###   ########.fr       */
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

void ft_main()
{
	ft::map<int, int> m;

	m[0] = 0;
	m[1] = 100;
	m[2] = 200;

	m.erase(m.find(2), m.end());

	for (ft::map<int, int>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		std::cout << "[" << iter->first << "] => " << iter->second << std::endl;
}

int main()
{
	ft_main();
	system("leaks run");
	return (0);
}