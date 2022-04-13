/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:48 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/13 19:52:19 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "Vector/vector.hpp"
# include <vector>

# include "Enable_If/enable_if.hpp"
# include <type_traits>

// ....... for testing enable_if ........

class A{};
class B : public A {};

template<typename T>
void int_type(T a)
{
	std::cout << "its an signed int" << std::endl;
}

template<typename T, class Y=void>//typename std::enable_if<std::is_unsigned<T>::value, T>::type* = nullptr>
void int_type(T a)
{
	std::cout << "its an unsigned int" << std::endl;
}

// template <typename Base, typename Child>
// void is_fromBase(void)
// {
// 	std::cout << "the childe  is not inhereted from the base" << std::endl;
// }
// template <typename Base, typename Childe, typename std::enable_if<std::is_base_of<A, B>::value, void>::type* = nullptr>
// void is_fromBase(void)
// {
// 	std::cout << "the childe is inheret from the base" << std::endl;
// }

// .......................................

int main()
{
	int a;
	unsigned int b;
	// .............. testing enable_if ...............
	//is_fromBase<A, B>();
	int_type<int>(a);
	int_type<unsigned int>(b);

}