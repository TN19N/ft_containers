/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:48 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/20 21:20:55 by mannouao         ###   ########.fr       */
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

void ft_main()
{
	ft::vector<std::string> const ft_v2(10, "string2");

	ft::vector<std::string>::const_iterator rit = ft_v2.begin();
}

int main()
{
	ft_main();
	//system("leaks a.out");
}