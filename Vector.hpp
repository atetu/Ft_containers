/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:17:43 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/16 15:24:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <exception>
#include <cmath>
#include <cstddef>

#include "Iterator.hpp"
#include "ReverseIterator.hpp"

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
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
		
		private:
			allocator_type m_allocator;
			value_type* m_array;
			int m_size;
			int m_capacity;
		
		public:
			explicit vector(const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(NULL),
				m_size(0),
				m_capacity(0)
			{
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(NULL),
				m_size(0),
				m_capacity(0)
			{
				assign(n, val);
			}

			// Implementation for class types other than integral types (char, int...)
			template <class InputIterator>
			vector (InputIterator first, typename allow_if<InputIterator::It, InputIterator>::type last, const allocator_type& alloc = allocator_type()) :
				m_allocator(alloc),
				m_array(NULL),
				m_size(0),
				m_capacity(0)
			{
				assign(first, last);
			}

			vector (const vector& x) :
				m_allocator(x.m_allocator),
				m_array(NULL),
				m_size(0),
				m_capacity(0)
			{
				assign(x.begin(), x.end());
			}

			~vector()
			{
				clear();
				m_allocator.deallocate(m_array, m_size);
			}

			vector& operator= (vector const & x)
			{
				if (this != &x)
				{
					clear();
					m_allocator = x.m_allocator;
					m_array = NULL;
					m_size = 0;
					m_capacity = 0;
					
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

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				iterator beg = begin();
				return (reverse_iterator(beg));
			}

			const_reverse_iterator rend() const
			{
				iterator beg = begin();
				return (const_reverse_iterator(beg));
			}
			
			/*CAPACITY*/

			size_type size() const
			{
				return (m_size);
			}

			size_type max_size() const
			{
				 return (std::min((size_type) std::numeric_limits<difference_type>::max(),
                        std::numeric_limits<size_type>::max() / sizeof(value_type)));	
			}
			
			void resize (size_type n, value_type val = value_type())
			{
				if ((int)n < m_size)
				{
					erase(iterator(&m_array[n]), iterator (&m_array[m_size]));
				}
				else if ((int)n > m_size)
				{
					if ((int)n > m_capacity)
						reserve(n);
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
				if (n > max_size())
					throw (std::length_error("Reservation exceeds max size"));
				if ((int)n > m_capacity)
				{
					if (m_capacity)
					{
						T* copy = m_allocator.allocate(n);
						
						for (int i = 0; i < m_size; i++)
							m_allocator.construct(copy + i, m_array[i]);
						m_allocator.destroy(m_array);
						m_allocator.deallocate(m_array, m_size);
						m_array = copy;
					}
					else
					{
						m_array = m_allocator.allocate(n);
					}
					m_capacity = n;
				}
			}

			/*ELEMENT ACCESS*/

			reference operator[] (size_type n)
			{
				return(m_array[n]);
			}
			
			const_reference operator[] (size_type n) const
			{
				return(m_array[n]);
			}
			
			reference at (size_type n)
			{
				if (m_size == 0 || (int)n < 0 || (int)n >= m_size)
				{
					throw (std::out_of_range("vector"));
				}
				else
					return(m_array[n]);		
			}
			
			const_reference at (size_type n) const
			{
				if (m_size == 0 || n < 0 || n >= m_size)
				{
					throw (std::out_of_range("vector"));
				}
				else
					return(m_array[n]);		
			}

			reference front()
			{
				return (m_array[0]);
			}

			const_reference front() const
			{
				return (m_array[0]);
			}

			reference back()
			{
				return (m_array[m_size - 1]);
			}

			const_reference back() const
			{
				return (m_array[m_size - 1]);
			}

			/*MODIFIERS*/
			
			void assign(size_type n, const value_type& val)
			{
				clear();
				
				if ((int)n >= m_capacity)
					reserve(n) ;
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
			
			template <class InputIterator>
			void assign (InputIterator first, typename allow_if<InputIterator::It, InputIterator>::type last)
			{
				clear();
				int neededSize = last.node() - first.node();
				if (neededSize < 0)
					neededSize = -neededSize;
				if (neededSize >= m_capacity)
					reserve(neededSize);
				for (;first != last; first++)
					push_back(*first);
			}

			void push_back (const value_type& val)
			{
				if (m_size + 1 > m_capacity)
					reserve(calculate_capacity(m_size + 1));
				m_allocator.construct(m_array + m_size, val);
				m_size++;
			}

			void pop_back()
			{
				iterator last = end();
				last--;
				if (m_size != 0)
					erase(last);
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				iterator start;
				iterator ret;
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
				if (n < 0)
					return;
				int p = position.node()- begin().node();
						
				if ((m_size + (int)n ) > m_capacity)
					reserve(calculate_capacity(m_size + n));
	
				if (&m_array[p] != end().node())
				{
					copy.assign(iterator(&m_array[p]), end());
					copyToDo = true;
					erase(iterator(&m_array[p]), end());
				}
				for (size_type i = 0; i < n; i++)
					push_back(val);
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
			}
			
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, typename allow_if<InputIterator::It, InputIterator>::type last)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				int p = position.node()- begin().node();
								
				difference_type neededSize = last - first;
				if (neededSize < 0)
					neededSize = -neededSize;
			
				if ((m_size + (int)neededSize + 1) > m_capacity)
					reserve(calculate_capacity(m_size + neededSize));
							
				if (&m_array[p] != end().node())
				{
					copyToDo = true;
					copy.assign(iterator(&m_array[p]), end());
					erase(iterator(&m_array[p]), end());
				}
				
				for (; first != last; first++)
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
					copy.assign(position, end());
					copyToDo = true;
				}
				ret = position;
				if (ret != begin())
					ret--;
				erase(position, end());
				if (copyToDo)
				{
					iterator start = copy.begin();
					start++;
					insert(iterator(&m_array[m_size]), start, copy.end());
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
			
				if (last != end() && last != end()--)
				{
					start = first;
					start--;
					copy.assign(last, end());
					copyToDo = true;
				}
				
				size_type toDelete = end().node() - first.node();
				
				m_allocator.destroy(first.node());
				m_size -= toDelete;;
		
				if (copyToDo)
					insert(iterator(&m_array[m_size]), copy.begin(), copy.end());
				return (last);
			}

			void clear()
			{
				m_allocator.destroy(m_array);
				m_size = 0;
			}

			void swap(vector &x)
			{
				ft::vector<T> copy;
				size_type x_capacity = x.capacity();
				size_type this_capacity = capacity();
				copy.assign(begin(), end());
				erase(begin(), end());
				reserve(x_capacity);
				insert(begin(), x.begin(), x.end());
				x.erase(x.begin(), x.end());
				x.reserve(this_capacity);
				x.assign(copy.begin(), copy.end());
				copy.clear();
			}

		private:
			size_type calculate_capacity (size_type neededCapacity)
			{
				size_type ret = 0;
				size_type exponent = 0;
				while (ret < neededCapacity)
					ret = pow(2, exponent++);
				return (ret);
			}
	};

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator ite_lhs = lhs.end();
		typename ft::vector<T>::const_iterator it_rhs = rhs.begin();
		typename ft::vector<T>::const_iterator ite_rhs = rhs.end();
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
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return(!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename ft::vector<T>::const_iterator it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator ite_lhs = lhs.end();
		typename ft::vector<T>::const_iterator it_rhs = rhs.begin();
		typename ft::vector<T>::const_iterator ite_rhs = rhs.end();
		
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
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	
};
#endif