/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:26:09 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/19 14:37:57 by mannouao         ###   ########.fr       */
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
		tree_type	__tree;
	public:
		typedef typename tree_type::reference				reference;
		typedef typename tree_type::const_reference			const_reference;
		typedef typename tree_type::pointer					pointer;
		typedef typename tree_type::const_pointer			const_pointer;
		typedef typename tree_type::difference_type			difference_type;
		typedef typename tree_type::size_type				size_type;
		typedef typename tree_type::iterator				iterator;
		typedef typename tree_type::const_iterator			const_iterator;
		typedef typename tree_type::reverse_iterator		reverse_iterator;
		typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

	};

} // ft

# endif