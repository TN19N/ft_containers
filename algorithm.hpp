/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:05:32 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/28 10:53:47 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include "iterator.hpp"

namespace ft
{
	
	// __equal_to -------------------------------------------------------------------------------------------------------------------------------------
	template<typename T1, typename T2>
	struct __equal_to { bool operator () (const T1& __x, const T2& __y) const { return __x == __y; } };
	// ------------------------------------------------------------------------------------------------------------------------------------------------
	
	// __less -----------------------------------------------------------------------------------------------------------------------------------------
	template<typename T1, typename T2>
	struct __less { bool operator () (const T1& __x, const T2& __y) { return __x < __y; } };
	// ------------------------------------------------------------------------------------------------------------------------------------------------

	// equal ------------------------------------------------------------------------------------------------------------------------------------------
	template<typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate>
	bool equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __pred)
	{
		for (; __first1 != __last1 ; ++__first1, ++__first2)
			if(!__pred(*__first1, *__first2))
				return (false);
		return (true);
	}
	
	template<typename _InputIterator1, typename _InputIterator2>
	bool equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
	{
		typedef typename ft::iterator_traits<_InputIterator1>::value_type __v1;
		typedef typename ft::iterator_traits<_InputIterator2>::value_type __v2;

		return ft::equal(__first1, __last1, __first2, ft::__equal_to<__v1, __v2>());
	}
	// ------------------------------------------------------------------------------------------------------------------------------------------------

	// lexicographical_compare ------------------------------------------------------------------------------------------------------------------------
	template<typename _InputIterator1, typename _InputIterator2, typename Compare>
	bool lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2, Compare __comp)
	{
		for (; __first2 != __last2 ; ++__first1, ++__first2)
		{
			if (__first1 == __last1 || __comp(*__first1, *__first2))
				return (true);
			if (__comp(*__first2, *__first1))
				return (false);
		}
		return(false);
	}

	template<typename _InputIterator1, typename _InputIterator2>
	bool lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2)
	{
		typedef typename ft::iterator_traits<_InputIterator1>::value_type __v1;
		typedef typename ft::iterator_traits<_InputIterator2>::value_type __v2;

		return ft::lexicographical_compare(__first1, __last1, __first2, __last2, ft::__less<__v1, __v2>());
	}
	// ------------------------------------------------------------------------------------------------------------------------------------------------

} // ft

# endif