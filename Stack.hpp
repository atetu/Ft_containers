/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:00:40 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/11 18:26:07 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <memory>
#include <iostream>
// #include "Base.hpp"
#include "Iterator.hpp"
#include "Deque.hpp"


namespace ft
{
	template <class T, class Container = deque<T> >
	class stack
	{
		
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;
					
		private:
			container_type m_container;
			
		public:
		
			explicit stack (const container_type& ctnr = container_type()): m_container(ctnr)
			{
			}

			bool empty() const
			{
				return(m_container.empty());
			}
			
			size_type size() const
			{
				return (m_container.size());
			}
			
			value_type& top()
			{
				return(m_container.back());
			}
			
			const value_type& top() const
			{
				return(m_container.back());
			}

			void push (const value_type& val)
			{
				m_container.push_back(val);
			}

			void pop()
			{
				m_container.pop_back();
			}

		
			template <class X, class Y>
			friend bool operator== (const stack<X, Y>& lhs, const stack<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator!= (const stack<X, Y>& lhs, const stack<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator< (const stack<X, Y>& lhs, const stack<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator<= (const stack<X, Y>& lhs, const stack<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator> (const stack<X, Y>& lhs, const stack<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator>= (const stack<X, Y>& lhs, const stack<X, Y>& rhs);
	};

	template <class T, class Container>
  	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_container == rhs.m_container);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return(!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_container< rhs.m_container);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_container<= rhs.m_container);
	}

	template <class T, class Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_container > rhs.m_container);
	}
	
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_container>= rhs.m_container);
	}
};
#endif