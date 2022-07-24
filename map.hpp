/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:26:09 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/24 17:06:59 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
# define MAP_HPP

# include "__tree.hpp"
# include "utility.hpp"
# include "algorithm.hpp"
# include <memory>

namespace ft
{

	// map ----------------------------------------------------------------------------------------------------------------------
	template<class _Key, class _Tp, class _Compare = std::less<_Key>,
			 class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{
	public:
		typedef _Key									key_type;
		typedef _Tp										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
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
			{ return comp(__x.first, __y.first); }
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
		{ insert(first, secend); }

		map(const map& __x) : __tree_(__x.__tree_)
		{ insert(__x.begin(), __x.end()); }

		map& operator = (const map& __x)
		{
			if (this != &__x)
			{
				__tree_.clear();
				__tree_.value_comp() = __x.__tree_.value_comp();
				insert(__x.begin(), __x.end());
			}
			return *this;
		} 
		
		iterator 				begin() 		{ return __tree_.begin(); }
		const_iterator			begin()  const	{ return __tree_.begin(); }
		iterator 				end() 			{ return __tree_.end(); }
		const_iterator			end()	 const	{ return __tree_.end(); }
		reverse_iterator 		rbegin() 		{ return reverse_iterator(end()); }
		const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(end()); }
		reverse_iterator 		rend() 			{ return reverse_iterator(begin()); }
		const_reverse_iterator	rend()	 const	{ return const_reverse_iterator(begin()); }

		

		iterator		lower_bound(const key_type& __k) 	   { return __tree_.lower_bound(__k); }
		const_iterator	lower_bound(const key_type& __k) const { return __tree_.lower_bound(__k); }

		iterator		upper_bound(const key_type& __k) 	   { return __tree_.upper_bound(__k); }
		const_iterator	upper_bound(const key_type& __k) const { return __tree_.upper_bound(__k); }
		
		iterator 		find(const key_type& __k) 		{ return __tree_.find(__k); }
		const_iterator 	find(const key_type& __k) const { return __tree_.find(__k); }

		bool			empty() 		const { return __tree_.size() == 0; }
		size_type		size() 			const { return __tree_.size(); }
		size_type		max_size() 		const { return __tree_.max_size(); }
		allocator_type 	get_allocator() const { return __tree_.get_allocator(); }
		key_compare		key_comp()		const { return __tree_.key_comp(); }
		value_compare	value_comp()	const { return value_compare(key_comp()); }

		ft::pair<iterator, bool> insert(const value_type& val) 				 { return __tree_.insert(val); }
		iterator			 	 insert(iterator __p, const value_type& val) { return __tree_.__insert(__p, val); }
		template<class _Iter>
		void insert(_Iter first, _Iter last)
		{
			for (; first != last; ++first)
				insert(*first);
		}

		// void 		erase(iterator __pos) 				 { return __tree_.erase(__pos); }
		// size_type	erase(const Key_type& __k) 			 { return __tree_.erase(find(__k)); }
		// void		erase(iterator first, iterator last)
		// {
		// 	for (; first != last; ++first)
		// 		__tree_.erase(first);
		// }

		void 		swap(map& __x) 					 { __tree_.swap(__x.__tree_); }
		void 		clear() 						 { __tree_.clear(); }
		size_type 	count(const key_type& __k) const { return find(__k) != end(); }

		ft::pair<iterator, iterator> equal_range(const key_type& __k)
		{
			iterator __p = find(__k);
			if (__p == end())
				return ft::make_pair(__p, __p);
			else
				return ft::make_pair(__p++, __p);
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& __k) const
		{
			const_iterator __p = find(__k);
			if (__p == end())
				return ft::make_pair(__p, __p);
			else
				return ft::make_pair(__p++, __p);
		}

		mapped_type& operator[] (const key_type& __k) { return insert(ft::make_pair(__k, mapped_type())).first->second; }
	};

	template<class _Key, class _Tp, class _Compare, class _Allocator>
	bool operator == (const map<_Key, _Tp, _Compare, _Allocator>& __x,
	                  const map<_Key, _Tp, _Compare, _Allocator>& __y)
	{ return __x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin()); }

	template<class _Key, class _Tp, class _Compare, class _Allocator>
	bool operator < (const map<_Key, _Tp, _Compare, _Allocator>& __x,
	                 const map<_Key, _Tp, _Compare, _Allocator>& __y)
	{ return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end()); }

	template<class _Key, class _Tp, class _Compare, class _Allocator>
	bool operator != (const map<_Key, _Tp, _Compare, _Allocator>& __x,
	                  const map<_Key, _Tp, _Compare, _Allocator>& __y)
	{ return !(__x == __y); }

	template<class _Key, class _Tp, class _Compare, class _Allocator>
	bool operator > (const map<_Key, _Tp, _Compare, _Allocator>& __x,
	                 const map<_Key, _Tp, _Compare, _Allocator>& __y)
	{ return __y < __x; }

	template<class _Key, class _Tp, class _Compare, class _Allocator>
	bool operator >= (const map<_Key, _Tp, _Compare, _Allocator>& __x,
	                  const map<_Key, _Tp, _Compare, _Allocator>& __y)
	{ return !(__x < __y); }

	template<class _Key, class _Tp, class _Compare, class _Allocator>
	bool operator <= (const map<_Key, _Tp, _Compare, _Allocator>& __x,
	                  const map<_Key, _Tp, _Compare, _Allocator>& __y)
	{ return !(__y < __x); }

	template<class _Key, class _Tp, class _Compare, class _Allocator>
	void swap(map<_Key, _Tp, _Compare, _Allocator>& __x,
	          map<_Key, _Tp, _Compare, _Allocator>& __y)
	{ __x.swap(__y); }
	// --------------------------------------------------------------------------------------------------------------------------

} // ft

# endif