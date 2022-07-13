/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:25:49 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/13 17:47:44 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "type_traits.hpp"

namespace ft
{

	// iterator_traits ---------------------------------------------------------------------------------
	template<typename _Tp>
	struct iterator_traits
	{
		typedef typename _Tp::difference_type 		difference_type;
		typedef typename _Tp::value_type			value_type;
		typedef typename _Tp::pointer				pointer;
		typedef typename _Tp::reference				reference;
		typedef typename _Tp::iterator_category		iterator_category;
	};

	template<typename _Tp>
	struct iterator_traits <_Tp *>
	{
		typedef ptrdiff_t							difference_type;
		typedef ft::remove_cv<_Tp>					value_type;
		typedef _Tp* 								pointer;
		typedef _Tp& 								reference;
		typedef std::random_access_iterator_tag 	iterator_category;
	};
	// -------------------------------------------------------------------------------------------------

} // ft

# endif