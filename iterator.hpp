/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:25:49 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/13 21:12:21 by mannouao         ###   ########.fr       */
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

	// __wrap_iter -------------------------------------------------------------------------------------
	template<typename _Iter>
	struct __wrap_iter
	{
	public :
		typedef _Iter															iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
    	typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
    	typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
    	typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
    	typedef typename ft::iterator_traits<iterator_type>::reference			reference;
	private :
		iterator_type __i;
	public :
		__wrap_iter() {}
		template<typename _Up> __wrap_iter(const __wrap_iter<_Up>& __u) : __i(__u.base()) {}

		reference 		operator *  () const { return *__i; }
		pointer   		operator -> () const { return __i; }
		__wrap_iter& 	operator ++ () { ++__i; return (*this); }
		__wrap_iter		operator ++ (int) { __wrap_iter __tmp(*this); ++__i; return (__tmp); }
		__wrap_iter& 	operator -- () { --__i; return (*this); }
		__wrap_iter 	operator -- (int) { __wrap_iter __tmp(*this); --__i; return (__tmp); }
		__wrap_iter		operator +  (difference_type __n) { __wrap_iter __w(*this); __w += __n; return (__w); }
		__wrap_iter&	operator += (difference_type __n) { __i += __n; return (*this); }
		__wrap_iter		operator -  (difference_type __n) { return (*this + (-__n)); } // -------- <<<
	};
	// -------------------------------------------------------------------------------------------------

} // ft

# endif