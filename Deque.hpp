/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:00:40 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/01 19:56:41 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

#include <memory>
#include <iostream>
#include "Iterator.hpp"

/*https://www.softwaretestinghelp.com/deque-in-cpp/*/
/*https://www.programiz.com/dsa/deque*/

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class deque
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef Iterator<T> iterator;
			typedef ConstIterator<T> const_iterator;
			//	typedef ft::ReverseIterator<T> reverse_iterator;
		//	typedef ft::ConstReverseIterator<T> const_reverse_iterator;

		private:
			allocator_type m_allocator;
			T *m_array;
			int m_font;
			int m_rear;
			int m_size;
			int m_capacity;

		explicit deque (const allocator_type& alloc = allocator_type())
			m_allocator(alloc),
			m_array(nullptr),
			m_front(-1),
			m_rear(0),
			m_size(0),
			m_capacity(0)
		{
		}
		
		explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			m_allocator(alloc),
			m_array(nullptr),
			m_front(-1),
			m_rear(0),
			m_size(0),
			m_capacity(0)
		{
			assign(n, val);
		}
	
		template <class InputIterator> deque (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			m_allocator(alloc),
			m_array(nullptr),
			m_front(-1),
			m_rear(0),
			m_size(0),
			m_capacity(0)
		{
			assign(first, last);
		}
			
		deque (const deque& x)
		{
			assign(x.begin(), x.end());
		}

		void reserve(size_type n)
		{
			if (n > m_capacity)
			{
				if (m_capacity)
				{
					T* copy = m_allocator.allocate(n);
					int oldCapacity = m_capacity;
					
					for (size_type i = 0; i < m_size; i++)
						m_allocator.construct(copy + i, m_array[i]);
					m_allocator.destroy(m_array);
					m_allocator.deallocate(m_array, m_size);
					m_array = copy;
					if (m_front >= 0)
						m_front += (n - oldCapacity); // check
					
				}
				else
				{
					m_array = m_allocator.allocate(n);
				}
				m_capacity = n;
			}
			//copy
		}

			/*MODIFIERS*/
			void assign(size_type n, const value_type& val)
			{
			//	clear();
				
				if (n >= m_capacity)
					reserve(n +10) ; // check way to reserve  + limit max_size
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
			
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
			//	clear();
				int neededSize = last.value() - first.value();
			//	std::cout << "HERE\n" << std::flush;
				if (neededSize < 0)
					neededSize = -neededSize;
				if (neededSize >= m_capacity)
					reserve(neededSize + 10); // check max limit
			//	std::cout << "HERE\n" << std::flush;
				for (;first != last; first++)
				{
		//			std::cout << "First: " << *first << "\n" << std::flush;
					push_back(*first);
			//		std::cout << "HERE\n" << std::flush;
				}
			}

			void push_back (const value_type& val)
			{
				if (m_size + 1 > m_capacity)
					reserve(m_size + 10) ; // check way to reserve  + limit max_size
				m_allocator.construct(m_array + m_size, val);
				m_size++;
			}

	};
};
#endif