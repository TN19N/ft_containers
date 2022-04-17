/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:36:23 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/15 01:06:32 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP

# define ENABLE_IF_HPP

/*
	The type T is enabled as member type enable_if::type if bool is true.
	Otherwise, enable_if::type is not defined.
*/

namespace ft
{

template<bool, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T>
{
	typedef T type;
};

} // ft

#endif