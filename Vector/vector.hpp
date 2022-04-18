/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:01:29 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/18 21:17:39 by mannouao         ###   ########.fr       */
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
		typedef typename ft::reverse_iterator<const_iterator>	const_rverse_iterator;
		typedef typename allocator_type::size_type				size_type;
    	typedef typename allocator_type::difference_type		difference_type;
	
	private:
		pointer			_begin;
		size_type		_size;
		size_type		_capacity;
	
	// default constructer
	vector(const allocator_type& alloc = allocator_type())
		: _begin(nullptr),
		  _size(0),
		  _capacity(0)
	{};
	
	// fill constructer
	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _begin(alloc.allocate(n)),
		  _size(n),
		  _capacity(n)
	{
		alloc.construct(n, val);
	}

	// range constructer
	template <class Iterator>
	vector(Iterator firts, Iterator last, const allocator_type& alloc = allocator_type())
	{
		
	}
};

} // ft

#endif