/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/16 16:34:53 by mannouao         ###   ########.fr       */
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

int main()
{
	ft::vector<int> v(4, 10);

	v.push_back(1337);

	v.insert(v.end(), 3, 42);

	std::cout << "size : " << v.size() << ", capacity : " << v.capacity() << std::endl;
	for (size_t i = 0; i < v.size() ; ++i)
		std::cout << "=> " << v[i] << std::endl;
}