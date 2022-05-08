/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:15:47 by mannouao          #+#    #+#             */
/*   Updated: 2022/05/08 13:27:58 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP

# define ITERATORS_TRAITS_HPP

namespace ft
{

template<class Iterator>
struct iterator_traits
{
	typedef typename Iterator::difference_type			difference_type;
	typedef typename Iterator::value_type				value_type;
	typedef typename Iterator::pointer					pointer;
	typedef	typename Iterator::reference				reference;
	typedef typename Iterator::iterator_category		iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
	typedef long int							difference_type;
	typedef T									value_type;
	typedef T* 									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template<class T>
struct iterator_traits<const T*>
{
	typedef long int							difference_type;
	typedef T									value_type;
	typedef const T* 									pointer;
	typedef const T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

} // ft

#endif