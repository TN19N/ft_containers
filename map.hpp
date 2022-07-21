/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:26:09 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/21 11:27:49 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
# define MAP_HPP

# include "__tree.hpp"
# include "utility.hpp"
# include <memory>

namespace ft
{
	template<class _Key, class _Tp, class _Compare = std::less<_Key>,
			 class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{
	public:
		typedef _Key									Key_type;
		typedef _Tp										mapped_type;
		typedef ft::pair<const Key_type, mapped_type>	value_type;
		typedef _Compare								key_compare;
		typedef _Allocator								allocator_type;

		class value_compare 
			: public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		protected:
			key_compare comp;

			value_compare(key_compare c) : comp(c) {}
		public:
			bool operator () (const value_type& __x, const value_type& __y) const
			{ return(comp(__x.first, __y.first)); }
		};
	private:
		typedef ft::tree<key_type, mapped_type, value_type, key_compare, allocator_type> tree_type;
		tree_type	__tree_;
	public:
		typedef typename tree_type::reference				reference;
		typedef typename tree_type::const_reference			const_reference;
		typedef typename tree_type::pointer					pointer;
		typedef typename tree_type::const_pointer			const_pointer;
		typedef typename tree_type::difference_type			difference_type;
		typedef typename tree_type::size_type				size_type;
		typedef typename tree_type::iterator				iterator;
		typedef typename tree_type::const_iterator			const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: __tree_(comp, alloc)
		{}

		template<class _Iter>
		map(_Iter first, _Iter secend, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: __tree_(comp, alloc)
		{
			insert(first, secend);
		}
		
		iterator 				begin() 		{ return (__tree_.begin()); }
		const_iterator			begin()  const	{ return (__tree_.begin()); }
		iterator 				end() 			{ return (__tree_.end()); }
		const_iterator			end()	 const	{ return (__tree_.end()); }
		reverse_iterator 		rbegin() 		{ return (reverse_iterator(end())); }
		const_reverse_iterator	rbegin() const	{ return (const_reverse_iterator(end())); }
		reverse_iterator 		rend() 			{ return (reverse_iterator(begin())); }
		const_reverse_iterator	rend()	 const	{ return (const_reverse_iterator(begin())); }

		pair<iterator, bool> insert(const value_type& val)
		{ return (__tree_.__insert(val)); }

		iterator insert(iterator __p, const value_type& val)
		{ return (__tree_.__insert(__p, val)); }

		template<class _Iter>
		void insert(_Iter first, _Iter last)
		{
			for (iterator __e = end(), first != last, ++first)
				insert(__e, *first);	
		}
	};

} // ft

# endif