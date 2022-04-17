/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:38:23 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/16 01:55:30 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP

# define EQUAL_HPP

namespace ft
{

// equality
template<typename Iterator1, typename Iterator2>
bool equal(Iterator1 first1, Iterator1 last1, Iterator2 first2)
{
	while (first1 != last1)
	{
	 	if(*first1 != *first2)
			return (false);
		++first1;
		++first2;
	}
	return (true);
}

// predicate
template<typename Iterator1, typename Iterator2, typename F>
bool equal(Iterator1 first1, Iterator1 last1, Iterator2 first2, F f)
{
	while (first1 != last1)
	{
		if(!f(*first1, *first2))
			return (false);
		++first1;
		++first2;
	}
	return (true);
}

} // ft

#endif