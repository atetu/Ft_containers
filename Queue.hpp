/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:00:40 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/15 19:47:15 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

#include <memory>
#include <iostream>
#include "Iterator.hpp"
#include "Deque.hpp"


namespace ft
{
	template <class T, class Container = deque<T> >
	class queue
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;
			
		
		private:
			container_type m_container;
			
		public:
		
			explicit queue (const container_type& ctnr = container_type()): m_container(ctnr)
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
			
			value_type& front()
			{
				return(m_container.front());
			}
			
			const value_type& back() const
			{
				return(m_container.back());
			}

			void push (const value_type& val)
			{
				m_container.push_back(val);
			}

			void pop()
			{
				m_container.pop_front();
			}

			template <class X, class Y>
			friend bool operator== (const queue<X, Y>& lhs, const queue<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator!= (const queue<X, Y>& lhs, const queue<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator< (const queue<X, Y>& lhs, const queue<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator<= (const queue<X, Y>& lhs, const queue<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator> (const queue<X, Y>& lhs, const queue<X, Y>& rhs);

			template <class X, class Y>
			friend bool operator>= (const queue<X, Y>& lhs, const queue<X, Y>& rhs);
	};

	template <class T, class Container>
  	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.m_container == rhs.m_container);
	}

	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return(!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator< (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.m_container< rhs.m_container);
	}

	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.m_container<= rhs.m_container);
	}

	template <class T, class Container>
	bool operator> (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.m_container > rhs.m_container);
	}
	
	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.m_container>= rhs.m_container);
	}
};
#endif