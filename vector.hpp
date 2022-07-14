/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:10:38 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/14 17:04:03 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "algorithm.hpp"

namespace ft
{

	template<typename _Tp, typename _Allocater = std::allocator<_Tp> >
	class vector
	{
	public:
		typedef _Tp											value_type;
		typedef _Allocater									allocater_type;
		typedef typename allocater_type::reference			reference;
		typedef typename allocater_type::const_reference	const_reference;
		typedef typename allocater_type::pointer			pointer;
		typedef typename allocater_type::const_pointer		const_pointer;
		typedef ft::__wrap_iter<pointer>					iterator;
		typedef ft::__wrap_iter<const_pointer>				const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef typename allocater_type::difference_type	difference_type;
		typedef typename allocater_type::size_type			size_type;

		explicit vector(const allocater_type& alloc = allocater_type())
			: __begin_(NULL),
			  __end_(NULL),
			  __capacity_(0),
			  __alloc_(alloc)
		{}

		explicit vector(size_type __n, const value_type& val = value_type(), const allocater_type& alloc = allocater_type())
			: __begin_(NULL),
			  __end_(NULL),
			  __capacity_(0),
			  __alloc_(alloc)
		{
			if (__n > 0)
			{
				__n > max_size() && std::__throw_length_error("vector");
				try { __begin_ = __end_ = __alloc_.allocate(__n) } catch (const std::bad_alloc& e) { throw (e); }
				__capacity_ = __n;
				for (size_type i = 0; i < __n; ++i)
					__alloc_.construct(__begin_ + i, val);
			}
		}

		template<typename _Iter>
		explicit vector(_Iter first, _Iter secend, const allocater_type& alloc = allocater_type(),
						typename ft::enable_if<std::__is_input_iterator<_Iter>::value, bool>::type = true)
			: __begin_(NULL),
			  __end_(NULL),
			  __capacity_(0),
			  __alloc_(alloc)
		{
			size_type __n = static_cast<size_type>(ft::distance(first, secend));
			if (__n > 0)
			{
				__n > max_size() && std::__throw_length_error("vector");
				try { __begin_ = __end_ = __alloc_.allocate(__n) } catch (const std::bad_alloc& e) { throw (e); }
				__capacity_ = __n;
			}
		}

		reverse_iterator		rbegin()		{ return (reverse_iterator(end())); }
		const_reverse_iterator	rbegin() const	{ return (const_reverse_iterator(end())); }
		reverse_iterator		rend()			{ return (reverse_iterator(begin())); }
		const_reverse_iterator	rend()	const	{ return (const_reverse_iterator(begin())); }
		iterator				begin()			{ return (iterator(__begin_)); }
		const_iterator			begin() const	{ return (const_iterator(__begin_)); }
		iterator				end()			{ return (iterator(__end_)); }
		const_iterator			end() const		{ return (const_iterator(__end_)); }

		size_type	max_size() const { return (__alloc_.max_size()); }
		size_type	capacity() const { return (__capacity_); }

	private:
		pointer			__begin_;
		pointer 		__end_;
		allocater_type	__alloc_;
		size_type		__capacity_;
	};
	
} // ft

# endif