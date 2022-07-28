/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __tree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/28 15:38:04 by mannouao         ###   ########.fr       */
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

	template<class key_type, class value_type, class value_compare , class allocator_type>
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
		typedef ft::__map_iter<const_pointer, node*>		const_iterator;
	private:
		node*			__NIL_;
		node*			__head_;
		node*			__begin_;
		size_type		__size_;
		value_compare	__compar_;
	public:
		tree(const value_compare& comp, const allocator_type& alloc)
			: 
			  value_alloc(alloc),
			  __size_(0),
			  __compar_(comp)
		{
			try { __NIL_ = __head_ = __begin_ = get_node(BLACK); } catch (const std::bad_alloc& e) { throw e; }
		}

		tree(const tree& __x)
			: value_alloc(__x.value_alloc),
			  __size_(0),
			  __compar_(__x.__compar_)
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
				if (!__compar_(*(__tmp->__value_), __k))
				{
					__res = __tmp;
					__tmp = __tmp->__left_;
				}
				else
					__tmp = __tmp->__right_;
			}
			return iterator(__res);
		}

		const_iterator lower_bound(const key_type& __k, node** parent = NULL) const
		{
			node* __tmp = __head_;
			node* __res = __NIL_;

			while (__tmp != NULL && __tmp != __NIL_)
			{
				if (parent != NULL)
					*parent = __tmp;
				if (!__compar_(*(__tmp->__value_), __k))
				{
					__res = __tmp;
					__tmp = __tmp->__left_;
				}
				else
					__tmp = __tmp->__right_;
			}
			return const_iterator(__res);
		}

		iterator upper_bound(const key_type& __k)
		{
			node* __tmp = __head_;
			node* __res = __NIL_;

			while (__tmp != NULL)
			{
				if (__compar_(__k, *(__tmp->__value_)))
				{
					__res = __tmp;
					__tmp = __tmp->__left_;
				}
				else
					__tmp = __tmp->__right_;
			}
			return iterator(__res);
		}

		const_iterator upper_bound(const key_type& __k) const
		{
			node* __tmp = __head_;
			node* __res = __NIL_;

			while (__tmp != NULL)
			{
				if (__compar_(__k, *(__tmp->__value_)))
				{
					__res = __tmp;
					__tmp = __tmp->__left_;
				}
				else
					__tmp = __tmp->__right_;
			}
			return const_iterator(__res);
		}

		iterator find(const key_type& __k, node** parent = NULL)
		{
			iterator __p = lower_bound(__k, parent);
			if (__p != end() && !__compar_(__k, *__p))
				return __p;
			return end();
		}

		const_iterator find(const key_type& __k, node** parent = NULL) const
		{
			const_iterator __p = lower_bound(__k, parent);
			if (__p != end() && !__compar_(__k, *__p))
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

		value_compare 	value_comp()    const 	{ return __compar_; }
		value_compare& 	value_comp()   			{ return __compar_; }
		size_type		size() 	        const	{ return __size_; }
		size_type		max_size()      const	{ return value_alloc.max_size(); }
		allocator_type	get_allocator() const	{ return value_alloc; }

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
			iterator __p = find(__get_key(__v), &parent);
	
			if (__p != end())
				return ft::make_pair(__p, false);
	
			__holder = get_node(RED, __v);
			__holder->__parent_ = parent;

			if (__compar_(__v, *(parent->__value_)))
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

			if (__compar_(__get_key(__v), *__hint))
			{
				iterator pre(__hint);
				if ((__hint == begin() || __compar_(*--pre, __get_key(__v))) && __hint.base()->__left_ == NULL)
					parent = __hint.base();
				else
					__p = find(__get_key(__v), &parent);
			}
			else if (__compar_(*__hint, __get_key(__v)))
			{
				iterator next(__hint);
				++next;
				if ((next == end() || __compar_(__get_key(__v), *next)) && check_right(__hint.base()))
					parent = __hint.base();
				else
					__p = find(__get_key(__v), &parent);
			}
			else
				return (iterator(__hint));

			if (__p != end())
				return end();
	
			__holder = get_node(RED, __v);
			__holder->__parent_ = parent;

			if (__compar_(__get_key(__v), *(parent->__value_)))
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

		void erase(iterator __pos)
		{
			node* __p = __pos.base();
			while(__p->__left_ != NULL || !check_right(__p))
			{
				node* __old =  __p;
				if (__p->__left_ != NULL)
					__p = max_child(__p->__left_);
				else
					__p = min_child(__p->__right_);
				ft::swap(__old->__value_, __p->__value_);
			}
			node *to_delet = __p;
			
			if (__p->__color_ == RED || __p == __head_)
				destroy_node(__p);
			else
			{		
				while (__p != __head_)
				{
					if (__p == __p->__parent_->__left_)
					{
						node *__sib = __p->__parent_->__right_;
						if (check_right(__p->__parent_) || __sib->__color_ == BLACK)
						{
							if (!check_right(__p->__parent_) &&  !check_right(__sib) && __sib->__right_->__color_ == RED)
							{
								ft::swap(__sib->__color_, __p->__parent_->__color_);
								left_rotate(__p->__parent_);
								__sib->__right_->__color_ = BLACK ;
								if (__p == to_delet)
									destroy_node(to_delet);
								break ;
							}
							else if (!check_right(__p->__parent_) && __sib->__left_ != NULL && __sib->__left_->__color_ == RED)
							{
								__sib->__left_->__color_ = BLACK;
								__sib->__color_ = RED;
								right_rotate(__sib);
							}
							else
							{
								if (!check_right(__p->__parent_))
									__sib->__color_ = RED;
								if (__p == to_delet)
								{
									__p = __p->__parent_;
									destroy_node(to_delet);
								}
								else
									__p = __p->__parent_;
								if (__p->__color_ == RED)
								{
									__p->__color_ = BLACK;
									break ;
								} 
							}
						}
						else
						{
							__p->__parent_->__color_ = RED;
							if (!check_right(__p->__parent_))
								__sib->__color_ = BLACK;
							left_rotate(__p->__parent_);
						}
					}
					else
					{
						node *__sib = __p->__parent_->__left_;
						if (__sib == NULL || __sib->__color_ == BLACK)
						{
							if (__sib != NULL && __sib->__left_ != NULL && __sib->__left_->__color_ == RED)
							{
								ft::swap(__sib->__color_, __p->__parent_->__color_);
								right_rotate(__p->__parent_);
								__sib->__left_->__color_ = BLACK;
								if (__p == to_delet)
									destroy_node(to_delet);
							}
							else if (__sib != NULL && !check_right(__sib) && __sib->__right_->__color_ == RED)
							{
								__sib->__right_->__color_ = BLACK;
								__sib->__color_ = RED;
								left_rotate(__sib);
							}
							else
							{
								if (__sib != NULL)
									__sib->__color_ = RED;
								if (__p == to_delet)
								{
									__p = __p->__parent_;
									destroy_node(to_delet);
								}
								else
									__p = __p->__parent_;
								if (__p->__color_ == RED)
								{
									__p->__color_ = BLACK;
									break ;
								}
							}
						}
						else
						{
							__p->__parent_->__color_ = RED;
							if (__sib != NULL)
								__sib->__color_ = BLACK;
							right_rotate(__p->__parent_);
						}
					}
				}
			}
			--__size_;
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
				node_alloc.destroy(__p);
				node_alloc.deallocate(__p, 1);
			}
		}

		void destroy_node(node *__p)
		{
			if (__begin_ == __p)
				__begin_ = __p->__parent_ ? __p->__parent_ : __NIL_;
			if (__NIL_->__parent_ == __p)
			{
				__NIL_->__parent_ = __p->__parent_;
				if (__p->__parent_ != NULL)
					__p->__parent_->__right_ = __NIL_;
			}
			if (__head_ == __p)
				__head_ = __NIL_;
			else
			{
				if (__p == __p->__parent_->__right_)
					__p->__parent_->__right_ = __p->__right_;
				else
					__p->__parent_->__left_ = __p->__left_;
			}

			value_alloc.destroy(__p->__value_);
			value_alloc.deallocate(__p->__value_, 1);
			node_alloc.destroy(__p);
			node_alloc.deallocate(__p, 1);
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

		bool check_right(node *__p)
		{
			return (__p->__right_ == NULL || __p->__right_ == __NIL_);
		}

		node* min_child(node *__p)
		{
			while (__p->__left_ != NULL)
				__p = __p->__left_;
			return (__p);
		}

		node* max_child(node *__p)
		{
			while (!check_right(__p))
				__p = __p->__right_;
			return (__p);
		}
		
		const key_type __get_key(const value_type& __p)
		{ return (__p.first); }
	};

} // ft

# endif