/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:08:44 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/13 18:50:11 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{

	// enable_if ---------------------------------------------------------------------------------------------------------------------------
	template <bool, typename _Tp = void> struct enable_if { };
	template <typename _Tp> struct enable_if<true, _Tp> { typedef _Tp type; };
	// -------------------------------------------------------------------------------------------------------------------------------------

	// integral_constant -------------------------------------------------------------------------------------------------------------------
	template<typename _Tp, _Tp __v>
	struct integral_constant
	{
		static const _Tp 			value = __v;
		typedef _Tp					value_type;
		typedef	integral_constant	type;
		operator value_type() const { return value; }
	};
	typedef ft::integral_constant<bool, true>	true_type; // true_type
	typedef ft::integral_constant<bool, false>	false_type; // false_type
	// -------------------------------------------------------------------------------------------------------------------------------------

	// remove_const ------------------------------------------------------------------------------------------------------------------------
	template<typename _Tp> struct remove_const { typedef _Tp type; };
	template<typename _Tp> struct remove_const <const _Tp> { typedef _Tp type; };
	// -------------------------------------------------------------------------------------------------------------------------------------

	// remove_volatile ---------------------------------------------------------------------------------------------------------------------
	template<typename _Tp> struct remove_volatile { typedef _Tp type; };
	template<typename _Tp> struct remove_volatile <volatile _Tp> { typedef _Tp type; };
	// -------------------------------------------------------------------------------------------------------------------------------------

	// remove_cv ---------------------------------------------------------------------------------------------------------------------------
	template<typename _Tp> struct remove_cv { typedef typename ft::remove_volatile<typename ft::remove_const<_Tp>::type>::type type; };
	// -------------------------------------------------------------------------------------------------------------------------------------

	// is_integral -------------------------------------------------------------------------------------------------------------------------
	template<typename _Tp> 	struct tmp_is_integral 						: public false_type {};
	template<>			   	struct tmp_is_integral<bool> 				: public true_type {};
	template<>			   	struct tmp_is_integral<char> 				: public true_type {};
	template<>			   	struct tmp_is_integral<signed char> 		: public true_type {};
	template<>			   	struct tmp_is_integral<unsigned char> 		: public true_type {};
	template<>			   	struct tmp_is_integral<wchar_t> 			: public true_type {};
	template<>			   	struct tmp_is_integral<char16_t> 			: public true_type {};
	template<>			   	struct tmp_is_integral<char32_t> 			: public true_type {};
	template<>			   	struct tmp_is_integral<short> 				: public true_type {};
	template<>			   	struct tmp_is_integral<unsigned short> 		: public true_type {};
	template<>			   	struct tmp_is_integral<int> 				: public true_type {};
	template<>			   	struct tmp_is_integral<unsigned int> 		: public true_type {};
	template<>			   	struct tmp_is_integral<long> 				: public true_type {};
	template<>			   	struct tmp_is_integral<unsigned long> 		: public true_type {};
	template<>			   	struct tmp_is_integral<long long> 			: public true_type {};
	template<>			   	struct tmp_is_integral<unsigned long long>	: public true_type {};


	template<typename _Tp> struct is_integral : public tmp_is_integral<typename ft::remove_cv<_Tp>::type> {};
	// -------------------------------------------------------------------------------------------------------------------------------------

} // ft

# endif