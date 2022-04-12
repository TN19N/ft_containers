/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:01:29 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/12 02:05:28 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

# define VECTOR_HPP

# include <memory>

namespace ft
{

template<class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef	T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		// ...
		// ...
		// ...
		// ...
		typedef typename allocator_type::size_type			size_type;
    	typedef typename allocator_type::difference_type	difference_type;
	
	
};

} // ft

#endif