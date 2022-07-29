/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:14:25 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/29 17:21:52 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

	template<typename _Tp, typename _Container = ft::vector<_Tp> >
	class stack
	{
	public:
		typedef _Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;
    	typedef typename container_type::size_type			size_type;

	protected:
		container_type c;
	
	public:
		explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}
		stack(const stack& __q) : c(__q.c) {}
		~stack() {}

		stack& operator = (const stack& __q) { c = __q.c; return(*this); }

		bool			empty() const { return (c.empty()); }
		size_type		size() 	const { return (c.size()); }
		reference		top() 		  { return (c.back()); }
		const_reference	top()   const { return (c.back()); }
		
		void push(const value_type& val)	{ c.push_back(val); }
		void pop() 							{ c.pop_back(); }
		void swap(stack& __s) 				{ ft::swap(c, __s.c); }

		template<typename T1, typename _C1> friend bool operator == (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);
		template<typename T1, typename _C1> friend bool operator < (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);
	};

	template<typename T1, typename _C1> bool operator == (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y) { return (__x.c == __y.c); }
	template<typename T1, typename _C1> bool operator < (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y) { return (__x.c < __y.c); }
	template<typename T1, typename _C1> bool operator != (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y) { return !(__x == __y); }
	template<typename T1, typename _C1> bool operator > (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y) { return (__y < __x); }
	template<typename T1, typename _C1> bool operator >= (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y) { return !(__x < __y); }
	template<typename T1, typename _C1> bool operator <= (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y) { return !(__y < __x); }

	template<typename T1, typename _C1> void swap(stack<T1, _C1>& __x, stack<T1, _C1>& __y) { __x.swap(__y); }

} // ft

# endif