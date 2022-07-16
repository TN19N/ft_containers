/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/16 18:11:57 by mannouao         ###   ########.fr       */
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
	std::vector<int> v(10, 1337);

	std::vector<int> c(v);

	std::cout << (v > c) << std::endl;
}