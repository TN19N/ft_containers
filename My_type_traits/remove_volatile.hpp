/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_volatile.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:34:44 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/15 01:10:21 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_VOLATILE_HPP

# define REMOVE_VOLATILE_HPP

/*
	remove volatile from the type , Otherwise leave the type as it is.
*/

namespace ft
{

template <typename T> struct remove_volatile { typedef T type; };

template <typename T> struct remove_volatile <volatile T> { typedef T type; };

} // ft

#endif