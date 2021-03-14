/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:00:40 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/14 16:59:39 by user42           ###   ########.fr       */
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
				m_size(0)
				
			{
				//std::cout << "ICIC\n";
				m_capacity = 0;
				assign(n, val);
				//std::cout << "ASSIGN\n";
			//exit(1);
			}
		
			template <class InputIterator> deque (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) :
				m_allocator(alloc),
				m_array(nullptr),
				m_front(0),
				m_rear(0),
				m_size(0),
				m_capacity(0)
			{
				assign(first, last);
			}
				
			deque(const deque& x)
			{
				if (this != &x)
				{
					m_allocator = x.m_allocator;
					m_array = NULL;
					m_front = 0;
					m_rear = 0;
					m_size = 0;
					m_capacity = 0;
			
					if (x.m_capacity !=0)	
						reserve(x.m_capacity);
					assign(x.begin(), x.end());
				}
			}

			~deque()
			{
				// std::cout << "Destructor\n";
			
			//	std::cout << "FRONT: " << m_array[m_front] << std::endl;
				// exit(1);
				clear();
				// delete (m_array);
				// for (int i = 0 ; i < m_capacity; i++)
					m_allocator.deallocate(m_array, m_capacity);
				m_array = NULL;
				// std::cout << "end of \n";
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
					m_front = 0;
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
				//std::cout << "M-front: " << m_front << std::endl;
				return(iterator(&m_array[m_front]));	
			}
			
			const_iterator begin() const
			{
				// std::cout << "M-front: " << m_front <<  std::endl;
				// std::cout << "M-size: " << m_size << std::endl;
				// if (m_front)
			//	std::cout << "M-front: " <<m_array[m_front] << std::endl;
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
				//	std::cout << "RESERVE: " << n << "\n" << std::flush;
					// std::cout << "SIZE: " << m_size << "\n" << std::flush;
				// if (n > m_capacity)
				// {
					size_t start;
					int end;
					if (m_capacity)
					{
					//	std::cout << "ALLOUEMENET\n";
						T* copy = m_allocator.allocate(n);
						//int oldCapacity = m_capacity;
						if (m_size)
						{
							// std::cout << "n: " << n << std::endl;
							// 	std::cout << "capacity: " << m_capacity << std::endl;
						//	std::cout << "Size before cal: " << m_size << std::endl;
							start = n / 2 - m_size / 2;
						//	std::cout << "Size after cal: " << m_size << std::endl;
							end = start;
							for (int i = m_front; i < m_rear; i++)
							{	
									// std::cout << "Start " <<  m_array[i] << std::endl;
								m_allocator.construct(&copy[end], m_array[i]);
								end +=1;
							}
							m_front = start;
							m_rear = end;
							
							
						}
						else
						{
							m_front =  m_rear = n / 2;
							//m_rear = m_front + 1;
						}
						
						// m_allocator.destroy(m_array);
						for(int i = m_front; i < m_rear; i++)
							m_allocator.destroy(&m_array[i]);
				
						m_allocator.deallocate(m_array, m_capacity);
						m_array = copy;
					//	std::cout << "New front 1: " <<  m_front << m_array[m_front] << std::endl;
						// // m_front = start;
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
						// std::cout << "reserve : "<< n << "\n";
						// std::cout << "ALOCATION\n";
						m_array = m_allocator.allocate(n);
					//	m_allocator.deallocate(m_array, m_capacity);
						m_middle = n/2;
						m_front = m_middle;
						m_rear = m_middle;
					}
					// std::cout << "New front: " <<  m_front << std::endl;
					m_capacity = n;
					// std::cout << "Front: "<< m_front << std::endl;
					// std::cout << "Rear: "<< m_rear << std::endl;
					
				// }
				//copy
				// std::cout << "Capacity at the end of reserve : " << m_capacity << std::endl;
				
			}

			/*ELEMENT ACCESS*/
			reference back()
			{
				// std::cout<< " rear :" << m_rear << std::endl;
				// 	std::cout<< " front :" << m_front << std::endl;
			//		std::cout << "val : " << m_array[m_front] << std::endl;
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
				if ((int)n >= m_capacity)
					reserve(n * 2 + 10) ; // check way to reserve  + limit max_size
				(void)val;
				for (size_type i = 0; i < n; i++)
				// {
				// 	this->m_allocator.construct(this->m_array + m_size, val);
				// 	m_size++;
				// }
				// // {
				// // 	this->m_allocator.construct(&(this->m_array[m_front + i]), val);
				// // 	m_rear++;
				// // }
					push_back(val);
				// std::cout << "m_capacity assign: " << m_capacity << std::flush;
			//	exit(1);
			}
				
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				clear();
			//	std::coutstd::cout << "First: " << *first << std::endl;
				int neededSize = last.node() - first.node();
			
				if (neededSize < 0)
					neededSize = -neededSize;
				if (neededSize > m_capacity)
					reserve(neededSize * 2 + 10); // check max limit
				
				for (;first != last; first++)
					push_back(*first);
			}

			void push_back (const value_type& val)
			{
				// std::cout << "initial val : " << val << std::endl;
				// 	std::cout << "initial size : " << m_size << std::endl;
				// std::cout << "Size: " << m_size << "\n" << std::flush;
				// std::cout << "Capacity: " << m_capacity << "\n" << std::flush;
				
				if (m_size >= m_capacity - 1 || m_rear >= m_capacity - 2 )
				{
					// std::cout << "To reserve: " << m_capacity + 10 << std::endl;
					reserve(m_capacity + 10) ; // check way to reserve  + limit max_size
					// std::cout << "Size after reserve: " << m_size << std::endl;
				}
				// std::cout << "CONSTRUCT\n";
				if (m_size)
				{
				//	std::cout << "rear1: " << m_rear << std::endl;
					m_rear++;
					m_allocator.construct(&m_array[m_rear - 1], val);
				//	std::cout << "Size after construct 1: " << m_size << std::endl;
				}
				else
				{
					//std::cout << "rear2: " << m_rear << std::endl;
					m_allocator.construct(&m_array[m_front], val);
					//this->m_allocator.construct(this->m_array + m_size, val);
					// m_front = m_middle;
					m_rear++;
					//std::cout << "Size after construct 2: " << m_size << std::endl;
					// std::cout << "rear end: " << m_rear << std::endl;
					// std::cout << "front: " << m_front << std::endl;
					// std::cout << "val : " << m_array[m_size] << std::endl;
				//	m_rear++;
				// 	std::cout << "rear middle: " << m_rear << std::endl;
				}
			//	std::cout << "Size before increment: " << m_size << std::endl;
				m_size++;
			//	std::cout << "size inside : " << m_size << std::endl;
				//std::cout << "val: " << m_array[m_size-1] << std::endl;
				// std::cout << "Front: " << m_front << " - " << m_array[m_front]<< std::endl;
			}

			void push_front (const value_type& val)
			{
				if (m_size >= m_capacity || &m_array[m_front] == m_array)
					reserve(m_capacity + 10) ; // check way to reserve  + limit max_size
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
				// if(m_size)
				// {
					m_allocator.destroy(&m_array[m_front]);
					m_front++;
					m_size--;
				// }
				// }
			}
			
			void clear()
			{
				
				//m_allocator.deallocate(m_array, m_capacity);
				if (m_size)
				{	
					for(int i = m_front; i < m_rear; i++)
					{
					//	std::cout << "I:" << i << std::endl;
						m_allocator.destroy(&m_array[i]);
					}
				}
				// 	std::cout << "insideCLEAR\n" << std::flush;
				// //	m_allocator.destroy(&m_array[m_front]);
				// 	m_array = NULL;
				// //std::cout << "front: " <<  m_array[m_front] << std::flush;
				// }
				m_size = 0;
				//m_allocator.deallocate(m_array, m_capacity);
				// m_capacity =0;
				if (m_capacity)
					m_front = m_rear = m_capacity / 2;
				else
					m_front = m_rear = 0;
				//std::cout << "capacity: " << m_capacity << std::endl;
			//	m_allocator.deallocate(m_array, m_capacity);
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
			// std::cout << "LHS: " << *it_lhs << std::endl;
			// std::cout << "RHS: " << *it_rhs << std::endl;
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
		// std::cout << "RHS\n";
		typename ft::ConstIterator<T> it_rhs = rhs.begin();
		typename ft::ConstIterator<T> ite_rhs = rhs.end();
		
		while (it_lhs != ite_lhs)
		{
			// std::cout << "lhs: " << *it_lhs << std::endl;
			// std::cout << "rhs: " << *it_rhs << std::endl;
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