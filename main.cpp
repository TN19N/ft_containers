/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/27 09:07:37 by mannouao         ###   ########.fr       */
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
	std::map<int, int> k;
	ft::map<int, int, std::greater<int>> m;
	ft::map<int, int>::iterator iter = m.begin();
	std::cout << iter->first << std::endl;
}