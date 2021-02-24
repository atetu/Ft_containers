/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:17:43 by alicetetu         #+#    #+#             */
/*   Updated: 2021/02/24 19:01:35 by alicetetu        ###   ########.fr       */
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
			typedef ft::ReverseIterator<T> reverse_iterator;
			typedef ft::ConstReverseIterator<T> const_reverse_iterator;
		
		private:
			allocator_type m_allocator;
			pointer m_array;
			int m_size;
			int m_capacity;
		
		public:
			explicit vector(const allocator_type& alloc = allocator_type()) : m_allocator(alloc), m_array(nullptr), m_size(0), m_capacity(0)
			{
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_allocator(alloc), m_array(nullptr), m_size(0), m_capacity(0)
			{
				assign(n, val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(nullptr),
				m_size(0),
				m_capacity(0)
			{
				assign(first, last);
			}

			vector (const vector& x) :
				m_allocator(x.m_allocator),
				m_array(nullptr),
				m_size(x.m_size),
				m_capacity(x.m_capacity)
			{
				assign(other.begin(), other.end());
			}

			~vector()
			{
				//clear
			}

			vector& operator= (const vector& x)
			{
				if (this != &x)
				{
					//clear();
					m_allocator = x.m_allocator;
					m_array = nullptr;
					m_size = x.m_size;
					m_capacity = x.m_capacity;
					
					assign(other.begin(), other.end());
				}
			}
			
			/*ITERATORS*/

			iterator begin()
			{
				return (iterator(&m_array[0]));
			}
			
			// const_iterator begin() const
			// {
				
			// }
			
			iterator end()
			{
				return (iterator(&m_array[m_size + 1]));
			}
			
			
			/*CAPACITY*/

			size_type size() const
			{
				return (m_size);
			}

			size_type max_size() const
			{
					return (std::numeric_limits<size_type>::max() / sizeof(pointer));
			}
			
			voir reserve(size_type n)
			{
				if (n > m_capacity)
				{
					//if (n <= max_size())
					for (size_type i = 0; i < n; i++)
					{
						//clear;
						m_array = m_allocator.allocate(n);
					}
					m_capacity = n;
				}
				//copy
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
					for(size_type i = m_ size; i < n + 1; i++)
						push_back(val);
				}
			}
			


			/*MODIFIERS*/
			
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
			//	clear();
				int neededSize = last - first;
				if (neededSize < 0)
					neededSize = -neededSize;
				if (neededSize >= m_capacity)
					reserve(neededSize + 10); // check max limit
				for (;first != last; first++)
				{
					push_back(*first);
				}
			}

			void assign(size_type n, const value_type& val)
			{
				clear();
				
				if (n >= m_capacity)
					reserve(n +10) ; // check way to reserve  + limit max_size
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			void push_back (const value_type& val)
			{
				if (m_size + 1 >= m_capacity)
					reserve(m_size + 10) ; // check way to reserve  + limit max_size
				m_allocator.construct(&m_array[m_size], val)
				m_size++;
			}

			iterator insert (iterator position, const value_type& val)
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
				
				push_back(val);
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
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
				for (;first < last; first++)
					push_back(*first);
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
			}

			iterator erase (iterator position)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				iterator start;
				
				if (position != end() && position != end()--)
				{
					start = position;
					start--;
					copy.assign(position++, end());
					copyToDo = true;
				}
				m_allocator.destroy(position.pointer());
				m_allocator.deallocate(position.pointer());
				m_size--;
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
			}
			
			iterator erase (iterator first, iterator last)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				iterator start;
				iterator tmp;
				
				if (last != end() && last != end()--)
				{
					start = first;
					start--;
					copy.assign(last, end());
					copyToDo = true;
				}
				while(first != last)
				{
					tmp = first;
					tmp++;
					m_allocator.destroy(first.pointer());
					m_allocator.deallocate(first.pointer());
					m_size--;
				}
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
			}
	};
};
#endif