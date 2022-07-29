/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:10:38 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/29 14:56:43 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterator.hpp"
# include "type_traits.hpp"
# include "algorithm.hpp"
# include "utility.hpp"
# include <memory>
# include <stdexcept>

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
				if(__n > max_size()) std::__throw_length_error("vector");
				__begin_ = __end_ = __alloc_.allocate(__n);
				for (; __capacity_ < __n ; ++__capacity_) __alloc_.construct(__end_++, val);
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
				if(__n > max_size()) std::__throw_length_error("vector");
				__begin_ = __end_ = __alloc_.allocate(__n);
				for (; first != secend ; ++first, ++__capacity_) __alloc_.construct(__end_++, *first);
			}
		}

		vector(const vector& other)
			: __begin_(NULL),
			  __end_(NULL),
			  __capacity_(0),
			  __alloc_(other.get_allocator())
		{
			if (other.size() > 0)
			{
				if(other.size() > max_size()) std::__throw_length_error("vector");
				__begin_ = __end_ = __alloc_.allocate(other.size());
				for (size_type i = 0; i < other.size(); ++i, ++__capacity_) __alloc_.construct(__end_++, other[i]);
			}
		}

		vector& operator = (const vector& other)
		{
			if (this != &other)
				assign(other.begin(), other.end());
			return *this;
		}

		~vector() { clear(); if(__begin_) __alloc_.deallocate(__begin_, __capacity_); }

		reverse_iterator		rbegin()		{ return reverse_iterator(end()); }
		const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(end()); }
		reverse_iterator		rend()			{ return reverse_iterator(begin()); }
		const_reverse_iterator	rend()   const	{ return const_reverse_iterator(begin()); }
		iterator				begin()			{ return iterator(__begin_); }
		const_iterator			begin()  const	{ return const_iterator(__begin_); }
		iterator				end()			{ return iterator(__end_); }
		const_iterator			end()    const	{ return const_iterator(__end_); }

		size_type		max_size() 		const { return __alloc_.max_size(); }
		size_type		capacity() 		const { return __capacity_; }
		size_type		size() 			const { return static_cast<size_type>(ft::distance(__begin_, __end_)); }
		bool			empty()			const { return size() == 0; };
		allocater_type	get_allocator() const { return __alloc_; }

		void clear() { while ( __end_ != __begin_ ) __alloc_.destroy(--__end_); }

		void push_back(const value_type& val)
		{
			if (__capacity_ == size()) reserve(__capacity_ ? __capacity_ * 2 : 1);
			__alloc_.construct(__end_++, val);
		}

		void pop_back() { if(!empty()) __alloc_.destroy(--__end_); }

		void reserve(size_type __n)
		{
			if (__n > __capacity_)
			{
				if(__n > max_size()) std::__throw_length_error("vector");
				vector __tmp(*this);
				clear();
				if (__begin_ != NULL) __alloc_.deallocate(__begin_, __capacity_);
				__begin_ = __end_ = __alloc_.allocate(__n);
				__capacity_ = __n;
				for (size_type i = 0; i < __tmp.size(); ++i) __alloc_.construct(__end_++, __tmp[i]);
			}
		}

		void resize(size_type __n, value_type val = value_type())
		{
			size_type __cs = size();

			if 		(__n < __cs) while (__end_ != __begin_ + __n) __alloc_.destroy(--__end_);
			else if (__n > __cs)
			{
				if (__n > __capacity_) reserve(__n > __capacity_ * 2 ? __n : __capacity_ * 2);
				while (size() < __n) __alloc_.construct(__end_++, val);
			}
		}

		template<typename _Iter>
		void assign(_Iter _first, _Iter _last)
		{
			size_type __n = static_cast<size_type>(ft::distance(_first, _last));
			clear();
			if (__n > __capacity_) reserve(__n);
			while (_first != _last) __alloc_.construct(__end_++, *_first++);
		}

		void assign(size_type __n, const value_type& val)
		{
			clear();
			if (__n > __capacity_) reserve(__n);
			while (__n-- > 0) __alloc_.construct(__end_++, val);
		}

		reference 		front() 		{ return *__begin_; }
		const_reference front() const 	{ return *__begin_; }

		reference 		back() 			{ return *(__end_ - 1); }
		const_reference back()  const 	{ return *(__end_ - 1); }

		reference 		operator [] (size_type __n) 		{ return __begin_[__n]; }
		const_reference operator [] (size_type __n) const 	{ return __begin_[__n]; }
	
		reference 		at(size_type __n) 		{ if(__n >= size()) std::__throw_out_of_range("vector"); return __begin_[__n]; }
		const_reference at(size_type __n) const { if(__n >= size()) std::__throw_out_of_range("vector"); return __begin_[__n]; }

		iterator insert(iterator __pos, const value_type& val)
		{
			size_type __len = static_cast<size_type>(ft::distance(begin(), __pos));
			insert(__pos, 1, val);
			return begin() + __len;
		}

		void insert(iterator __pos, size_type __n, const value_type& val)
		{
			size_type __len = static_cast<size_type>(ft::distance(begin(), __pos));
			if(__n + size() > __capacity_ * 2) reserve(__n + __capacity_);
			else if (__n + size() > __capacity_) reserve(__capacity_ * 2);
			__pos = begin() + __len;
			for (iterator __tp = end(); __tp != __pos; --__tp)
			{
				__alloc_.construct(__tp.base() + __n - 1, *(__tp - 1));
				__alloc_.destroy(__tp.base() - 1);
			}
			for (size_type i = 0; i < __n; ++i, ++__end_)
				__alloc_.construct(__pos.base() + i, val);
		}

		template<typename _Iter>
		void insert(iterator __pos, _Iter __first, _Iter __last)
		{
			size_type __len = static_cast<size_type>(ft::distance(begin(), __pos));
			size_type __n = static_cast<size_type>(ft::distance(__first, __last));
			if(__n + size() > __capacity_ * 2) reserve(__n + __capacity_);
			else if (__n + size() > __capacity_) reserve(__capacity_ * 2);
			__pos = begin() + __len;
			for (iterator __tp = end(); __tp != __pos; --__tp)
			{
				__alloc_.construct(__tp.base() + __n - 1, *(__tp - 1));
				__alloc_.destroy(__tp.base() - 1);
			}
			for (size_type i = 0; i < __n; ++i, ++__end_, ++__first)
				__alloc_.construct(__pos.base() + i, *__first);
		}

		iterator erase(iterator __pos) { return (erase(__pos, __pos + 1)); }

		iterator erase(iterator __first, iterator __last)
		{
			for (iterator __tp = __first; __tp != __last; ++__tp)
				__alloc_.destroy(__tp.base());
			size_type __len = ft::distance(__last, end());
			for (size_type i = 0; i < __len; ++i)
			{
				__alloc_.construct(__first.base() + i, *(__last + i));
				__alloc_.destroy(__last.base() + i);
			}
			__end_ -= ft::distance(__first, __last);
			return __first;
		}

		void swap(vector& __x)
		{
			ft::swap(__begin_, __x.__begin_);
			ft::swap(__end_, __x.__end_);
			ft::swap(__capacity_, __x.__capacity_);
			ft::swap(__alloc_, __x.__alloc_);
		}
		
	private:
		pointer			__begin_;
		pointer 		__end_;
		size_type		__capacity_;
		allocater_type	__alloc_;
	};

	template<typename _Tp, typename _Allocater>
	bool operator == (const ft::vector<_Tp, _Allocater>& __x, const ft::vector<_Tp, _Allocater>& __y)
	{ return __x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin()); }

	template<typename _Tp, typename _Allocater>
	bool operator != (const ft::vector<_Tp, _Allocater>& __x, const ft::vector<_Tp, _Allocater>& __y)
	{ return !(__x == __y); }

	template<typename _Tp, typename _Allocater>
	bool operator < (const ft::vector<_Tp, _Allocater>& __x, const ft::vector<_Tp, _Allocater>& __y)
	{ return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end()); }

	template<typename _Tp, typename _Allocater>
	bool operator <= (const ft::vector<_Tp, _Allocater>& __x, const ft::vector<_Tp, _Allocater>& __y)
	{ return !(__y < __x); }

	template<typename _Tp, typename _Allocater>
	bool operator > (const ft::vector<_Tp, _Allocater>& __x, const ft::vector<_Tp, _Allocater>& __y)
	{ return __y < __x; }

	template<typename _Tp, typename _Allocater>
	bool operator >= (const ft::vector<_Tp, _Allocater>& __x, const ft::vector<_Tp, _Allocater>& __y)
	{ return !(__x < __y); }

	template<typename _Tp, typename _Allocater>
	void swap (ft::vector<_Tp, _Allocater>& __x, ft::vector<_Tp, _Allocater>& __y)
	{ __x.swap(__y); }
	
} // ft

# endif