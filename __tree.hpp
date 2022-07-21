/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __tree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/21 14:09:29 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* READ-BLACK-TREE */

# ifndef __TREE_HPP
# define __TREE_HPP

# include "iterator.hpp"
# include <memory>

namespace ft
{

	template<class key_type, class mapped_type, class value_type, class key_compare, class allocator_type>
	class tree
	{
	private:
		enum color_type : bool { RED, BLACK };
		struct node {
			color_type	__color_;
			void*		__parent_;
			void*		__left_;
			void*		__right_;
			value_type	*__value_:

			node(color_type c, void* p, void* l, void* r)
				: __color_(c),
				  __parent_(p),
				  __left_(l),
				  __right_(r)
			{}
		};
		allocator_type						value_alloc;
		allocator_type::rebind<node>::other	node_alloc;
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
		node* 			__end_;
		size_type		__count_;
		key_compare		__compar_;
	public:
		tree(const key_compare& comp, const allocator_type& alloc)
			: 
			  __NIL_(get_node(BLACK))
			  __head_(__NIL_),
			  __begin_(__NIL_),
			  __end_(__NIL_),
			  __count_(0),
			  __compar_(comp),
			  value_alloc(alloc)
		{}

		iterator begin() { return (iterator(__begin_)); }
		const_iterator begin() const { return (const_iterator(__begin_)); }
		iterator end() { return (iterator(__end_)); }
		const_iterator end() const { return (const_iterator(__end_)); }

	private:
		node*	get_node(color_type __c, void* p = NULL, void* l = NULL, void* r = NULL)
		{
			node*   __node;
			try { __node = node_alloc.allocate(1) } catch (const std::bad_alloc& e) { throw e; }
			node_alloc.construct(__node, node(__c, p, l, r));
			try { __node->__value_ = value_alloc.allocate(1) } catch (const std::bad_alloc& e) { throw e; };
			
		}
	};

} // ft

# endif