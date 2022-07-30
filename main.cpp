/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/30 18:48:26 by mannouao         ###   ########.fr       */
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

#include <limits.h>

int main()
{
	ft::map<int, int> m;


	for (int i = 0; i < 4; ++i)
		m[i] = i;
	ft::map<int, int>::const_iterator iter = m.find(3);
	
	m.erase(m.find(2));

	// while (iter != m.begin())
	// {
	// 	std::cout  << "---" << std::endl;
	// 	--iter;
	// }
	--iter;

	//while (iter != m.end())
	//{
		std::cout << "=> " << iter->first << std::endl;
		//++iter;
	//}
}