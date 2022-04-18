/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:16:15 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/18 17:30:07 by mannouao         ###   ########.fr       */
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
	
	// default constructer
	reverse_iterator() {};
	
	// initalization constructor
	reverse_iterator(iter cur) : current(cur) {};
	
	// copy constructer
	reverse_iterator(const reverse_iterator<iter>& other)
	{
		*this = other;
	}

	// assignment operator
	reverse_iterator& operator = (const reverse_iterator<iter>& other)
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
	pointer operator -> () const
	{
		iter tmp(this->current);
		return(--tmp);
	}

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

// a < b
template<class iter_1, class iter_2>
bool operator < (const reverse_iterator<iter_1>& x, const reverse_iterator<iter_2>& y)
{
	return (x.base() > y.base());
}

// a != b
template<class iter_1, class iter_2>
bool operator != (const reverse_iterator<iter_1>& x, const reverse_iterator<iter_2>& y)
{
	return (x.base() != y.base());
}

// a > b
template<class iter_1, class iter_2>
bool operator > (const reverse_iterator<iter_1>& x, const reverse_iterator<iter_2>& y)
{
	return (x.base() < y.base());
}

// a >= b
template<class iter_1, class iter_2>
bool operator >= (const reverse_iterator<iter_1>& x, const reverse_iterator<iter_2>& y)
{
	return (x.base() <= y.base());
}

// a <= b
template<class iter_1, class iter_2>
bool operator <= (const reverse_iterator<iter_1>& x, const reverse_iterator<iter_2>& y)
{
	return (x.base() >= y.base());
}

} // ft

#endif