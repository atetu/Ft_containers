/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:00:40 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/03 15:23:05 by atetu            ###   ########.fr       */
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
			// typedef ptrdiff_t difference_type;
			// typedef typename allocator_type::reference reference;
			// typedef typename allocator_type::const_reference const_reference;
			// typedef typename allocator_type::pointer pointer;
			// typedef typename allocator_type::const_pointer const_pointer;
			// typedef Iterator<T> iterator;
			// typedef ConstIterator<T> const_iterator;
			//	typedef ft::ReverseIterator<T> reverse_iterator;
		//	typedef ft::ConstReverseIterator<T> const_reverse_iterator;
		
		
			
	
		
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
	
	// template <class T, class Alloc>
	// bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	// 	typename ft::vector<T>::const_iterator it_lhs = lhs.begin();
	// 	typename ft::vector<T>::const_iterator ite_lhs = lhs.end();
	// 	typename ft::vector<T>::const_iterator it_rhs = rhs.begin();
	// 	typename ft::vector<T>::const_iterator ite_rhs = rhs.end();
		
	// 	while (it_lhs != ite_lhs)
	// 	{
	// 		if (it_rhs == ite_rhs || *it_rhs < *it_lhs)
	// 			return false;
	// 		else if (*it_lhs < *it_rhs)
	// 			return true;
	// 		++it_lhs;
	// 		++it_rhs;
	// 	}
	// 	return (it_rhs != ite_rhs);
	// }
	
	// template <class T, class Alloc>
	// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	// 	return (!(rhs < lhs));
	// }

	// template <class T, class Alloc>
	// bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	// 	return (rhs < lhs);
	// }

	// template <class T, class Alloc>
	// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	// 	return (!(lhs < rhs));
	// }
};
#endif