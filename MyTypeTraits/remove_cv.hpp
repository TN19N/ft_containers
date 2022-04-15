/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_cv.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:55:22 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/15 01:10:36 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_CV_HPP

# define REMOVE_CV_HPP

# include "remove_volatile.hpp"
# include "remove_const.hpp"

/*
	remove volatile and const from the type , Otherwise leave the type as it is.
*/

namespace ft
{

template<typename T>
struct remove_cv
{
	typedef typename ft::remove_volatile<typename ft::remove_const<T>::type>::type type;
};

} // ft

#endif