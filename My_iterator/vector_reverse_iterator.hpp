/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:16:15 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/20 20:30:23 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR_HPP

# define VECTOR_REVERSE_ITERATOR_HPP

namespace ft
{

template <typename iter>	
struct reverse_iterator
{
	typedef typename iter::value_type				value_type;
	typedef typename iter::iterator_category		iterator_category;
	typedef typename iter::iterator_type			iterator_type;
    typedef typename iter::difference_type			difference_type;
    typedef typename iter::pointer					pointer;
    typedef typename iter::reference				reference;

	protected:
		iter current;
	
	public:
	// default constructer
	reverse_iterator() {}
	
	// initalization constructor
	reverse_iterator(iter cur) : current(cur) {}
	
	// copy constructer
	reverse_iterator(const reverse_iterator<iter>& other)
	{
		*this = other;
	}

	// assignment operator
	template <typename Up>
	reverse_iterator& operator = (const reverse_iterator<Up>& other)
	{
		this->current = other.base();
		return (*this);
	}

	// return private attribute
	iter base() const { return this->current; }

	// *a
	reference operator * () const
	{
		iter tmp(this->current);
		return (*(--tmp));
	}

	// a->...
	pointer operator -> () const { return(&operator*()); }

	// ++a
	reverse_iterator& operator ++ ()
	{
		--this->current;
		return (*this);
	}
	
	// a++
	reverse_iterator operator ++ (int)
	{
		reverse_iterator tmp(*this);
		--this->current;
		return (tmp);
	}

	// --a
	reverse_iterator& operator -- ()
	{
		++this->current;
		return (*this);
	}
	
	// a--
	reverse_iterator operator -- (int)
	{
		reverse_iterator tmp(*this);
		++this->current;
		return (tmp);
	}

	// a + 5
	reverse_iterator operator + (difference_type n) const { return(reverse_iterator(this->current - n)); }

	// a += 5
	reverse_iterator& operator += (difference_type n) 
	{
		this->current -= n;
		return(*this);
	}

	// a - 5
	reverse_iterator operator - (difference_type n) const { return(reverse_iterator(this->current + n)); }

	// a -= 5
	reverse_iterator& operator -= (difference_type n) 
	{
		this->current += n;
		return(*this);
	}

	// a[5]
	reference operator [] (difference_type n) const { return (*(*this + n)); }
};

// a == b
template <class T_1, class T_2>
bool operator == (const reverse_iterator<T_1>& x, const reverse_iterator<T_2>& y)
{
	return (x.base() == y.base());
}

// a < b
template<class T_1, class T_2>
bool operator < (const reverse_iterator<T_1>& x, const reverse_iterator<T_2>& y)
{
	return (x.base() > y.base());
}

// a != b
template<class T_1, class T_2>
bool operator != (const reverse_iterator<T_1>& x, const reverse_iterator<T_2>& y)
{
	return (x.base() != y.base());
}

// a > b
template<class T_1, class T_2>
bool operator > (const reverse_iterator<T_1>& x, const reverse_iterator<T_2>& y)
{
	return (x.base() < y.base());
}

// a >= b
template<class T_1, class T_2>
bool operator >= (const reverse_iterator<T_1>& x, const reverse_iterator<T_2>& y)
{
	return (x.base() <= y.base());
}

// a <= b
template<class T_1, class T_2>
bool operator <= (const reverse_iterator<T_1>& x, const reverse_iterator<T_2>& y)
{
	return (x.base() >= y.base());
}

// a - b
template <typename T_1, typename T_2>
typename reverse_iterator<T_1>::difference_type operator - (const reverse_iterator<T_1>& x, const reverse_iterator<T_2>& y)
{
	return (y.base() - x.base());
}

// 5 + b
template <typename T>
reverse_iterator<T>  operator + (typename reverse_iterator<T>::difference_type n, reverse_iterator<T>& x)
{
	return (reverse_iterator<T>(x.base() - n));
}

} // ft

#endif