/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:12:43 by atetu             #+#    #+#             */
/*   Updated: 2021/03/02 14:31:03 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <memory>
#include <iostream>

/*https://www.softwaretestinghelp.com/deque-in-cpp/*/
/*https://www.programiz.com/dsa/deque*/

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class Base
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			// typedef ptrdiff_t difference_type;
			// typedef typename allocator_type::reference reference;
			// typedef typename allocator_type::const_reference const_reference;
			// typedef typename allocator_type::pointer pointer;
			// typedef typename allocator_type::const_pointer const_pointer;
			// typedef DequeIterator<T> iterator;
		//	typedef ConstDequeIterator<T> const_iterator;
			//	typedef ft::ReverseIterator<T> reverse_iterator;
		//	typedef ft::ConstReverseIterator<T> const_reverse_iterator;

		protected:
			allocator_type m_allocator;
			T *m_array;
			int m_front;
			int m_rear;
			int m_size;
			int m_capacity;
	
		public:
		
			Base (const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(nullptr),
				m_front(-1),
				m_rear(0),
				m_size(0),
				m_capacity(0)
			{
			}
			virtual void reserve(size_type n) = 0;
			// Base (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			// 	m_allocator(alloc),
			// 	m_array(nullptr),
			// 	m_front(-1),
			// 	m_rear(0),
			// 	m_size(0),
			// 	m_capacity(0)
			// {
			// }
		
			// template <class InputIterator> Base (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
			// 	m_allocator(alloc),
			// 	m_array(nullptr),
			// 	m_front(-1),
			// 	m_rear(0),
			// 	m_size(0),
			// 	m_capacity(0)
			// {
			// }

	};
};
#endif