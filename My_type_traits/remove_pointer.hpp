/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_pointer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:17:20 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/16 23:18:44 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef REMOVE_POINTER_HPP

# define REMOVE_POINTER_HPP

/*
	remove pointer from the type , Otherwise leave the type as it is.
*/

namespace ft
{

template <class _Tp> struct remove_pointer                      {typedef _Tp type;};
template <class _Tp> struct remove_pointer<_Tp*>                {typedef _Tp type;};
template <class _Tp> struct remove_pointer<_Tp* const>          {typedef _Tp type;};
template <class _Tp> struct remove_pointer<_Tp* volatile>       {typedef _Tp type;};
template <class _Tp> struct remove_pointer<_Tp* const volatile> {typedef _Tp type;};

} // ft

#endif