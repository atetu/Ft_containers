/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:17:43 by alicetetu         #+#    #+#             */
/*   Updated: 2021/02/25 20:02:17 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "Iterator.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
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
			value_type* m_array;
			int m_size;
			int m_capacity;
		
		public:
			explicit vector(const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(nullptr),
				m_size(0),
				m_capacity(0)
			{
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(nullptr),
				m_size(0),
				m_capacity(0)
			{
				assign(n, val);
			}

			// Implementation for class types other than integral types (char, int...)
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) :
				m_allocator(alloc),
				m_array(nullptr),
				m_size(0),
				m_capacity(0)
			{
				//std::cout << "WHERE IT SHOULD NOT BE\n" << std::flush;
				assign(first, last);
			}

			vector (const vector& x) :
				m_allocator(x.m_allocator),
				m_array(nullptr),
				m_size(0),
				m_capacity(0)
			{
				// check size of x??
				assign(x.begin(), x.end());
			}

			~vector()
			{
				//clear
				m_allocator.deallocate(m_array, m_size);
			}

			vector& operator= (vector const & x)
			{
				if (this != &x)
				{
					//clear();
					m_allocator = x.m_allocator;
					m_array = nullptr;
					m_size = 0;
					m_capacity = 0;
					
				//	const_iterator it = x.begin();
				//	std::cout << "IT: " << it.value() << std::endl;
					
					if (x.m_capacity != 0)
						reserve(m_capacity);
				
					if (x.size() != 0)
						assign(x.begin(), x.end());
				
				}
				return(*this);
			}
			
			/*ITERATORS*/

			iterator begin()
			{
				return (iterator(m_array));
			}
			
			const_iterator begin() const
			{
				return (const_iterator(&m_array[0]));
			}
			
			iterator end()
			{
				return (iterator(&m_array[m_size]));
			}
			
			const_iterator end() const
			{
				return (const_iterator(&m_array[m_size]));
			}
			/*CAPACITY*/

			size_type size() const
			{
				return (m_size);
			}

			size_type max_size() const
			{
					return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			}
			
			void resize (size_type n, value_type val = value_type())
			{
				if (n < m_size)
				{
					erase(iterator(&m_array[n]), iterator (&m_array[m_size]));
					//m_size too adapat
				}
				else if (n > m_size)
				{
					if (n + 1 > m_capacity)
						reserve(n + 10); // check max
					for(size_type i = m_size; i < n; i++)
						push_back(val);
				}
			}
			
			size_type capacity() const
			{
				return (m_capacity);
			}
			
			bool empty() const
			{
				return (m_size == 0);
			}
			
			void reserve(size_type n)
			{
				if (n > m_capacity)
				{
					clear();
					
					m_array = m_allocator.allocate(n);
					// }
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

			iterator insert (iterator position, const value_type& val)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				iterator start;
				iterator ret;
				// check capacity
				if (position != end())
				{
					start = position;
					start--;
					copy.assign(position, end());
					copyToDo = true;
					erase(position, end());
					
				}
				push_back(val);
				ret = end();
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
				return (ret);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				iterator start;
					// check capacity
				if (position != end())
				{
					start = position;
					start--;
					copy.assign(position, end());
					copyToDo = true;
					erase(position, end());
				}
				for (;m_size < n +1 ; m_size++)
					push_back(val);
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
			}
			
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
					
					// check capacity
			
				if (position != end())
				{
					copy.assign(position, end());
					copyToDo = true;
					erase(position, end());
				}
				for (;first != last; first++)
					push_back(*first);
				
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
			}

			iterator erase (iterator position)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				iterator ret;
				
				if (position != end() && position != end()--)
				{
					copy.assign(position++, end());
					copyToDo = true;
				}
				ret = position;
				if (ret != begin())
					ret--;
				m_allocator.destroy(position.value());
				// m_allocator.deallocate(position.pointer());
				m_size--;
				if (copyToDo)
				{
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
					ret++;
				}
				return (ret);
			}
			
			iterator erase (iterator first, iterator last)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				iterator start;
				iterator tmp;
				std::cout << "ICI\n" << std::flush;
				if (last != end() && last != end()--)
				{
					start = first;
					start--;
					copy.assign(last, end());
					copyToDo = true;
				}
				
				size_type toDelete = end().value() - first.value();
				
				m_allocator.destroy(first.value()); // does it destroy all the rest of the vector until the end?
				m_size -= toDelete;;
		
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
				return (last); // to check
			}

			void clear()
			{
				m_allocator.destroy(m_array);
				m_size = 0;
			}
	};
};
#endif