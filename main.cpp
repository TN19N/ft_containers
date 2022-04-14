/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:48 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/14 21:44:58 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "Vector/vector.hpp"
# include <vector>

# include "Tools/enable_if.hpp"
# include "Tools/is_integral.hpp"
# include <type_traits>

// ....... for testing enable_if ........

// class A{};
// class B : public A {};

// template<typename T, typename ft::enable_if<std::is_signed<T>::value, bool>::type = true>
// void int_type(T)
// {
// 	std::cout << "T is signed int" << std::endl;
// }

// template<typename T, typename ft::enable_if<std::is_unsigned<T>::value, bool>::type = true>
// void int_type(T)
// {
// 	std::cout << "T is unsigned int" << std::endl;
// }

// template <typename Base, typename Child, typename ft::enable_if<!std::is_base_of<Base, Child>::value, bool>::type = true>
// void is_fromBase(void)
// {
// 	std::cout << "the child is not inherited from the base" << std::endl;
// }
// template <typename Base, typename Childe, typename ft::enable_if<std::is_base_of<Base, Childe>::value, bool>::type = true>
// void is_fromBase(void)
// {
// 	std::cout << "the child is inherited from the base" << std::endl;
// }

// .......................................

int main()
{
	// .............. testing enable_if ...............
	
	{
		int a;
		unsigned int b;

		// is_fromBase<A, B>();
		// int_type(a);
		// int_type(b);
	}
	// .................................................

	// ............. testing is_integral ...............

	{
		std::cout << std::is_integral<int>::value << std::endl;
		std::cout << ft::is_integral<int>::value << std::endl;

		std::cout << std::is_integral<float>::value << std::endl;
		std::cout << ft::is_integral<float>::value << std::endl;
	}

	// .................................................
}