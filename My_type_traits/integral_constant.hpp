/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:46:37 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/15 02:15:28 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_HPP

# define INTEGRAL_CONSTANT_HPP

/*
	This template is designed to provide compile-time constants as types.
*/

namespace ft
{

template <typename T, T v>
struct integral_constant
{
	static const T value = v;
	typedef T value_type;
	typedef integral_constant<T,v> type;
	operator T() { return v; }
};

} // ft

#endif