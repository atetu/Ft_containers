/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:38:21 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/16 15:17:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
//https://www.cplusplus.com/reference/iterator/iterator/

namespace ft
{
	template<class T>
	class Iterator
	{
		public:
			typedef T value_type;
			typedef const T const_value_type;
			typedef value_type &reference;
			typedef value_type* pointer;
			typedef const_value_type* const_pointer;
			
			static const bool It;
			
		private:
			T *m_ptr;
			
		public:
			Iterator() : 
				m_ptr(NULL)
			{
			}

			Iterator(T* ptr):
				m_ptr(ptr)
			{
			}
			
			Iterator(const T* ptr) :
				m_ptr(ptr)
			{
			}
			
			Iterator(const Iterator& other) : 
				m_ptr(other.m_ptr)
			{
			}
			
			~Iterator()
			{
			}
			
			Iterator
			operator=(const Iterator &other)
			{
				m_ptr = other.m_ptr;
				return (*this);
			}
			
			Iterator& 
			operator++()
			{
				m_ptr++;
				return (*this);
			}
			
  			Iterator
			operator++(int)
			{
				Iterator tmp(*this);
				operator++();
				return (tmp);
			}
			
			Iterator& 
			operator--()
			{
				m_ptr--;
				return (*this);
			}
			
  			Iterator
			operator--(int)
			{
				Iterator tmp(*this);
				operator--();
				return (tmp);
			}
			
  			bool
			operator==(const Iterator& other) const
			{
				return (m_ptr == other.m_ptr);
			}
			
  			bool
			operator!=(const Iterator& other) const
			{
				return (m_ptr != other.m_ptr);
			}
			
  			T&
			operator*() const
			{
				return (*m_ptr);
			}

			T&
			operator->() const
			{
				return (&(*m_ptr));
			}
			
			pointer
			node() const
			{
				return (m_ptr);
			}

			Iterator
			base() const
			{
				return(*this);
			}

			Iterator
			operator+(int value)
			{
				Iterator tmp(*this);
				tmp += value;
				return(tmp);
			}

			Iterator
			operator-(int value)
			{
				Iterator tmp(*this);
				tmp -=value;
				return(tmp);
			}
			
			bool
			operator<(const Iterator& other) const
			{
				return(m_ptr < other.node());
			}

			bool
			operator>(const Iterator& other) const
			{
				return(m_ptr > other.node());
			}

			bool
			operator<=(const Iterator& other) const
			{
				return(m_ptr <= other.node());
			}

			bool
			operator>=(const Iterator& other) const
			{
				return(m_ptr >= other.node());
			}

			Iterator
			operator+=(int value)
			{
				m_ptr +=value;
				return(*this);
			}

			Iterator
			operator-=(int value)
			{
				m_ptr -=value;
				return(*this);
			}
	};

	template <class T>
	int operator-(Iterator<T> &it, Iterator<T> &it2)
	{
		int ret = it.node() - it2.node();
		if (ret < 0)
			ret = -ret;
		return (ret);
	}
	
	template <class T>
	const bool Iterator<T>::It = true;
	
	template <class T>
	class ConstIterator
	{
	public:
		typedef T value_type;
		typedef const T const_value_type;
		typedef value_type &reference;
		typedef const_value_type& const_reference;
		typedef value_type* pointer;
		typedef const_value_type* const_pointer;
	
		static const bool It;
		
	private:
		value_type *m_ptr;

	public:
		public:
			ConstIterator() : 
				m_ptr(NULL)
			{
			}

			ConstIterator(T* ptr):
				m_ptr(ptr)
			{
			}
			
			ConstIterator(const T* ptr) :
				m_ptr(ptr)
			{
			}
			
			ConstIterator(const ConstIterator& other) : 
				m_ptr(other.m_ptr)
			{
			}

			~ConstIterator()
			{
			}
  			
			ConstIterator
			operator=(const ConstIterator &other)
			{
				m_ptr = other.m_ptr;
				return (*this);
			}
			
			ConstIterator& 
			operator++()
			{
				m_ptr++;
				return (*this);
			}
			
  			ConstIterator
			operator++(int)
			{
				ConstIterator tmp(*this);
				operator++();
				return (tmp);
			}
			
			ConstIterator& 
			operator--()
			{
				m_ptr--;
				return (*this);
			}
			
  			ConstIterator
			operator--(int)
			{
				ConstIterator tmp(*this);
				operator--();
				return (tmp);
			}
			
  			bool
			operator==(const ConstIterator& other) const
			{
				return (m_ptr == other.m_ptr);
			}
			
  			bool
			operator!=(const ConstIterator& other) const
			{
				return (m_ptr != other.m_ptr);
			}
			
  			const_reference
			operator*() const
			{
				return (*m_ptr);
			}

			const_reference
			operator->() const
			{
				return (&(*m_ptr));
			}
			const value_type*
			node() const
			{
				return (m_ptr);
			}
	

			ConstIterator
			base() const
			{
				return(*this);
			}

			ConstIterator
			operator+(int value)
			{
				ConstIterator tmp(*this);
				tmp +=value;
				return(tmp);
			}

			ConstIterator
			operator-(int value)
			{
				ConstIterator tmp(*this);
				tmp -=value;
				return(tmp);
			}

			bool
			operator<(ConstIterator& other) const
			{
				return(m_ptr < other.node());
			}

			bool
			operator>(ConstIterator& other) const
			{
				return(m_ptr > other.node());
			}

			bool
			operator<=(ConstIterator& other) const
			{
				return(m_ptr <= other.node());
			}

			bool
			operator>=(ConstIterator& other) const
			{
				return(m_ptr >= other.node());
			}

			ConstIterator
			operator+=(int value)
			{
				m_ptr = m_ptr + value;
				return(*this);
			}

			ConstIterator
			operator-=(int value)
			{
				m_ptr = m_ptr - value;
				return(*this );
			}
	};

	template <class T>
	int operator-(ConstIterator<T> &it, ConstIterator<T> &it2)
	{
		int ret = it.node() - it2.node();
		if (ret < 0)
			ret = -ret;
		return (ret);
	}
	
	template <class T>
	const bool ConstIterator<T>::It = true;
}
#endif
