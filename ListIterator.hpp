/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:38:21 by alicetetu         #+#    #+#             */
/*   Updated: 2021/01/15 14:09:22 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

#include <iterator>
#include "list.hpp"
// https://www.cplusplus.com/reference/iterator/iterator/

namespace ft
{
	template<class T>
		class ListIterator : public Iterator
	{
		public:
			// typedef typename Iter::value_type value_type;
			// typedef typename Iter::pointer pointer;
			// typedef typename Iter::const_pointer const_pointer;
			// typedef typename Iter::reference reference;
			// typedef typename Iter::const_reference const_reference;
		
			typedef ft::bidirectional_iterator_tag iterator_category;
			typedef T value_type;
			typedef ptrdiff_t difference_type;
			typedef T *pointer;
			typedef T &reference;

		
		private:
			typedef typename ft::Node<T> Node;
//			typedef ft::Node<T> node;
		
		private:
			Node *m_node;
			
		public:
			ListIterator() : 
				m_node(NULL)
			{
			}

			ListIterator(Node *node):
				m_node(node)
			{
			}
			
			ListIterator(const Node *node) :
				m_node(node)
			{
			}
			
			ListIterator(const ListIterator& other) : 
				m_node(other.m_node)
			{
			}
  			
			ListIterator& 
			operator++()
			{
				m_node = m_node->next();
				return (*this);
			}
			
  			ListIterator
			operator++(int) // ou int?
			{
				ListIterator tmp(*this);
				operator++();
				return (tmp);
			}
			
			ListIterator& 
			operator--()
			{
				m_node = m_node->previous();
				return (*this);
			}
			
  			ListIterator
			operator--(int) // ou int?
			{
				ListIterator tmp(*this);
				operator--();
				return (tmp);
			}
			
  			bool
			operator==(const ListIterator& other) const
			{
				return (m_node == other.m_node);
			}
			
  			bool
			operator!=(const ListIterator& other) const
			{
				return (m_node != other.m_node);
			}
			
  			int&
			operator*()
			{
				return (*m_node);
			}

			Node*
			node()
			{
				return (m_node);
			}
		
	};

	
	// template<class Iterator>
	// 	class ReverseIterator
	// 	{
	// 		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_type;
	// 		typedef typename ft::iterator_traits<Iterator>::value_type iterator_value;
	// 		typedef	typename ft::iterator_traits<Iterator>::difference_type difference_type;
	// 		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
	// 		typedef typename ft::iterator_traits<Iterator>::reference reference;

	// 		private :
	// 		iterator_type m_it;

	// 		public:
	// 			ReverseIterator() :
	// 				m_it(NULL)
	// 			{
	// 			};

	// 			explicit ReverseIterator(iterator_type it) :
	// 				m_it(it)
	// 			{					
	// 			}

	// 			template <class U>
	// 			ReverseIterator(const ReverseIterator<U>& other) :
	// 				m_it(other.m_it)
	// 			{	
	// 			}
			

	// 		iterator_type
	// 		base() const
	// 		{
	// 			return (m_it);
	// 		}
	// 	};


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