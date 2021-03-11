/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:38:21 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/11 15:21:45 by atetu            ###   ########.fr       */
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
			operator++(T) // ou int?
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
			
  			T&
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

	template <class T>
	class ConstIterator
	{
	public:
		typedef const T value_type;
		typedef const value_type& const_reference;
//		typedef value_type & reference;

	// private:
	// 	typedef Node<T> Node;
	
	// private:
	// 	const Node *m_node;
	
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
  			
			ConstIterator
			operator=(const ConstIterator &other)
			{
				// m_ptr = other.m_ptr;
				return (*this);
			}
			
			ConstIterator& 
			operator++()
			{
				m_ptr++;
				return (*this);
			}
			
  			ConstIterator
			operator++(T) // ou int?
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
			operator--(T) // ou int?
			{
				ConstIterator tmp(*this);
				operator--();
				return (tmp);
			}
			
  			bool
			operator==(const ConstIterator& other) const
			{
				std::cout << "ICI\n";
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

			const value_type*
			value() const
			{
				return (m_ptr);
			}
	
		// listConstIterator() : m_node(NULL)
		// {
		// }

		// listConstIterator(Node *node) : m_node(node)
		// {
		// }

		// listConstIterator(const Node *node) : m_node(node)
		// {
		// }

		// listConstIterator(const listConstIterator &other) : m_node(other.m_node)
		// {
		// }

		// listConstIterator
		// operator=(const listConstIterator &other)
		// {
		// 	m_node = other.m_node;
		// 	return (*this);
		// }

		// listConstIterator
		// operator++()
		// {
		// 	m_node = m_node->next();
		// 	return (*this);
		// }

		// listConstIterator
		// operator++(int)
		// {
		// 	listConstIterator tmp(*this);
		// 	operator++();
		// 	return (tmp);
		// }

		// listConstIterator &
		// operator--()
		// {
		// 	m_node = m_node->previous();
		// 	return (*this);
		// }

		// listConstIterator
		// operator--(int)
		// {
		// 	listConstIterator tmp(*this);
		// 	operator--();
		// 	return (tmp);
		// }

		// bool
		// operator==(const listConstIterator &other) const
		// {
		// 	return (m_node == other.m_node);
		// }

		// bool
		// operator!=(const listConstIterator &other) const
		// {
		// 	return (m_node != other.m_node);
		// }

		// reference
		// operator*() const
		// {
		// 	return (m_node->value());
		// 	//eturn (static_cast<const Node*>(m_node)->value());
		// }

		// const Node *
		// node() const
		// {
		// 	return (m_node);
		// }
	};

	// template <class Iterator>
	// 	struct iterator_traits
	// 	{
	// 		typedef typename Iterator::difference_type difference_type;
	// 		typedef typename Iterator::value_type value_type;
	// 		typedef typename Iterator::pointer pointer;
	// 		typedef typename Iterator::reference reference;
	// 		typedef typename Iterator::iterator_category iterator_category;
	// 	};
		
	// 		// typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_type;
	// 		// typedef typename ft::iterator_traits<Iterator>::value_type iterator_value;
	// 		// typedef	typename ft::iterator_traits<Iterator>::difference_type difference_type;
	// 		// typedef typename ft::iterator_traits<Iterator>::pointer pointer;
	// 		// typedef typename ft::iterator_traits<Iterator>::reference reference;

	// 	template <class T>
	// 	class ReverseIterator
	// 	{
	// 		private:
	// 			T *m_ptr;

	// 		public:
	// 			ReverseIterator() : 
	// 				m_ptr(NULL)
	// 			{
	// 			}

	// 			ReverseIterator(T* ptr):
	// 				m_ptr(ptr)
	// 			{
	// 			}
				
	// 			ReverseIterator(const T* ptr) :
	// 				m_ptr(ptr)
	// 			{
	// 			}
				
	// 			ReverseIterator(const ReverseIterator& other) : 
	// 				m_ptr(other.m_ptr)
	// 			{
	// 			}
				
	// 			ReverseIterator
	// 			operator=(const ReverseIterator &other)
	// 			{
	// 				m_ptr = other.m_ptr;
	// 				return (*this);
	// 			}
			
	// 			ReverseIterator
	// 			operator++()
	// 			{
	// 				m_ptr--;
	// 				return (*this);
	// 			}

	// 			ReverseIterator
	// 			operator++(int)
	// 			{
	// 				ReverseIterator tmp(*this);
	// 				operator++();
	// 				return (tmp);
	// 			}

	// 			ReverseIterator &
	// 			operator--()
	// 			{
	// 				m_ptr++;
	// 				return (*this);
	// 			}

	// 			ReverseIterator
	// 			operator--(int)
	// 			{
	// 				ReverseIterator tmp(*this);
	// 				operator--();
	// 				return (tmp);
	// 			}

	// 			bool
	// 			operator==(const ReverseIterator &other) const
	// 			{
	// 				return (m_ptr == other.m_ptr);
	// 			}

	// 			bool
	// 			operator!=(const ReverseIterator &other) const
	// 			{
	// 				return (m_ptr != other.m_ptr);
	// 			}

	// 			T&
	// 			operator*()
	// 			{
	// 				return (*m_ptr);
	// 			}

	// 			T*
	// 			value()
	// 			{
	// 				return (m_ptr);
	// 			}
	// 	};

	// 	template <class T>
	// 	class ConstReverseIterator
	// 	{
		
	// 		private:
	// 			T* m_ptr;

	// 		public:
	// 			ConstReverseIterator() : 
	// 				m_ptr(NULL)
	// 			{
	// 			}

	// 			ConstReverseIterator(T *ptr) :
	// 				m_ptr(ptr)
	// 			{
	// 			}

	// 			ConstReverseIterator(const T* ptr) : m_ptr(ptr)
	// 			{
	// 			}

	// 			ConstReverseIterator(const ConstReverseIterator &other) :
	// 				m_ptr(other.m_ptr)
	// 			{
	// 			}

	// 			ConstReverseIterator
	// 			operator=(const ConstReverseIterator &other)
	// 			{
	// 				m_ptr = other.m_ptr;
	// 				return (*this);
	// 			}

	// 			ConstReverseIterator
	// 			operator++()
	// 			{
	// 				m_ptr--;
	// 			}

	// 			ConstReverseIterator
	// 			operator++(int)
	// 			{
	// 				ConstReverseIterator tmp(*this);
	// 				operator++();
	// 				return (tmp);
	// 			}

	// 			ConstReverseIterator &
	// 			operator--()
	// 			{
	// 				m_ptr--;
	// 				return (*this);
	// 			}

	// 			ConstReverseIterator
	// 			operator--(int)
	// 			{
	// 				ConstReverseIterator tmp(*this);
	// 				operator--();
	// 				return (tmp);
	// 			}

	// 			bool
	// 			operator==(const ConstReverseIterator &other) const
	// 			{
	// 				return (m_ptr == other.m_ptr);
	// 			}

	// 			bool
	// 			operator!=(const ConstReverseIterator &other) const
	// 			{
	// 				return (m_ptr != other.m_ptr);
	// 			}

	// 			T&
	// 			operator*() const
	// 			{
	// 				return (*m_ptr);
	// 				//return (static_cast<const Node*>(m_node)->value());
	// 			}

	// 			T *
	// 			value() const
	// 			{
	// 				return (m_ptr);
	// 			}
	// 		};


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