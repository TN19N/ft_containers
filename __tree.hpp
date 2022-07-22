/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __tree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/22 10:31:47 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* READ-BLACK-TREE */

# ifndef __TREE_HPP
# define __TREE_HPP

# include "iterator.hpp"
# include <memory>

namespace ft
{

	const bool RED = 0;
	const bool BLACK = 1;

	template<class key_type, class mapped_type, class value_type, class value_compare, class allocator_type>
	class tree
	{
	private:
		struct node {
			bool		__color_;
			void*		__parent_;
			void*		__left_;
			void*		__right_;
			value_type	*__value_;

			node(bool c, void* p, void* l, void* r)
				: __color_(c),
				  __parent_(p),
				  __left_(l),
				  __right_(r)
			{}
		};
		typename allocator_type::template rebind<node>::other	node_alloc;
		allocator_type											value_alloc;
	public:
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type			size_type;
		typedef ft::__map_iter<pointer, node*>				iterator;
		typedef ft::__map_iter<const_pointer, const node*>	const_iterator;
	private:
		node*			__NIL_;
		node*			__head_;
		node*			__begin_;
		size_type		__count_;
		value_compare	__compar_;
	public:
		tree(const value_compare& comp, const allocator_type& alloc)
			: 
			  value_alloc(alloc),
			  __count_(0),
			  __compar_(comp)
		{
			try { __NIL_ = __head_ = __begin_ = get_node(BLACK); } catch (const std::bad_alloc& e) { throw e; }
		}

		iterator begin() { return (iterator(__begin_)); }
		const_iterator begin() const { return (const_iterator(__begin_)); }
		iterator end() { return (iterator(__NIL_)); }
		const_iterator end() const { return (const_iterator(__NIL_)); }

		//iterator lower_bound()

		iterator find(const key_type& __k)
		{
			
		}

	private:
		node*	get_node(bool __c, const value_type val = value_type(), void* p = NULL, void* l = NULL, void* r = NULL)
		{
			node*	__node;
			try { __node = node_alloc.allocate(1); } catch (const std::bad_alloc& e) { throw e; }
			node_alloc.construct(__node, node(__c, p, l, r));
			try { __node->__value_ = value_alloc.allocate(1); } catch (const std::bad_alloc& e) { throw e; };
			value_alloc.construct(__node->__value_, val);
			return (__node);
		}
	};

} // ft

# endif