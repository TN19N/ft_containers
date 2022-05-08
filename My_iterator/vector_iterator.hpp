/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:31:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/05/08 13:21:55 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP

# define ITERATOR_HPP

# include "../My_type_traits/enable_if.hpp"
# include "iterators_traits.hpp"
# include <type_traits>

namespace ft
{

template <typename T>
struct iterator
{
	typedef T																iterator_type;
    typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category; 
    typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
    typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
    typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
    typedef typename ft::iterator_traits<iterator_type>::reference			reference;
	
	private:
		iterator_type m_ptr;
	
	public:
	// default constructer
	iterator() {}

	// parametrise constructer
	iterator(const iterator_type& ptr) 
		: m_ptr(ptr)
	{}

	// copy constructer
	template <typename Up>
	iterator(const iterator<Up>& other)
		: m_ptr(other.base())
	{}

	// assignment operator
	iterator& operator = (const iterator& other)
	{
		m_ptr = other.base();
		return (*this);
	}

	// return private pointer
	iterator_type base() const
	{
		return (m_ptr);
	}

	// *a
	reference operator * () const { return (*m_ptr); }

	// a->...
	pointer operator -> () const { return (m_ptr); }

	// ++a;
	iterator& operator ++()
	{
		++m_ptr;
		return (*this);
	}
	
	// a++;
	iterator operator ++(int)
	{
		iterator tmp(*this);
		++(*this);
		return (tmp);
	}

	// --a;
	iterator& operator -- ()
	{
		--this->m_ptr;
		return (*this);
	}

	// a--;
	iterator operator -- (int)
	{
		iterator tmp(*this);
		--(*this);
		return (tmp);
	}

	//a + 5;
	iterator operator + (difference_type n) const
	{
		iterator tmp(*this);

		tmp += n;
		return (tmp);
	}

	// a += 5
	iterator& operator += (difference_type n)
	{
		m_ptr += n;
		return (*this);
	}

	//a - 5;
	iterator operator - (difference_type n) const { return (*this + (-n)); }

	// a -= 5
	iterator& operator -= (difference_type n)
	{
		*this += -n;
		return (*this);
	}

	// a[5]
	reference operator [] (difference_type n) const { return (m_ptr[n]); }
};

// a == b
template <typename T_1, typename T_2>
bool operator == (const iterator<T_1>& x, const iterator<T_2>& y) { return (x.base() == y.base()); }

// a < b
template <typename T_1, typename T_2>
bool operator < (const iterator<T_1>& x, const iterator<T_2>& y) { return (x.base() < y.base()); }

// a != b
template <typename T_1, typename T_2>
bool operator != (const iterator<T_1>& x, const iterator<T_2>& y) { return (!(x.base() == y.base())); }

// a > b
template <typename T_1, typename T_2>
bool operator > (const iterator<T_1>& x, const iterator<T_2>& y) { return (y < x); }

// a >= b
template <typename T_1, typename T_2>
bool operator >= (const iterator<T_1>& x, const iterator<T_2>& y) { return (!(x < y)); }

// a <= b
template <typename T_1, typename T_2>
bool operator <= (const iterator<T_1>& x, const iterator<T_2>& y) { return (!(y < x)); }


// a - b
template <typename T_1, typename T_2>
typename iterator<T_1>::difference_type operator - (const iterator<T_1>& x, const iterator<T_2>& y)
{
	return (x.base() - y.base());
}

// 5 + b
template <typename T>
iterator<T>  operator + (typename iterator<T>::difference_type n, iterator<T> x)
{
	x += n;
	return (x);
}

} // ft

#endif