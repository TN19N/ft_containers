/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:27:20 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/14 21:43:13 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP

# define IS_INTEGRAL_HPP

# include <type_traits>

namespace ft
{

typedef std::integral_constant<bool, true>  true_type;
typedef std::integral_constant<bool, false> false_type;

template <class _Tp> struct tmp_template                     : public false_type {};
template <>          struct tmp_template<bool>               : public true_type {};
template <>          struct tmp_template<char>               : public true_type {};
template <>          struct tmp_template<signed char>        : public true_type {};
template <>          struct tmp_template<unsigned char>      : public true_type {};
template <>          struct tmp_template<wchar_t>            : public true_type {};
template <>          struct tmp_template<short>              : public true_type {};
template <>          struct tmp_template<unsigned short>     : public true_type {};
template <>          struct tmp_template<int>                : public true_type {};
template <>          struct tmp_template<unsigned int>       : public true_type {};
template <>          struct tmp_template<long>               : public true_type {};
template <>          struct tmp_template<unsigned long>      : public true_type {};
template <>          struct tmp_template<long long>          : public true_type {};
template <>          struct tmp_template<unsigned long long> : public true_type {};


template<typename T>
struct is_integral : public tmp_template<typename std::remove_cv<T>::type> {};

} // ft

#endif