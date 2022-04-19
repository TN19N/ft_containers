/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:31:06 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/19 22:44:35 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP

# define ITERATOR_HPP

# include "iterators_traits.hpp"

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
		pointer m_ptr;
	
	public:
	// default constructer
	iterator() {}

	// parameterised constructor
	iterator(iterator_type x)
		: m_ptr(x)
	{}

	// copy constructer
	iterator(const iterator<T>& other)
	{
		*this = other;
	}

	// assignment operator
	iterator& operator = (const iterator<T>& other)
	{
		this->m_ptr = other.base();
		return (*this);
	}

	// return private pointer
	iterator_type base() const
	{
		return (m_ptr);
	}

	// *a
	reference operator * () const { return (*this->m_ptr); }

	// a->...
	pointer operator -> () const { return (this->m_ptr); }

	// ++a;
	iterator& operator ++()
	{
		++this->m_ptr;
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
		this->m_ptr += n;
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
	reference operator [] (difference_type n) const { return (this->m_ptr[n]); }
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

} // ft

#endif