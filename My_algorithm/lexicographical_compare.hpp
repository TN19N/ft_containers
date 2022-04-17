/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:38:23 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/16 15:46:53 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_HPP

# define LEX_HPP

namespace ft
{

template<typename Iterator1, typename Iterator2>
bool lexicographical_compare(Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first2 > *first1)
			return (true);
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template<typename Iterator1, typename Iterator2, typename F>
bool lexicographical_compare(Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2, F f)
{
	while (first1 != last1)
	{
		if (first2 == last2 || f(*first2, *first1))
			return (false);
		else if (f(*first1, *first2))
			return (true);
		++first1;
		++first2;
	}
	return (first2 != last2);
}

} // ft

#endif