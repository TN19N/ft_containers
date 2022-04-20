/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:48 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/20 15:16:37 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

//# include "Vector/vector.hpp"
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

int main()
{
	std::allocator<int> n;
	std::vector<int> a(11);
	std::vector<int> b(10);

	a.push_back(1337);
	a.push_back(-1);
	a.push_back(-2);
	b.assign(a.begin(), a.end());
	std::cout << b.size() << " - " << b.capacity() << std::endl;
	//a.operator=
}