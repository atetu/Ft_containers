/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:38:21 by alicetetu         #+#    #+#             */
/*   Updated: 2021/02/24 11:51:03 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
//https://www.cplusplus.com/reference/iterator/iterator/

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct iterator
	{
		typedef T         value_type; //Type of elements pointed by the iterator.

		typedef Distance  difference_type; //Type to represent the difference between two iterators.
		typedef Pointer   pointer;//Type to represent a pointer to an element pointed by the iterator.
		typedef Reference reference;//Type to represent a reference to an element pointed by the iterator.
		typedef Category  iterator_category;//Category to which the iterator belongs to
	};

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
	
	

	template<class T>
	class Iterator //: public ft::iterator<ft::input_iterator_tag, T>
	{
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
  			
			Iterator& 
			operator++()
			{
				++m_ptr;
				return (*this);
			}
			
  			Iterator
			operator++(T) // ou int?
			{
				Iterator tmp(*this);
				operator++();
				return (tmp);
			}
			
			Iterator& 
			operator--()
			{
				--m_ptr;
				return (*this);
			}
			
  			Iterator
			operator--(T) // ou int?
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
			
  			int&
			operator*()
			{
				return (*m_ptr);
			}

			T*
			value()
			{
				return (m_ptr);
			}
		
	};

	template <class Iterator>
		struct iterator_traits
		{
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;
			typedef typename Iterator::iterator_category iterator_category;
		};
		
	template<class Iter>
		class ReverseIterator
		{
			// typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_type;
			// typedef typename ft::iterator_traits<Iterator>::value_type iterator_value;
			// typedef	typename ft::iterator_traits<Iterator>::difference_type difference_type;
			// typedef typename ft::iterator_traits<Iterator>::pointer pointer;
			// typedef typename ft::iterator_traits<Iterator>::reference reference;

			typedef typename Iter::iterator_category iterator_type;
			typedef typename Iter::value_type iterator_value;
			typedef	typename Iter::difference_type difference_type;
			typedef typename Iter::pointer pointer;
			typedef typename Iter::reference reference;
			
			private :
			iterator_type m_it;

			public:
				ReverseIterator() :
					m_it(NULL)
				{
				};

				explicit ReverseIterator(iterator_type it) :
					m_it(it)
				{					
				}

				template <class U>
				ReverseIterator(const ReverseIterator<U>& other) :
					m_it(other.m_it)
				{	
				}
			

			iterator_type
			base() const
			{
				return (m_it);
			}
		};


}
#endif
// template<class Iter>
// class ReverseIterator : public Iter
// {
// 	typedef typename Iter::value_type value_type;
// 	typedef typename Iter::pointer pointer;
// 	typedef typename Iter::const_pointer const_pointer;
// 	typedef typename Iter::reference reference;
// 	typedef typename Iter::const_reference const_reference;
// }