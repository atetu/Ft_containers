/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:00:40 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/03 15:16:00 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

#include <memory>
#include <iostream>
// #include "Base.hpp"
#include "Iterator.hpp"



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
			int m_front;
			int m_rear;
			int m_size;
			int m_capacity;
			int m_middle;
			
		public:
		
			explicit deque (const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(nullptr),
				m_front(0),
				m_rear(0),
				m_size(0),
				m_capacity(0)
			{
			}
			
			explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(nullptr),
				m_front(0),
				m_rear(0),
				m_size(0),
				m_capacity(0)
			{
				assign(n, val);
			}
		
			template <class InputIterator> deque (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) :
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
				if (this != &x)
				{
					m_allocator = x.m_allocator;
					m_array = NULL;
					m_front = -1;
					m_rear = 0;
					m_size = 0;
					m_capacity = 0;
			
					if (x.m_capacity !=0)	
						reserve(x.m_capacity);
					assign(x.begin(), x.end());
				}
			}

			deque& operator= (deque const & x)
			{
				if (this != &x)
				{
					//clear();
					m_allocator = x.m_allocator;
					m_array = nullptr;
					m_size = 0;
					m_capacity = 0;
					m_front = -1;
					m_rear = 0;
				//	const_iterator it = x.begin();
				//	std::cout << "IT: " << it.value() << std::endl;
					
					if (x.m_capacity != 0)
						reserve(x.m_capacity);
				
					if (x.size() != 0)
						assign(x.begin(), x.end());
				
				}
				return(*this);
			}
			
			iterator begin()
			{
				return(iterator(&m_array[m_front]));	
			}
			
			const_iterator begin() const
			{
				return(const_iterator(&m_array[m_front]));
			}

			iterator end()
			{
				return(iterator(&m_array[m_rear]));
			}
			
			const_iterator end() const
			{
				return(const_iterator(&m_array[m_rear]));
			}

			size_type size() const
			{
				return(m_size);
			}
			
			bool empty() const
			{
				return (m_size == 0);
			}
			
			void reserve(size_type n)
			{
					// std::cout << "RESERVE: " << n << "\n" << std::flush;
					// std::cout << "SIZE: " << m_size << "\n" << std::flush;
				// if (n > m_capacity)
				// {
					size_t start;
					int end;
					if (m_capacity)
					{
						T* copy = m_allocator.allocate(n);
						//int oldCapacity = m_capacity;
						if (m_size)
						{
							start = n / 2 - m_size / 2;
							
							for (size_type i = 0; i < m_size; i++)
							{	
								m_allocator.construct(copy + start + i, m_array[i]);
								end = start + i + 1;
							}
							m_front = start;
							m_rear = end;
						}
						else
						{
							m_front =  m_rear = n / 2;
							//m_rear = m_front + 1;
						}
						
						m_allocator.destroy(m_array);
						m_allocator.deallocate(m_array, m_capacity);
						m_array = copy;
						// m_front = start;
						// m_rear = end;
					//	std::cout << "end: " << end << std::endl;
						// if (m_front >= 0)
						// 	m_front += (n - oldCapacity); // check
				//		std::cout << "SIZE: " << m_size << "\n" << std::flush;
						// if (!m_size)
						// 	m_middle = n / 2;
					//	std::cout << "ICI\n";
						
					}
					else
					{
						m_array = m_allocator.allocate(n);
						m_middle = n/2;
						m_front = m_middle;
						m_rear = m_middle;
					}
		
					m_capacity = n;
					// std::cout << "Front: "<< m_front << std::endl;
					// std::cout << "Rear: "<< m_rear << std::endl;
					
				// }
				//copy
			}

			/*ELEMENT ACCESS*/
			reference back()
			{
				return (m_array[m_rear - 1]);
			}
			
			const_reference back() const
			{
				return (m_array[m_rear - 1]);
			}
			
			/*MODIFIERS*/
			void assign(size_type n, const value_type& val)
			{
			//	std::cout << "HERE\n" << std::flush;
				clear();
				if (n >= m_capacity)
					reserve(n * 2 + 10) ; // check way to reserve  + limit max_size
				for (size_type i = 0; i < n; i++)
					push_back(val);
			//	std::cout << "end\n" << std::flush;
			}
				
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				clear();
				int neededSize = last.value() - first.value();
			
				if (neededSize < 0)
					neededSize = -neededSize;
				if (neededSize > m_capacity)
					reserve(neededSize * 2 + 10); // check max limit
				
				for (;first != last; first++)
					push_back(*first);
			}

			void push_back (const value_type& val)
			{
				if (m_size >= m_capacity - 1)
					reserve(m_size + 10) ; // check way to reserve  + limit max_size
				if (m_size)
				{
					// std::cout << "rear: " << m_rear << std::endl;
					m_rear++;
					m_allocator.construct(&m_array[m_rear - 1], val);
				}
				else
				{
					m_allocator.construct(&m_array[m_front], val);
					// m_front = m_middle;
					m_rear++;
				//	m_rear++;
				// 	std::cout << "rear middle: " << m_rear << std::endl;
				}
				m_size++;
			}

			void push_front (const value_type& val)
			{
				if (m_size >= m_capacity || &m_array[m_front] == m_array)
					reserve(m_size + 10) ; // check way to reserve  + limit max_size
				m_front--;
				m_allocator.construct(&m_array[m_front], val);
				m_size++;
			}

			void pop_back()
			{
				// if (m_size)
				// {
					m_allocator.destroy(&m_array[m_rear - 1]);
					// std::cout << "rear: " <<  m_array[m_rear] << std::endl;
					m_rear--;
					m_size--;
					// if (m_rear == -1 && m_size)
					// 	m_rear = m_capacity - 1;
					
					// std::cout << "rear : " << m_rear << std::endl;
					// std::cout << "cap : " << m_capacity << std::endl;
					
				// }
			}
			
			void pop_front()
			{
				// int front;
				// if (m_size)
				// {
				// 	if (m_front == -1)
				// 		front = 0;
				// 	else
				// 		front = m_front;	
					m_allocator.destroy(&m_array[m_front]);
					m_front++;
					m_size--;
				// }
			}
			
			void clear()
			{
				// std::cout << "CLEAR\n" << std::flush;
				if (m_size)
				{	
					// std::cout << "insideCLEAR\n" << std::flush;
					m_allocator.destroy(&m_array[m_front]);
					m_array = NULL;
				}
				m_size = 0;
				if (m_capacity)
					m_front = m_rear = m_capacity / 2;
				else
					m_front = m_rear = 0;
				
			}
		// private:

		
		// 	iterator setIterator(int index)
		// 	{
		// 		int side;
		// 		if (m_rear >= m_front)
		// 			side = 0;
		// 		else
		// 		{
		// 			if (index <= m_rear)
		// 				side = 0;
		// 			else
		// 				side = 1;
		// 		}
		// 		return (iterator(index, m_array, &m_array[m_capacity - 1], side, m_capacity));
		// 	}
			
		// 	const_iterator setConstIterator(int index) const
		// 	{
		// 		int side;
		// 		if (m_rear > m_front)
		// 			side = 0;
		// 		else
		// 		{
		// 			if (index <= m_rear)
		// 				side = 0;
		// 			else
		// 				side = 1;
		// 		}
		// 		return (const_iterator(index, m_array, &m_array[m_capacity - 1], side, m_capacity));
		// 	}
			
	};
	
	template <class T, class Alloc>
	bool operator== (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::deque<T>::const_iterator it_lhs = lhs.begin();
		typename ft::deque<T>::const_iterator ite_lhs = lhs.end();
		typename ft::deque<T>::const_iterator it_rhs = rhs.begin();
		typename ft::deque<T>::const_iterator ite_rhs = rhs.end();
		while(it_lhs != ite_lhs && it_rhs != ite_rhs)
		{
			if (*it_lhs != *it_rhs)
				return(false);
			it_lhs++;
			it_rhs++;
		}
		if (it_lhs == ite_lhs && it_rhs == ite_rhs)
			return(true);
		return (false);
	}
	
	template <class T, class Alloc>
	bool operator!= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
	{
		return(!(lhs == rhs));
	}
	
	template <class T, class Alloc>
	bool operator< (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
	{
		typename ft::ConstIterator<T> it_lhs = lhs.begin();
		typename ft::ConstIterator<T> ite_lhs = lhs.end();
		typename ft::ConstIterator<T> it_rhs = rhs.begin();
		typename ft::ConstIterator<T> ite_rhs = rhs.end();
		
		while (it_lhs != ite_lhs)
		{
			if (it_rhs == ite_rhs || *it_rhs < *it_lhs)
				return false;
			else if (*it_lhs < *it_rhs)
				return true;
			++it_lhs;
			++it_rhs;
		}
		return (it_rhs != ite_rhs);
	}
	
	template <class T, class Alloc>
	bool operator<= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	
	template <class T, class Alloc>
	bool operator> (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T, class Alloc>
	bool operator>= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
};
#endif