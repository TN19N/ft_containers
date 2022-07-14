/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:10:38 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/14 14:48:41 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

# include "algorithm.hpp"

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
	};
	
} // ft

# endif