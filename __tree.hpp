/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __tree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/25 13:58:05 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* READ-BLACK-TREE */

# ifndef __TREE_HPP
# define __TREE_HPP

# include "iterator.hpp"
# include "utility.hpp"
# include <memory>

namespace ft
{

	const bool RED = 0;
	const bool BLACK = 1;

	template<class key_type, class mapped_type, class value_type, class key_compare , class allocator_type>
	class tree
	{
	private:
		struct node {
			bool			__color_;
			node*			__parent_;
			node*			__left_;
			node*			__right_;
			value_type		*__value_;

			node(bool c, node* p, node* l, node* r)
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
		size_type		__size_;
		key_compare		__compar_;
	public:
		tree(const key_compare& comp, const allocator_type& alloc)
			: 
			  value_alloc(alloc),
			  __size_(0),
			  __compar_(comp)
		{
			try { __NIL_ = __head_ = __begin_ = get_node(BLACK); } catch (const std::bad_alloc& e) { throw e; }
		}

		iterator 		begin() 		{ return iterator(__begin_); }
		const_iterator 	begin() const 	{ return const_iterator(__begin_); }
		iterator 		end() 			{ return iterator(__NIL_); }
		const_iterator 	end() 	const 	{ return const_iterator(__NIL_); }

		iterator lower_bound(const key_type& __k, node** parent = NULL)
		{
			node* __tmp = __head_;
			node* __res = __NIL_;

			while (__tmp != NULL && __tmp != __NIL_)
			{
				if (parent != NULL)
					*parent = __tmp;
				if (!__compar_(__tmp->__value_->first, __k))
				{
					__res = __tmp;
					__tmp = __tmp->__left_;
				}
				else
					__tmp = __tmp->__right_;
			}
			return iterator(__res);
		}

		iterator upper_bound(const key_type& __k)
		{
			node* __tmp = __head_;
			node* __res = __NIL_;

			while (__tmp != NULL)
			{
				if (__compar_(__k, __tmp->__value_->first))
				{
					__res = __tmp;
					__tmp = __tmp->__left_;
				}
				else
					__tmp = __tmp->__right_;
			}
			return iterator(__res);
		}

		iterator find(const key_type& __k, node** parent = NULL)
		{
			iterator __p = lower_bound(__k, parent);
			if (__p != end() && !__compar_(__k, __p->first))
				return __p;
			return end();
		}

		void clear()
		{
			destroy(__head_);
			__size_ = 0;
			__NIL_->__parent_ = NULL;
			__head_ = __begin_ = __NIL_;
		}

		key_compare 	key_comp()  const 		{ return __compar_; }
		key_compare& 	key_comp()   			{ return __compar_; }
		size_type		size() 	    const		{ return __size_; }
		size_type		max_size()  const		{ return value_alloc.max_size(); }
		allocator_type	get_alloc() const		{ return value_alloc; }

		void swap(tree& __x)
		{
			ft::swap(__head_, __x.__head_);
			ft::swap(__begin_, __x.__begin_);
			ft::swap(__size_, __x.__size_);
			ft::swap(__NIL_, __x.__NIL_);
			ft::swap(__compar_, __x.__compar_);
		}

		ft::pair<iterator, bool> insert(const value_type& __v)
		{
			if (__head_ == __NIL_)
			{
				__begin_ = __head_ = get_node(BLACK, __v);
				__NIL_->__parent_ = __head_;
				__head_->__right_ = __NIL_;
				++__size_;
				return (ft::make_pair(iterator(__head_), true));
			}

			node  *parent;
			node* __holder;
			iterator __p = find(__v.first, &parent);
	
			if (__p != end())
				return ft::make_pair(__p, false);
	
			__holder = get_node(RED, __v);
			__holder->__parent_ = parent;

			if (__compar_(__v.first, parent->__value_->first))
			{
				parent->__left_ = __holder;
				if (__begin_ == parent)
					__begin_ = __holder;
			}
			else
			{
				parent->__right_ = __holder;
				if (__NIL_->__parent_ == parent)
				{
					__NIL_->__parent_ = __holder;
					__holder->__right_ = __NIL_;
				}
			}
			balance(__holder);
			++__size_;
			return ft::make_pair(iterator(__holder), true);
		}

		iterator insert(iterator __hint, const value_type& __v)
		{
			if (__head_ == __NIL_)
			{
				__begin_ = __head_ = get_node(BLACK, __v);
				__NIL_->__parent_ = __head_;
				__head_->__right_ = __NIL_;
				++__size_;
				return (iterator(__head_));
			}

			node  	*parent = NULL;
			node* 	 __holder;
			iterator __p = end();

			if (key_comp(__v.first, __hint->first))
			{
				iterator pre(__hint);
				if ((__hint == begin() || key_comp((--pre)->first, __v.first)) && __hint.base()->__left_ == NULL)
					parent = __hint.base();
				else
					__p = find(__v.first, &parent);
			}
			else if (key_comp(__hint->first, __v.first))
			{
				iterator next(__hint);
				++next;
				if ((next == begin() || key_comp(__v.first, next->first)) && (__hint.base()->__right_ == NULL || __hint.base()->__right_ == __NIL_))
					parent = __hint.base();
				else
					__p = find(__v.first, &parent);
			}
			else
				return (iterator(__hint));

			if (__p != end())
				return end();
	
			__holder = get_node(RED, __v);
			__holder->__parent_ = parent;

			if (__compar_(__v.first, parent->__value_->first))
			{
				parent->__left_ = __holder;
				if (__begin_ == parent)
					__begin_ = __holder;
			}
			else
			{
				parent->__right_ = __holder;
				if (__NIL_->__parent_ == parent)
				{
					__NIL_->__parent_ = __holder;
					__holder->__right_ = __NIL_;
				}
			}
			balance(__holder);
			++__size_;
			return iterator(__holder);
		}

	private:
		node*	get_node(bool __c, const value_type val = value_type(), node* p = NULL, node* l = NULL, node* r = NULL)
		{
			node*	__node;
			try { __node = node_alloc.allocate(1); } catch (const std::bad_alloc& e) { throw e; }
			node_alloc.construct(__node, node(__c, p, l, r));
			try { __node->__value_ = value_alloc.allocate(1); } catch (const std::bad_alloc& e) { throw e; };
			value_alloc.construct(__node->__value_, val);
			return (__node);
		}

		void destroy(node* __p)
		{
			if (__p != NULL && __p != __NIL_)
			{
				destroy(__p->__left_);
				destroy(__p->__right_);
				value_alloc.destroy(__p->__value_);
				value_alloc.deallocate(__p->__value_, 1);
				value_alloc.destroy(__p);
				value_alloc.deallocate(__p, 1);
			}
		}

		void left_rotate(node* __x)
		{
			node*	__y = __x->__right_;
			__x->__right_ = __y->__left_;
			if (__x->__right_ != NULL)
				__x->__right_->__parent_ = __x;
			__y->__parent_ = __x->__parent_;

			if (__y == __NIL_->__parent_)
				__NIL_->__parent_ = __x;

			if (__x->__parent_ == NULL)
				__head_ = __y;
			else if (__x->__parent_->__left_ == __x)
				__x->__parent_->__left_ = __y;
			else
				__x->__parent_->__right_ = __y;

			__y->__left_ = __x;
			__x->__parent_ = __y;
		}

		void right_rotate(node* __x)
		{
			node*	__y = __x->__left_;
			__x->__left_ = __y->__right_;
			if (__x->__left_ != NULL)
				__x->__left_->__parent_ = __x;
			__y->__parent_ = __x->__parent_;
			
			if (__begin_ == __y)
				__begin_ = __x;

			if (__x->__parent_ == NULL)
				__head_ = __y;
			else if (__x->__parent_->__right_ == __x)
				__x->__parent_->__right_ = __y;
			else
				__x->__parent_->__left_ = __y;
			
			__y->__right_ = __x;
			__x->__parent_ = __y;
		}

		void balance(node* __x)
		{
			while (__x != __head_ && __x->__parent_->__color_ == RED)
			{
				if (__x->__parent_ == __x->__parent_->__parent_->__left_)
				{
					node *__p = __x->__parent_->__parent_->__right_;
					if (__p != NULL && __p->__color_ == RED)
					{
						__x = __x->__parent_;
						__x->__color_ = BLACK;
						__x = __p->__parent_;
						if (__x != __head_)
							__x->__color_ = RED;
						__p->__color_ = BLACK;
					}
					else
					{
						if (__x == __x->__parent_->__right_)
						{
							__x = __x->__parent_;
							left_rotate(__x);
						}
						__x = __x->__parent_;
						__x->__color_ = BLACK;
						__x = __x->__parent_;
						__x->__color_ = RED;
						right_rotate(__x);
						break ;
					}
				}
				else
				{
					node *__p = __x->__parent_->__parent_->__left_;
					if (__p != NULL && __p->__color_ == RED)
					{
						__x = __x->__parent_;
						__x->__color_ = BLACK;
						__x = __p->__parent_;
						if (__x != __head_)
							__x->__color_ = RED;
						__p->__color_ = BLACK;
					}
					else
					{
						if (__x == __x->__parent_->__left_)
						{
							__x = __x->__parent_;
							right_rotate(__x);
						}
						__x = __x->__parent_;
						__x->__color_ = BLACK;
						__x = __x->__parent_;
						__x->__color_ = RED;
						left_rotate(__x);
						break ;
					}
				}
			}
		}
	};

} // ft

# endif