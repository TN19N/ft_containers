/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:25:49 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/24 13:53:37 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "type_traits.hpp"

namespace ft
{

	// iterator_traits ---------------------------------------------------------------------------------------------------------------
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
		typedef _Tp									value_type;
		typedef _Tp* 								pointer;
		typedef _Tp& 								reference;
		typedef std::random_access_iterator_tag 	iterator_category;
	};

	template<typename _Tp>
	struct iterator_traits <const _Tp *>
	{
		typedef ptrdiff_t							difference_type;
		typedef _Tp									value_type;
		typedef const _Tp* 							pointer;
		typedef const _Tp& 							reference;
		typedef std::random_access_iterator_tag 	iterator_category;
	};
	// -------------------------------------------------------------------------------------------------------------------------------

	// iterator ----------------------------------------------------------------------------------------------------------------------
	template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
	          typename _Pointer = _Tp*, typename _Reference = _Tp&>
	struct iterator
	{
		typedef _Tp			value_type;
		typedef _Distance	difference_type;
		typedef _Pointer	pointer;
		typedef _Reference	reference;
		typedef _Category	iterator_category; 
	};
	// -------------------------------------------------------------------------------------------------------------------------------

	// __wrap_iter -------------------------------------------------------------------------------------------------------------------
	template<typename _Iter>
	class __wrap_iter
	{
	public:
		typedef _Iter															iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
    	typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
	private:
		iterator_type __i;
	public:
		__wrap_iter() {}
		template<class _Up> __wrap_iter(const ft::__wrap_iter<_Up>& __u) : __i(__u.base()) {}
		template<class _Up> __wrap_iter& operator = (const ft::__wrap_iter<_Up>& __u) { __i == __u.base(); return *this; }

		reference 		operator *  () const { return *__i; }
		pointer			operator -> () const { return __i; }
		__wrap_iter& 	operator ++ () { ++__i; return *this; }
		__wrap_iter		operator ++ (int) { __wrap_iter __tmp(*this); ++__i; return __tmp; }
		__wrap_iter& 	operator -- () { --__i; return *this; }
		__wrap_iter 	operator -- (int) { __wrap_iter __tmp(*this); --__i; return __tmp; }
		__wrap_iter		operator +  (difference_type __n) const { __wrap_iter __w(*this); __w += __n; return __w; }
		__wrap_iter&	operator += (difference_type __n) { __i += __n; return *this; }
		__wrap_iter		operator -  (difference_type __n) const { return *this + (-__n); }
		__wrap_iter&	operator -= (difference_type __n) { __i -= __n; return *this; }
		reference		operator [] (difference_type __n) const { return __i[__n]; }

		iterator_type base() const { return __i; }

	private:
		__wrap_iter(iterator_type __x) : __i(__x) {}
		
		template<typename _Tp, typename _Alloc> friend class vector;
	};

	template<typename _Iter1, typename _Iter2>
	bool operator == (const ft::__wrap_iter<_Iter1>& __x, const ft::__wrap_iter<_Iter2>& __y)
	{ return __x.base() == __y.base(); }

	template<typename _Iter1, typename _Iter2>
	bool operator <  (const ft::__wrap_iter<_Iter1>& __x, const ft::__wrap_iter<_Iter2>& __y)
	{ return __x.base() < __y.base(); }

	template<typename _Iter1, typename _Iter2>
	bool operator != (const ft::__wrap_iter<_Iter1>& __x, const ft::__wrap_iter<_Iter2>& __y)
	{ return !(__x == __y); }

	template<typename _Iter1, typename _Iter2>
	bool operator >  (const ft::__wrap_iter<_Iter1>& __x, const ft::__wrap_iter<_Iter2>& __y)
	{ return __y < __x; }

	template<typename _Iter1, typename _Iter2>
	bool operator >= (const ft::__wrap_iter<_Iter1>& __x, const ft::__wrap_iter<_Iter2>& __y)
	{ return !(__x < __y); }

	template<typename _Iter1, typename _Iter2>
	bool operator <= (const ft::__wrap_iter<_Iter1>& __x, const ft::__wrap_iter<_Iter2>& __y)
	{ return !(__y < __x); }

	template<typename _Iter1, typename _Iter2>
	typename __wrap_iter<_Iter1>::difference_type operator - (const ft::__wrap_iter<_Iter1>& __x, const ft::__wrap_iter<_Iter2>& __y)
	{ return __x.base() - __y.base(); }

	template<typename _Iter>
	__wrap_iter<_Iter> operator + (typename ft::__wrap_iter<_Iter>::difference_type __n, ft::__wrap_iter<_Iter> __x)
	{ __x += __n; return __x; }
	// -------------------------------------------------------------------------------------------------------------------------------

	// reverse_iterator --------------------------------------------------------------------------------------------------------------
	template<typename _Iter>
	class reverse_iterator 
		: public ft::iterator<typename ft::iterator_traits<_Iter>::iterator_category,
							  typename ft::iterator_traits<_Iter>::value_type,
							  typename ft::iterator_traits<_Iter>::difference_type,
							  typename ft::iterator_traits<_Iter>::pointer,
							  typename ft::iterator_traits<_Iter>::reference>
	{
	protected:
		_Iter current;
	public:
		typedef _Iter													iterator_type;
		typedef typename ft::iterator_traits<_Iter>::difference_type 	difference_type;
		typedef typename ft::iterator_traits<_Iter>::reference			reference;
		typedef typename ft::iterator_traits<_Iter>::pointer			pointer;

		reverse_iterator () : current() {}
		explicit reverse_iterator (_Iter __x) : current(__x) {}
		template<typename _Up> reverse_iterator (const ft::reverse_iterator<_Up>& __u) : current(__u.base()) {}
		template<typename _Up> 
		reverse_iterator& operator = (const ft::reverse_iterator<_Up>& __u) { current = __u.base(); return *this; } 
		
		_Iter base() const { return current; }

		reference			operator *  () const { _Iter __tmp = current; return *--__tmp; }
		pointer				operator -> () const { return &operator*(); }
		reverse_iterator&	operator ++ () { --current; return *this; }
		reverse_iterator	operator ++ (int) { reverse_iterator __tmp(*this); --current; return __tmp; }
		reverse_iterator&	operator -- () { ++current; return *this; }
		reverse_iterator	operator -- (int) { reverse_iterator __tmp(*this); ++current; return __tmp; }
		reverse_iterator	operator +  (difference_type __n) const { return reverse_iterator(current - __n); }
		reverse_iterator&	operator += (difference_type __n) { current -= __n; return *this; }
		reverse_iterator	operator -  (difference_type __n) const { return reverse_iterator(current + __n); }
		reverse_iterator&	operator -= (difference_type __n) { current += __n; return *this; }
		reference			operator [] (difference_type __n) { return *(*this + __n); }
	};
	template<typename _Iter1, typename _Iter2>
	bool operator == (const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
	{ return __x.base() == __y.base(); }

	template<typename _Iter1, typename _Iter2>
	bool operator < (const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
	{ return __x.base() > __y.base(); }

	template<typename _Iter1, typename _Iter2>
	bool operator != (const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
	{ return __x.base() != __y.base(); }

	template<typename _Iter1, typename _Iter2>
	bool operator > (const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
	{ return __x.base() < __y.base(); }

	template<typename _Iter1, typename _Iter2>
	bool operator >= (const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
	{ return __x.base() <= __y.base(); }

	template<typename _Iter1, typename _Iter2>
	bool operator <= (const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
	{ return __x.base() >= __y.base(); }

	template<typename _Iter1, typename _Iter2>
	typename ft::reverse_iterator<_Iter1>::difference_type
	operator - (const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
	{ return __y.base() - __x.base(); }

	template<typename _Iter>
	ft::reverse_iterator<_Iter> operator + (typename ft::reverse_iterator<_Iter>::difference_type __n, const ft::reverse_iterator<_Iter>& __x)
	{ return ft::reverse_iterator<_Iter>(__x.base() - __n); }
	// -------------------------------------------------------------------------------------------------------------------------------
	
	// distance ----------------------------------------------------------------------------------------------------------------------
	template<typename _InputIter>
	typename ft::iterator_traits<_InputIter>::difference_type
	distance(_InputIter __first, _InputIter __last) { return __last - __first; }
	// -------------------------------------------------------------------------------------------------------------------------------
	
	// __map_iter --------------------------------------------------------------------------------------------------------------------
	template<class _Iter, class _Node_ptr>
	class __map_iter
	{
	public:
		typedef _Iter															iterator_type;
		typedef std::bidirectional_iterator_tag									iterator_category;
		typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
	private:
		_Node_ptr __i;
	public:
		__map_iter() {}
		template<class _Up, class _Up_node>
		__map_iter(const ft::__map_iter<_Up, _Up_node>& __u) : __i(__u.__i) {}
		template<class _Up, class _Up_node>
		__map_iter& operator = (const ft::__map_iter<_Up, _Up_node>& __u) { __i = __u.__i; return *this; }

		reference	operator *  () const { return *(__i->__value_); }
		pointer		operator -> () const { return __i->__value_; }

		__map_iter& operator ++ ()
		{
			if (__i->__right_ != NULL)
				for(__i = __i->__right_; __i->__left_ != NULL;)
					__i = __i->__left_;
			else
			{
				while (__i == __i->__parent_->__right_)
					__i = __i->__parent_;
			}
			return *this;
		}
		__map_iter operator ++ (int) { __map_iter __tmp(*this); ++*this; return __tmp; }
		__map_iter& operator -- ()
		{
			if (__i->__left_ != NULL)
				for (__i = __i->__left_; __i->__right_ != NULL;)
					__i = __i->__right_;
			else
			{
				while(__i == __i->__parent_->__left_)
					__i = __i->__parent_;
			}
			return *this;
		}
		__map_iter operator -- (int) {__map_iter __tmp(*this); --*this; return __tmp; }
	private:
		__map_iter(_Node_ptr __x) : __i(__x) {}
		
		template<class key_type, class mapped_type, class value_type, class key_compare, class value_compare, class allocator_type> friend class tree;
		template<class _Iter1, class _Node_ptr1, class _Iter2, class _Node_ptr2>
		friend bool operator == (const __map_iter<_Iter1, _Node_ptr1>& __x, const __map_iter<_Iter2, _Node_ptr2>& __y);
	};
	template<class _Iter1, class _Node_ptr1, class _Iter2, class _Node_ptr2>
	bool operator == (const __map_iter<_Iter1, _Node_ptr1>& __x, const __map_iter<_Iter2, _Node_ptr2>& __y)
	{ return __x.__i == __y.__i; }

	template<class _Iter1, class _Node_ptr1, class _Iter2, class _Node_ptr2>
	bool operator != (const __map_iter<_Iter1, _Node_ptr1>& __x, const __map_iter<_Iter2, _Node_ptr2>& __y)
	{ return !(__x == __y); }
	// -------------------------------------------------------------------------------------------------------------------------------
	
} // ft

# endif