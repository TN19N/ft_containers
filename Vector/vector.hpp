/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:01:29 by mannouao          #+#    #+#             */
/*   Updated: 2022/05/07 17:08:58 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

# define VECTOR_HPP

# include "../My_type_traits/enable_if.hpp"
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
	explicit vector(const allocator_type& alloc = allocator_type())
		: _begin(nullptr),
		  _size(0),
		  _capacity(0),
		  _alloc(alloc)
	{}
	
	// fill constructer
	explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _begin(nullptr),
		  _size(0),
		  _capacity(0),
		  _alloc(alloc)
	{
		if (n > 0)
		{
			if (n > max_size())
				throw(std::length_error("Error : vector : length bigger than of std::allocator<T>::max_size() !!"));
			try { _begin = _alloc.allocate(n); }
			catch (const std::exception& e) { throw (e); }
			_capacity = n;
			pointer tmp = _begin;
			for(size_type i = 0; i < n; i++)
				_alloc.construct(tmp++, val);
			_size = n;
		}
	}

	// range constructer
	template <class Iterator>
	vector(Iterator first, Iterator last, const allocator_type& alloc = allocator_type()
	, typename ft::enable_if<std::is_convertible<Iterator, iterator>::value || std::is_convertible<Iterator, reverse_iterator>::value, bool>::type = true)
		: _begin(nullptr),
		  _size(0),
		  _capacity(0),
		  _alloc(alloc)
	{
		typename iterator::difference_type n = last - first;
		if (n > 0)
		{
			if (n > max_size())
				throw(std::length_error("Error : vector : length bigger than of std::allocator<T>::max_size() !!"));
			try { _begin = _alloc.allocate(n); }
			catch (const std::exception& e) { throw (e); }
			_capacity = n;
			assign(first, last);
		}
	}

	// copy constructor
	vector(const vector& other)
		: _begin(nullptr),
		  _size(0),
		  _capacity(0),
		  _alloc(other._alloc)
	{
		if (other._size > 0)
		{
			try { _begin = _alloc.allocate(other._size); }
			catch (const std::exception& e) { throw (e); }
			_capacity = other._capacity;
			pointer tmp = _begin;
			for (size_type i = 0; i < other._size; i++)
				_alloc.construct(tmp++, other._begin[i]);
			_size = other._size;
		}
	}

	// operator =
	vector& operator = (const vector& other)
	{
		if (this != &other)
			assign(other.begin(), other.end());
		return (*this);
	}

	// begin()
	iterator begin() { return (iterator(_begin)); }

	//  const begin()
	const_iterator begin() const { return (const_iterator(_begin)); }

	// end()
	iterator end() { return (iterator(_begin + _size)); }

	// const end()
	const_iterator end() const { return (const_iterator(_begin + _size)); }

	// begin()
	reverse_iterator rbegin() { return (reverse_iterator(end())); }

	//  const begin()
	const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }

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

	// clear()
	void clear()
	{
		pointer tmp = _begin;
		for(size_type i = 0; i < _size; i++)
			_alloc.destroy(tmp++);
		_size = 0;
	}

	// assign() // range
	template <class Iterator>
	void assign(Iterator first, Iterator last)
	{
		typename iterator::difference_type n = last - first;
		if (n > _capacity)
			reserve(n);
		clear();
		for (; first != last; first++)
			push_back(*first);
	}

	// assign() // fill
	void assign(size_type n, const value_type& val)
	{
		if (n > _capacity)
			reserve(n);
		clear();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}

	// push_back()
	void push_back (const value_type& val)
	{
		if (_capacity == 0)
			reserve(1);
		else if (_size == _capacity)
			reserve(_capacity * 2);
		_alloc.construct(_begin + _size, val);
		_size++;
	}

	// reserve()
	void reserve(size_type n)
	{
		if (n > _capacity)
		{
			vector tmp(*this);
			clear();
			if (_begin != nullptr)
				_alloc.deallocate(_begin, _capacity);
			try { _begin = _alloc.allocate(n); }
			catch(const std::exception& e) { throw(e); }
			_capacity = n;
			assign(tmp.begin(), tmp.end());
		}
	}

	// max_size()
	size_type max_size() const
	{
		return (_alloc.max_size());
	}

	// resize()
	void resize (size_type n, value_type val = value_type())
	{
		if (n < _size)
		{
			pointer tmp = _begin + n;
			for (size_type i = n; i < _size; i++)
				_alloc.destroy(tmp++);
			_size = n;
		}
		else if (n > _size)
		{
			if (n > _capacity)
			{
				if (n > _capacity * 2)
					reserve (n);
				else
					reserve (_capacity * 2);
			}
			pointer tmp = _begin + n;
			for (size_type i = _size; i < n; i++)
			{
				std::cout << i << " - " << *(tmp - 1) << std::endl;
				_alloc.construct(tmp++, val);
			}
			_size = n;
		}
	}
};

} // ft

#endif