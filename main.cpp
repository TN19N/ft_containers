/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/28 14:40:03 by mannouao         ###   ########.fr       */
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

template <typename Iter1, typename Iter2>
bool comparemaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}


int main()
{
	ft::map<int, int> m;

	for (int i = 0; i < 10; ++i)
		m[i] = i;

	// m.erase(0);
	// m.erase(1);
	// m.erase(2);
	m.erase(m.begin(), m.end());

	std::cout << "size : " << m.size() << std::endl;
} 