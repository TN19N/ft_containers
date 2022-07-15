/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/15 11:25:51 by mannouao         ###   ########.fr       */
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
	ft::vector<int> v;

	v.push_back(1337);
	v.push_back(42);

	ft::vector<int>::reverse_iterator iter1 = v.rbegin();
	ft::vector<int>::reverse_iterator iter2 = v.rend();

	std::cout << " => " << (iter2 - iter1) << std::endl;
}