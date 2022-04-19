/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:01:29 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/19 22:41:53 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

# define VECTOR_HPP

# include "../My_iterator/vector_iterator.hpp"
# include "../My_iterator/vector_reverse_iterator.hpp"
# include <memory>

namespace ft
{

template<class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef	T												value_type;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename ft::iterator<pointer>					iterator;
		typedef typename ft::iterator<const_pointer>			const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename allocator_type::size_type				size_type;
    	typedef typename allocator_type::difference_type		difference_type;
	
	private:
		pointer			_begin;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;
	
	public:
	// default constructer
	vector(const allocator_type& alloc = allocator_type())
		: _begin(nullptr),
		  _size(0),
		  _capacity(0),
		  _alloc(alloc)
	{}
	
	// fill constructer
	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _begin(nullptr),
		  _size(n),
		  _capacity(n),
		  _alloc(alloc)
	{
		if (n > 0)
		{
			_begin = _alloc.allocate(n);
			pointer tmp = _begin;
			for(int i = 0; i < n; i++)
				_alloc.construct(tmp++, val);
		}
	}

	// range constructer
	template <class Iterator>
	vector(Iterator first, Iterator last, const allocator_type& alloc = allocator_type())
		: _begin(nullptr),
		  _size(0),
		  _capacity(0),
		  _alloc(alloc)
	{
		typename Iterator::difference_type n = first - last;
		if (n > 0)
		{
			this->_begin = _alloc.allocate(n);
			pointer tmp = _begin;
			for(; first != last; first++)
			 	_alloc.construct(tmp++, *first);
		}
	}

	// copy constructor
	vector(const vector& other)
		: _begin(nullptr),
		  _size(other._size),
		  _capacity(other._size),
		  _alloc(other._alloc)
	{
		if (other._size > 0)
		{
			_begin = _alloc.allocate(other._size);
			pointer tmp = _begin;
			for (int i = 0; i < other._size; i++)
				_alloc.construct(tmp++, other._begin[i]);
		}
	}

	// begin()
	iterator begin() { return (iterator(_begin)); }

	//  const begin()
	const_iterator begine() const { return (const_iterator(_begin)); }

	// end()
	iterator end() { return (iterator(_begin + _size)); }

	// const end()
	const_iterator end() const { return (const_iterator(_begin + _size)); }

	// begin()
	reverse_iterator rbegin() { return (reverse_iterator(end())); }

	//  const begin()
	const_reverse_iterator rbegine() const { return (const_reverse_iterator(end())); }

	// end()
	reverse_iterator rend() { return (reverse_iterator(begin())); }

	// const end()
	const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }

	// size()
	size_type size() const
	{
		return (_size);
	}

	// capacity()
	size_type capacity() const
	{
		return (_capacity);
	}
};

} // ft

#endif