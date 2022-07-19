/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __tree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/19 15:44:02 by mannouao         ###   ########.fr       */
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
			color_type	color;
			void*		parent;
			void*       left;
			void*		right;
			value_type	value:
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
		typedef ft::__map_iter<pointer, node*>						iterator;
		typedef ft::__map_iter<, const node*>					const_iterator;
	};

} // ft

# endif