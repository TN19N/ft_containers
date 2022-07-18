/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:30:19 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/18 10:35:34 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
	
	// swap -------------------------------------------------------------------------------------------------------------------------------------------
	template<class _Tp>
	void swap(_Tp& __x, _Tp& __y)
	{ _Tp __c(__x); __x = __y; __y = __c; }
	// ------------------------------------------------------------------------------------------------------------------------------------------------

	// pair -------------------------------------------------------------------------------------------------------------------------------------------
	template<class _T1, class _T2>
	struct pair
	{
		typedef _T1 first_type;
		typedef _T2 secend_type;

		_T1 first;
		_T2 secend;

		pair() : first(), secend() {}
		pair(_T1 const& __t1, _T2 const& __t2) : first(__t1), secend(__t2) {}
		template<class _U1, class _U2> pair(const pair<_U1, _U2>& __p) : first(__p.first), secend(__p.secend) {}

		pair& operator = (pair const& __p)
		{
			first = __p.first;
			secend = __p.secend;
			return (*this);
		}

		void swap(const pair& __p)
		{
			ft::swap(first, __p.first);
			ft::swap(secend, __p.secend);
		}
	};

	template<class _T1, class _T2>
	bool operator == (const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return (__x.first == __y.first && __x.secend == __y.secend); }

	template<class _T1, class _T2>
	bool operator != (const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return !(__x == __y); }

	template<class _T1, class _T2>
	bool operator < (const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return __x.first < __y.first || ( !(__y.first < __x.first) && __x.secend < __y.secend ); }

	template<class _T1, class _T2>
	bool operator > (const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return (__y < __x); }

	template<class _T1, class _T2>
	bool operator >= (const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return !(__x < __y); }

	template<class _T1, class _T2>
	bool operator <= (const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return !(__y < __x); }
	// ------------------------------------------------------------------------------------------------------------------------------------------------

	// make_pair --------------------------------------------------------------------------------------------------------------------------------------
	template<class _T1, class _T2>
	pair<_T1, _T2> make_pair(_T1 __x, _T2 __y)
	{ return (ft::pair<_T1, _T2>(__x, __y)); }
	// ------------------------------------------------------------------------------------------------------------------------------------------------

} // ft

# endif