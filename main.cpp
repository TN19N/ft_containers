/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/24 13:50:26 by mannouao         ###   ########.fr       */
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
	ft::map<std::string, int> m;
	m["BO3O"] = 18;


	for (ft::map<std::string, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		std::cout << "[" << iter->first  <<  "]" << " => " << iter->second << std::endl;
}