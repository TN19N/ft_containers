/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_const.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:34:44 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/15 01:09:49 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_CONST_HPP

# define REMOVE_CONST_HPP

/*
	remove const from the type , Otherwise leave the type as it is.
*/

namespace ft
{

template <typename T> struct remove_const { typedef T type; };

template <typename T> struct remove_const <const T> { typedef T type; };

} // ft

#endif