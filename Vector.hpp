/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:17:43 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/11 16:35:14 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <exception>

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
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
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
				clear();
				m_allocator.deallocate(m_array, m_size);
			}

			vector& operator= (vector const & x)
			{
				if (this != &x)
				{
					clear();
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
				if (m_size)
				{
					iterator beg = begin();
					beg++;
					return (reverse_iterator(beg));
				}
				else
					return(reverse_iterator(end(), 0));
			}

			const_reverse_iterator rend() const
			{
				if (m_size)
				{
					iterator beg = begin();
					beg++;
					return (const_reverse_iterator(beg));
				}
				else
					return(const_reverse_iterator(end(), 0));
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
					if (m_capacity)
					{
						T* copy = m_allocator.allocate(n);
						
						for (size_type i = 0; i < m_size; i++)
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
				//copy
			}

			
			/*ELEMENT ACCESS*/

			reference operator[] (size_type n)
			{
				return(m_array[n]);
			}
			
			const_reference operator[] (size_type n) const
			{
				return(m_array[n]); // check
			}
			
			reference at (size_type n)
			{
				if (m_size == 0 || n < 0 || n >= m_size)
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
				// std::cout << "Val: " << val << std::endl;
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
				// check capacity
				if (position != end())
				{
					// std::cout << "ICI\n";
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
				//VERIFIER MAX SIZE
				if (n < 0)
					return;
				int p = position.value()- begin().value();
						
				if ((m_size + n + 1) > m_capacity)
					reserve(m_size + n + 1);
	
				if (&m_array[p] != end().value())
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
    		void insert (iterator position, InputIterator first, InputIterator last,
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
			{
				bool copyToDo = false;
				ft::vector<T> copy;
				int p = position.value()- begin().value();
								
				int neededSize = last.value() - first.value();
				if (neededSize < 0)
					neededSize = -neededSize;
			
				if ((m_size + neededSize + 1) > m_capacity)
					reserve(m_size + neededSize + 1);
							
				if (&m_array[p] != end().value())
				{
					copyToDo = true;
					copy.assign(iterator(&m_array[p]), end());
					erase(iterator(&m_array[p]), end());
				}
				
				for (; first != last; first++)
				{
					// std::cout << "First:" << *first << std::endl;
					push_back(*first);
				}
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
				// std::cout << "SIZE: " << m_size << std::endl;
				// std::cout << "Begin: " << *(copy.begin()) << std::endl;
				// std::cout << "Begin++: " << *(copy.begin()++) << std::endl;
			//	m_allocator.destroy(position.value());
			//	m_size--;
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