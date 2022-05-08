/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:48 by mannouao          #+#    #+#             */
/*   Updated: 2022/05/08 18:54:21 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "Vector/vector.hpp"
# include <vector>

# include "My_type_traits/enable_if.hpp"
# include "My_type_traits/is_integral.hpp"
# include <type_traits>


# include <algorithm>
# include "My_algorithm/equal.hpp"
# include "My_algorithm/lexicographical_compare.hpp"

# include <iterator>
# include "My_iterator/vector_iterator.hpp"
# include "My_iterator/vector_reverse_iterator.hpp"

# include <utility>

# include <list>

int main()
{
	ft::vector<int> vec;

	vec.reserve(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.insert(vec.end(), 1337);
	std::cout << vec.size() << std::endl;
}