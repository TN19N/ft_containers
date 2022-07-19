/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __tree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/19 11:49:09 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* READ-BLACK-TREE */

# ifndef __TREE_HPP
# define __TREE_HPP

namespace ft
{

	template<class value_type, class key_compare, class allocator_type>
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
	};

} // ft

# endif