/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:48 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/19 22:45:23 by mannouao         ###   ########.fr       */
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

int main()
{
	std::vector<int> a(3);
	ft::vector<int> b(3);

	a.end();
	std::vector<int>::iterator iter;
	//ft::vector<int>::iterator iter;

	for (;iter != a.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << "std: size = " << a.size() << ", capacity = " << a.capacity() << std::endl;
	std::cout << "ft: size = " << b.size() << ", capacity = " << b.capacity() << std::endl;
}