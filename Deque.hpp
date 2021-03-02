/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:00:40 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/02 20:57:30 by alicetetu        ###   ########.fr       */
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
		// public:
			
			// class Iterator
			// {
			// 	public:
			// 		typedef T value_type;
			// 		typedef value_type& const_reference;
					
			// 	private:
			// 		T* m_ptr;
			// 		// T *m_array;
			// 		// T *m_end_array;
			// 		// int m_side; // 0 : to the left / 1 : to the right
			// 		// int m_front;
			// 		// int m_rear;
			// 		// int m_size;
			// 		// int m_capacity;

			// 	public:
			// 		Iterator() :
			// 			// m_index(0),
			// 			m_ptr(NULL),
			// 			// m_array(NULL),
			// 			// m_end_array(NULL),
			// 			// m_side(0),
			// 			// // m_front(0),
			// 			// // m_rear(0),
			// 			// // m_size(0),
			// 			// m_capacity(0)
			// 		{
			// 		}
					
			// 		Iterator(int index, T *array, T *end_array, int side, int capacity):
			// 			// m_ptr(&array[index]),
			// 			m_array(array),
			// 			m_end_array(end_array),
			// 			m_side(side),
			// 			// m_front(front),
			// 			// m_rear(rear),
			// 			// m_size(size),
			// 			m_capacity(capacity)
			// 		{
			// 			if (index == -1)
			// 				m_ptr = &m_array[0];
			// 			else
			// 				m_ptr = &m_array[index];
			// 		}

			// 		Iterator
			// 		operator=(const Iterator &other)
			// 		{
			// 			// if (m_index != -1)
			// 			// 	m_index = other.m_index;
			// 			// else
			// 			// 	m_index = 0;
			// 			m_ptr = other.m_ptr;
			// 			m_array = other.m_array;
			// 			m_end_array = other.m_end_array;
			// 			m_side = other.m_side;
			// 			m_capacity = other.m_capacity;
			// 		//	m_way = other.m_way;
			// 			// m_front = other.m_front;
			// 			// m_rear = other.m_rear;
			// 			// m_size = other.m_size;
			// 			// m_capacity = other.m_capacity;
						
			// 			return (*this);
			// 		}
						
			// 		Iterator& 
			// 		operator++()
			// 		{
			// 			if (m_ptr != m_end_array)
			// 				m_ptr++;
			// 			else
			// 			{
			// 				if (m_side == 1)
			// 				{
			// 					m_ptr = m_array;
			// 					m_side = 0;
			// 			}
			// 			// if (way)
			// 			// {
			// 			// 	if (m_ptr != m_end_array)
			// 			// 		m_ptr++;
			// 			// 	else
			// 			// 		m_ptr = m_array;
			// 			// }
			// 			// else
			// 			// {
			// 			// 	if( m_ptr != m_array)
			// 			// 		m_ptr--;
			// 			// 	else
			// 			// 		m_ptr = m_end_array;
			// 			// }
			// 			// std::cout << "index : " << m_index << std::endl;
			// 			// std::cout << "rear : " << m_rear << std::endl;
			// 			// std::cout << "front : " << m_front << std::endl;
			// 			// int front;
			// 			// if (m_front < 0)
			// 			// 	front = 0;
			// 			// else
			// 			// 	front = m_front;
						
			// 			// if (m_index >= 0 && m_index <= m_rear && m_rear < m_front)
			// 			// {
			// 			// 	m_index++; // check overflow
			// 			// 	if (m_index == front)
			// 			// 		m_index = m_size; // reproduce the segfault
			// 			// }
			// 			// else if(m_index >= front && m_index < m_capacity && m_rear < m_front)
			// 			// {
			// 			// 	m_index++;
			// 			// 	if (m_index == m_rear)
			// 			// 		m_index = m_size; // reproduce the segfault
			// 			// }
			// 			// else if(m_rear > m_front)
			// 			// {
			// 			// 	m_index--;
			// 			// 	// if (m_index == m_rear)
			// 			// 	// 	m_index = m_size; // reproduce the segfault
			// 			// }
			// 			// std::cout << "index exit : " << m_index << std::endl;
			// 			return (*this);
			// 		}

			// 		int 
			// 		operator-(Iterator& first)
			// 		{
			// 			int ret = 0;
			// 			int part1;
			// 			int part2;
						
			// 			if (first.side() == m_side)
			// 			{
			// 				ret = first.ptr() - m_ptr;
			// 				if (ret < 0)
			// 					ret = -ret;
			// 			}
			// 			else
			// 			{
			// 				if (first.side() == 0)
			// 				{
			// 					part1 = first.ptr() - first.start();
			// 					if (part1 < 0)
			// 						part1 = -part1;
			// 				}
			// 				else if (first.side() == 1)
			// 				{
			// 					part1 = first.ptr() - first.end();
			// 					if (part1 < 0)
			// 						part1 = -part1;
			// 				}
			// 				if (m_side == 0)
			// 				{
			// 					part2 = m_ptr - m_array;
			// 					if (part2 < 0)
			// 						part2 = -part2;
			// 				}
			// 				else if (m_side == 1)
			// 				{
			// 					part2 = m_ptr - m_end_array;
			// 					if (part2 < 0)
			// 						part2 = -part2;
			// 				}
			// 				ret = part1 + part2;
			// 			}
			// 			// if (first.ptr() < &m_array[m_index])
			// 			// {
			// 			// 	ret = &m_array[m_index] - first.ptr();
			// 			// 	if (ret < 0)
			// 			// 		ret = -ret;
							
			// 			// }
			// 			// else
			// 			// {
			// 			// 	ret = (first.ptr() - m_array) + (m_capacity - first.index());
			// 			// }
			// 			return(ret); // check if rear changes
			// 		}

			// 		Iterator
			// 		operator++(T) // ou int?
			// 		{
			// 			Iterator tmp(*this);
			// 			operator++();
			// 			return (tmp);
			// 		}
					
			// 		Iterator& 
			// 		operator--()
			// 		{
			// 			if (m_ptr != m_array)
			// 				m_ptr--;
			// 			else
			// 			{
			// 				m_ptr = m_end_array;
			// 				m_side = 1;
			// 			}
			// 			// int front;
			// 			// if (m_front < 0)
			// 			// 	front = 0;
			// 			// else
			// 			// 	front = m_capacity - 1;
						
			// 			// if (m_index >= 0 && m_index <= m_rear)
			// 			// {
			// 			// 	m_index--; // check overflow
			// 			// 	// if (m_index == m_front)
			// 			// 	// 	m_index = m_size; // reproduce the segfault
			// 			// }
			// 			// else if(m_index >= m_front)
			// 			// {
			// 			// 	m_index++;
			// 			// 	// if (m_index == m_rear)
			// 			// 	// 	m_index = m_size; // reproduce the segfault
			// 			// }
			// 			// if (way)
			// 			// {
			// 			// 	if( m_ptr != m_array)
			// 			// 		m_ptr--;
			// 			// 	else
			// 			// 		m_ptr = m_end_array;
			// 			// }
			// 			// else
			// 			// {
			// 			// 	if( m_ptr != m_array)
			// 			// 		m_ptr--;
			// 			// 	else
			// 			// 		m_ptr = m_end_array;
			// 			// }
			// 			return (*this);
			// 		}
					
			// 		Iterator
			// 		operator--(T) // ou int?
			// 		{
			// 			Iterator tmp(*this);
			// 			operator--();
			// 			return (tmp);
			// 		}
					
			// 		bool
			// 		operator==(const Iterator& other) const
			// 		{
			// 			// return (m_index == other.m_index &&	m_array == other.m_array
			// 			// 	&& m_front == other.m_front && m_rear == other.m_rear
			// 			// 	&& m_size == other.m_size && m_capacity == other.m_capacity);
			// 			return (m_ptr == other.m_ptr);
			// 		}
					
			// 		bool
			// 		operator!=(const Iterator& other) const
			// 		{
			// 			return (!(operator==(other)));
			// 		}
					
			// 		T&
			// 		operator*()
			// 		{
			// 			return (*m_ptr);
			// 		}

			// 		T*
			// 		ptr()
			// 		{
			// 			return (m_ptr);
			// 		}

			// 		T*
			// 		start()
			// 		{
			// 			return (m_array);
			// 		}
					
			// 		T*
			// 		end()
			// 		{
			// 			return (m_end_array);
			// 		}

			// 		int
			// 		side()
			// 		{
			// 			return(m_side);
			// 		}
					
			// 		// int
			// 		// index()
			// 		// {
			// 		// 	return (m_index);
			// 		// }
			// };

			// int operator- (const Iterator& first, const Iterator& last)
			// {
			// 	int ret = 0;
						
			// 	if (first.ptr() < last.ptr())
			// 	{
			// 		ret = last.ptr() - first.ptr();
			// 		if (ret < 0)
			// 			ret = -ret;
			// 		return(ret);
			// 	}
			// 	else
			// 	{
			// 		ret = (first.ptr() - m_array) + (m_capacity - last.index());
			// 	}
			// 	return(ret);
			// }

			
			// class ConstIterator
			// {

			// 	public:
			// 		typedef const T value_type;
			// 		typedef const value_type& const_reference;
					
			// 	private:
			// 		T* m_ptr;
			// 		T *m_array;
			// 		T *m_end_array;
			// 		int m_side; // 0 : to the left / 1 : to the right
			// 		// int m_front;
			// 		// int m_rear;
			// 		// int m_size;
			// 		int m_capacity;

			// 	public:
			// 		ConstIterator() :
			// 			// m_index(0),
			// 			m_ptr(NULL),
			// 			m_array(NULL),
			// 			m_end_array(NULL),
			// 			m_side(0),
			// 			// m_front(0),
			// 			// m_rear(0),
			// 			// m_size(0),
			// 			m_capacity(0)
			// 		{
			// 		}
					
			// 		ConstIterator(int index, T *array, T *end_array, int side, int capacity):
			// 			// m_ptr(&array[index]),
			// 			m_array(array),
			// 			m_end_array(end_array),
			// 			m_side(side),
			// 			// m_front(front),
			// 			// m_rear(rear),
			// 			// m_size(size),
			// 			m_capacity(capacity)
			// 		{
			// 			if (index == -1)
			// 				m_ptr = &m_array[0];
			// 			else
			// 				m_ptr = &m_array[index];
			// 		}
					
			// 		ConstIterator
			// 		operator=(const Iterator &other)
			// 		{
			// 			m_ptr = other.m_ptr;
			// 			m_array = other.m_array;
			// 			m_end_array = other.m_end_array;
			// 			m_side = other.m_side;
			// 			m_capacity = other.m_capacity;
						
			// 			return (*this);
			// 		}
					
			// 		ConstIterator& 
			// 		operator++()
			// 		{
			// 			if (m_ptr != m_end_array)
			// 				m_ptr++;
			// 			else
			// 			{
			// 				m_ptr = m_array;
			// 				m_side = 0;
			// 			}
			// 			// int front;
			// 			// if (m_front < 0)
			// 			// 	front = 0;
			// 			// else
			// 			// 	front = m_front;
						
			// 			// if (m_index >= 0 && m_index <= m_rear)
			// 			// {
			// 			// 	m_index++; // check overflow
			// 			// 	if (m_index == front)
			// 			// 		m_index = m_size; // reproduce the segfault
			// 			// }
			// 			// else if(m_index >= front && m_index < m_capacity)
			// 			// {
			// 			// 	m_index--;
			// 			// 	if (m_index == m_rear)
			// 			// 		m_index = m_size; // reproduce the segfault
			// 			// }
			// 			return (*this);
			// 		}
					
			// 		int 
			// 		operator-(ConstIterator& first)
			// 		{
			// 			int ret = 0;
			// 			int part1;
			// 			int part2;
						
			// 			if (first.side() == m_side)
			// 			{
			// 				ret = first.ptr() - m_ptr;
			// 				if (ret < 0)
			// 					ret = -ret;
			// 			}
			// 			else
			// 			{
			// 				if (first.side() == 0)
			// 				{
			// 					part1 = first.ptr() - first.start();
			// 					if (part1 < 0)
			// 						part1 = -part1;
			// 				}
			// 				else if (first.side() == 1)
			// 				{
			// 					part1 = first.ptr() - first.end();
			// 					if (part1 < 0)
			// 						part1 = -part1;
			// 				}
			// 				if (m_side == 0)
			// 				{
			// 					part2 = m_ptr - m_array;
			// 					if (part2 < 0)
			// 						part2 = -part2;
			// 				}
			// 				else if (m_side == 1)
			// 				{
			// 					part2 = m_ptr - m_end_array;
			// 					if (part2 < 0)
			// 						part2 = -part2;
			// 				}
			// 				ret = part1 + part2;
			// 			}
			// 			// int ret = 0;
						
			// 			// if (first.ptr() < &m_array[m_index])
			// 			// {
			// 			// 	ret = &m_array[m_index] - first.ptr();
			// 			// 	if (ret < 0)
			// 			// 		ret = -ret;
							
			// 			// }
			// 			// else
			// 			// {
			// 			// 	ret = (first.ptr() - m_array) + (m_capacity - first.index());
			// 			// }
			// 			return(ret); // check if rear changes
			// 		}
					
			// 		ConstIterator
			// 		operator++(int) // ou int?
			// 		{
			// 			ConstIterator tmp(*this);
			// 			operator++();
			// 			return (tmp);
			// 		}
					
			// 		ConstIterator& 
			// 		operator--()
			// 		{
			// 			if (m_ptr != m_array)
			// 				m_ptr--;
			// 			else
			// 			{
			// 				m_ptr = m_end_array;
			// 				m_side = 1;
			// 			}
			// 			// int front;
			// 			// if (m_front < 0)
			// 			// 	front = 0;
			// 			// else
			// 			// 	front = m_capacity - 1;
						
			// 			// if (m_index >= 0 && m_index <= m_rear)
			// 			// {
			// 			// 	m_index--; // check overflow
			// 			// 	// if (m_index == m_front)
			// 			// 	// 	m_index = m_size; // reproduce the segfault
			// 			// }
			// 			// else if(m_index >= m_front)
			// 			// {
			// 			// 	m_index++;
			// 			// 	// if (m_index == m_rear)
			// 			// 	// 	m_index = m_size; // reproduce the segfault
			// 			// }
			// 			return (*this);
			// 		}
					
			// 		ConstIterator
			// 		operator--(T) // ou int?
			// 		{
			// 			ConstIterator tmp(*this);
			// 			operator--();
			// 			return (tmp);
			// 		}
					
			// 		bool
			// 		operator==(const ConstIterator& other) const
			// 		{
			// 			// return (m_index == other.m_index &&	m_array == other.m_array
			// 			// 	&& m_front == other.m_front && m_rear == other.m_rear
			// 			// 	&& m_size == other.m_size && m_capacity == other.m_capacity);
			// 			return (m_ptr == other.m_ptr);
			// 		}
					
			// 		bool
			// 		operator!=(const ConstIterator& other) const
			// 		{
			// 			return (!(operator==(other)));
			// 		}
					
			// 		const_reference
			// 		operator*() const
			// 		{
			// 			return (*m_ptr);
			// 		}

			// 		const T*
			// 		ptr()const 
			// 		{
			// 			return (m_ptr);
			// 		}

			// 		const T*
			// 		start() const
			// 		{
			// 			return (m_array);
			// 		}
					
			// 		const T*
			// 		end() const
			// 		{
			// 			return (m_end_array);
			// 		}

			// 		int
			// 		side()
			// 		{
			// 			return(m_side);
			// 		}
			// };
		
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
				return(iterator(&m_array[m_rear + 1]));
			}
			
			const_iterator end() const
			{
				return(const_iterator(&m_array[m_rear + 1]));
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
					std::cout << "RESERVE: " << n << "\n" << std::flush;
					std::cout << "SIZE: " << m_size << "\n" << std::flush;
				// if (n > m_capacity)
				// {
					if (m_capacity)
					{
						T* copy = m_allocator.allocate(n);
						//int oldCapacity = m_capacity;
						size_t start = n / 2 - m_size / 2;
						for (size_type i = 0; i < m_size; i++)
							m_allocator.construct(copy + start + i, m_array[i]);
						m_allocator.destroy(m_array);
						m_allocator.deallocate(m_array, m_capacity);
						m_array = copy;
						// if (m_front >= 0)
						// 	m_front += (n - oldCapacity); // check
						std::cout << "SIZE: " << m_size << "\n" << std::flush;
						if (!m_size)
							m_middle = n / 2;
						std::cout << "ICI\n";
						
					}
					else
					{
						m_array = m_allocator.allocate(n);
						m_middle = n/2;
					}
		
					m_capacity = n;
				// }
				//copy
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
			//		std::cout << "NOT GOOD\n" << std::flush;
				clear();
				int neededSize = last.value() - first.value();
				//	std::cout << "HERE\n" << std::flush;
				if (neededSize < 0)
					neededSize = -neededSize;
				std::cout << "Needed: " << neededSize << std::endl;
				if (neededSize > m_capacity)
					reserve(neededSize * 2 + 10); // check max limit
				//	std::cout << "HERE\n" << std::flush;
				// std::cout << "First: " << *first <<  " - " << first.index() << "\n" << std::flush;
				// first++;
				// std::cout << "First: " << *first <<  " - " << first.index() << "\n" << std::flush;
				// first++;
				// std::cout << "First: " << *first <<  " - " << first.index() << "\n" << std::flush;
				for (;first != last; first++)
				{
				//	std::cout << "First: " << *first <<  " - " << first.index() << "\n" << std::flush;
						//	std::cout << "First: " << first.index() << "\n" << std::flush;
					push_back(*first);
				//		std::cout << "HERE\n" << std::flush;
				}
			}

			void push_back (const value_type& val)
			{
				if (m_size >= m_capacity - 1)
					reserve(m_size + 10) ; // check way to reserve  + limit max_size
				if (m_size)
				{
					// std::cout << "rear: " << m_rear << std::endl;
					m_rear++;
					m_allocator.construct(&m_array[m_rear], val);
				}
				else
				{
					m_allocator.construct(&m_array[m_middle], val);
					m_front = m_middle;
					m_rear = m_middle;
				// 	std::cout << "rear middle: " << m_rear << std::endl;
				}
				m_size++;
			}

			void push_front (const value_type& val)
			{
				if (m_size >= m_capacity)
					reserve(m_size + 10) ; // check way to reserve  + limit max_size
				if (m_front < 0)
					m_front = m_capacity - 1;
				else
					m_front--;
				m_allocator.construct(&m_array[m_front], val);
				m_size++;
			}

			void pop_back()
			{
				// if (m_size)
				// {
					m_allocator.destroy(&m_array[m_rear]);
					// std::cout << "rear: " <<  m_array[m_rear] << std::endl;
					m_rear--;
					m_size--;
					if (m_rear == -1 && m_size)
						m_rear = m_capacity - 1;
					
					// std::cout << "rear : " << m_rear << std::endl;
					// std::cout << "cap : " << m_capacity << std::endl;
					
				// }
			}
			
			void pop_front()
			{
				int front;
				if (m_size)
				{
					if (m_front == -1)
						front = 0;
					else
						front = m_front;	
					m_allocator.destroy(&m_array[front]);
					m_front++;
					m_size--;
				}
			}
			
			void clear()
			{
				// std::cout << "CLEAR\n" << std::flush;
				if (m_size)
				{	
					// std::cout << "insideCLEAR\n" << std::flush;
					m_allocator.destroy(m_array);
					m_array = NULL;
				}
				m_size = 0;
				m_front = -1;
				m_rear = 0;
			}

		private:

		
			iterator setIterator(int index)
			{
				int side;
				if (m_rear >= m_front)
					side = 0;
				else
				{
					if (index <= m_rear)
						side = 0;
					else
						side = 1;
				}
				return (iterator(index, m_array, &m_array[m_capacity - 1], side, m_capacity));
			}
			
			const_iterator setConstIterator(int index) const
			{
				int side;
				if (m_rear > m_front)
					side = 0;
				else
				{
					if (index <= m_rear)
						side = 0;
					else
						side = 1;
				}
				return (const_iterator(index, m_array, &m_array[m_capacity - 1], side, m_capacity));
			}
			
	};
};
#endif