/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:15:47 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/18 20:21:03 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP

# define ITERATORS_TRAITS_HPP

# include "../My_type_traits/remove_cv.hpp"

namespace ft
{

template<class T>
struct iterator_traits
{
	typedef long int							difference_type;
	typedef T									value_type;
	typedef T*									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
	typedef long int							difference_type;
	typedef typename ft::remove_cv<T>::type		value_type;
	typedef T* 									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

} // ft

#endif