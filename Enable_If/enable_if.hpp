/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:36:23 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/13 15:20:53 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP

# define ENABLE_IF_HPP

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