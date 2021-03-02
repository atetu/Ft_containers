/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:38:21 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/02 15:09:36 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEITERATOR_HPP
# define DEQUEITERATOR_HPP

// #include <iterator>
// #include "Base.hpp"
// #include "Deque.hpp"

//https://www.cplusplus.com/reference/iterator/iterator/

namespace ft
{
	// template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	// 	struct iterator
	// {
	// 	typedef T         value_type; //Type of elements pointed by the iterator.

	// 	typedef Distance  difference_type; //Type to represent the difference between two iterators.
	// 	typedef Pointer   pointer;//Type to represent a pointer to an element pointed by the iterator.
	// 	typedef Reference reference;//Type to represent a reference to an element pointed by the iterator.
	// 	typedef Category  iterator_category;//Category to which the iterator belongs to
	// };

	// struct input_iterator_tag {};
	// struct output_iterator_tag {};
	// struct forward_iterator_tag {};
	// struct bidirectional_iterator_tag {};
	// struct random_access_iterator_tag {};
	
	

	template<class T>
	class DequeIterator : public Base
	{
		private:
			int m_index;
			T *m_array;
			int m_front;
			int m_rear;
			int m_size;
			int m_capacity;
			
		public:
			,
				m_array(NULL),
				m_front(0),
				m_rear(0),
				m_size(0),
				m_capacity(0)
			{
			}

			DequeIterator(int index, T *array, int front, int rear, int size, int capacity):
				m_index(index),
				m_array(array),
				m_front(front),
				m_rear(rear),
				m_size(size),
				m_capacity(capacity)
			{
			}
			
			// DequeIterator(const T* ptr) :
			// 	m_ptr(ptr)
			// {
			// }
			
			DequeIterator(const DequeIterator& other) : 
				m_index(other.m_index),
				m_array(other.m_array),
				m_front(other.m_front),
				m_rear(other.m_rear),
				m_size(other.m_size),
				m_capacity(other.m_capacity)
			{
			}
  			
			DequeIterator
			operator=(const DequeIterator &other)
			{
				m_index = other.m_index;
				m_array = other.m_array;
				m_front = other.m_front;
				m_rear = other.m_rear;
				m_size = other.m_size;
				m_capacity = other.m_capacity;
				
				return (*this);
			}
			
			DequeIterator& 
			operator++()
			{
				int front;
				if (m_front < 0)
					front = 0;
				else
					front = m_capacity - 1;
				
				if (m_index >= 0 && m_index <= m_rear)
				{
					m_index++; // check overflow
					if (m_index == m_front)
						m_index = m_size; // reproduce the segfault
				}
				else if(m_index >= m_front && m_index < m_capacity)
				{
					m_index--;
					if (m_index == m_rear)
						m_index = m_size; // reproduce the segfault
				}
				return (*this);
			}
			
  			DequeIterator
			operator++(T) // ou int?
			{
				DequeIterator tmp(*this);
				operator++();
				return (tmp);
			}
			
			DequeIterator& 
			operator--()
			{
				int front;
				if (m_front < 0)
					front = 0;
				else
					front = m_capacity - 1;
				
				if (m_index >= 0 && m_index <= m_rear)
				{
					m_index--; // check overflow
					// if (m_index == m_front)
					// 	m_index = m_size; // reproduce the segfault
				}
				else if(m_index >= m_front)
				{
					m_index++;
					// if (m_index == m_rear)
					// 	m_index = m_size; // reproduce the segfault
				}
				return (*this);
			}
			
  			DequeIterator
			operator--(T) // ou int?
			{
				DequeIterator tmp(*this);
				operator--();
				return (tmp);
			}
			
  			bool
			operator==(const DequeIterator& other) const
			{
				return (m_index == other.m_index &&	m_array == other.m_array
					&& m_front == other.m_front && m_rear == other.m_rear
					&& m_size == other.m_size && m_capacity == other.m_capacity);
			}
			
  			bool
			operator!=(const DequeIterator& other) const
			{
				return (!(operator==(other)));
			}
			
  			T&
			operator*()
			{
				return (m_array[m_index]);
			}

			T*
			value()
			{
				return (m_index);
			}
		
	};

// 	template <class T>
// 	class ConstIterator
// 	{
// 	public:
// 		typedef const T value_type;
// 		typedef const value_type& const_reference;
// //		typedef value_type & reference;

// 	// private:
// 	// 	typedef Node<T> Node;
	
// 	// private:
// 	// 	const Node *m_node;
	
// 	private:
// 			value_type *m_ptr;

// 	public:
// 		public:
// 			ConstIterator() : 
// 				m_ptr(NULL)
// 			{
// 			}

// 			ConstIterator(T* ptr):
// 				m_ptr(ptr)
// 			{
// 			}
			
// 			ConstIterator(const T* ptr) :
// 				m_ptr(ptr)
// 			{
// 			}
			
// 			ConstIterator(const ConstIterator& other) : 
// 				m_ptr(other.m_ptr)
// 			{
// 			}
  			
// 			ConstIterator
// 			operator=(const ConstIterator &other)
// 			{
// 				// m_ptr = other.m_ptr;
// 				return (*this);
// 			}
			
// 			ConstIterator& 
// 			operator++()
// 			{
// 				m_ptr++;
// 				return (*this);
// 			}
			
//   			ConstIterator
// 			operator++(T) // ou int?
// 			{
// 				ConstIterator tmp(*this);
// 				operator++();
// 				return (tmp);
// 			}
			
// 			ConstIterator& 
// 			operator--()
// 			{
// 				m_ptr--;
// 				return (*this);
// 			}
			
//   			ConstIterator
// 			operator--(T) // ou int?
// 			{
// 				ConstIterator tmp(*this);
// 				operator--();
// 				return (tmp);
// 			}
			
//   			bool
// 			operator==(const ConstIterator& other) const
// 			{
// 				std::cout << "ICI\n";
// 				return (m_ptr == other.m_ptr);
// 			}
			
//   			bool
// 			operator!=(const ConstIterator& other) const
// 			{
// 				return (m_ptr != other.m_ptr);
// 			}
			
//   			const_reference
// 			operator*() const
// 			{
// 				return (*m_ptr);
// 			}

// 			const value_type*
// 			value() const
// 			{
// 				return (m_ptr);
// 			}
	
// 		// listConstIterator() : m_node(NULL)
// 		// {
// 		// }

// 		// listConstIterator(Node *node) : m_node(node)
// 		// {
// 		// }

// 		// listConstIterator(const Node *node) : m_node(node)
// 		// {
// 		// }

// 		// listConstIterator(const listConstIterator &other) : m_node(other.m_node)
// 		// {
// 		// }

// 		// listConstIterator
// 		// operator=(const listConstIterator &other)
// 		// {
// 		// 	m_node = other.m_node;
// 		// 	return (*this);
// 		// }

// 		// listConstIterator
// 		// operator++()
// 		// {
// 		// 	m_node = m_node->next();
// 		// 	return (*this);
// 		// }

// 		// listConstIterator
// 		// operator++(int)
// 		// {
// 		// 	listConstIterator tmp(*this);
// 		// 	operator++();
// 		// 	return (tmp);
// 		// }

// 		// listConstIterator &
// 		// operator--()
// 		// {
// 		// 	m_node = m_node->previous();
// 		// 	return (*this);
// 		// }

// 		// listConstIterator
// 		// operator--(int)
// 		// {
// 		// 	listConstIterator tmp(*this);
// 		// 	operator--();
// 		// 	return (tmp);
// 		// }

// 		// bool
// 		// operator==(const listConstIterator &other) const
// 		// {
// 		// 	return (m_node == other.m_node);
// 		// }

// 		// bool
// 		// operator!=(const listConstIterator &other) const
// 		// {
// 		// 	return (m_node != other.m_node);
// 		// }

// 		// reference
// 		// operator*() const
// 		// {
// 		// 	return (m_node->value());
// 		// 	//eturn (static_cast<const Node*>(m_node)->value());
// 		// }

// 		// const Node *
// 		// node() const
// 		// {
// 		// 	return (m_node);
// 		// }
// 	};

// 	template <class Iterator>
// 		struct iterator_traits
// 		{
// 			typedef typename Iterator::difference_type difference_type;
// 			typedef typename Iterator::value_type value_type;
// 			typedef typename Iterator::pointer pointer;
// 			typedef typename Iterator::reference reference;
// 			typedef typename Iterator::iterator_category iterator_category;
// 		};
		
// 			// typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_type;
// 			// typedef typename ft::iterator_traits<Iterator>::value_type iterator_value;
// 			// typedef	typename ft::iterator_traits<Iterator>::difference_type difference_type;
// 			// typedef typename ft::iterator_traits<Iterator>::pointer pointer;
// 			// typedef typename ft::iterator_traits<Iterator>::reference reference;

// 		template <class T>
// 		class ReverseIterator
// 		{
// 			private:
// 				T *m_ptr;

// 			public:
// 				ReverseIterator() : 
// 					m_ptr(NULL)
// 				{
// 				}

// 				ReverseIterator(T* ptr):
// 					m_ptr(ptr)
// 				{
// 				}
				
// 				ReverseIterator(const T* ptr) :
// 					m_ptr(ptr)
// 				{
// 				}
				
// 				ReverseIterator(const ReverseIterator& other) : 
// 					m_ptr(other.m_ptr)
// 				{
// 				}
				
// 				ReverseIterator
// 				operator=(const ReverseIterator &other)
// 				{
// 					m_ptr = other.m_ptr;
// 					return (*this);
// 				}
			
// 				ReverseIterator
// 				operator++()
// 				{
// 					m_ptr--;
// 					return (*this);
// 				}

// 				ReverseIterator
// 				operator++(int)
// 				{
// 					ReverseIterator tmp(*this);
// 					operator++();
// 					return (tmp);
// 				}

// 				ReverseIterator &
// 				operator--()
// 				{
// 					m_ptr++;
// 					return (*this);
// 				}

// 				ReverseIterator
// 				operator--(int)
// 				{
// 					ReverseIterator tmp(*this);
// 					operator--();
// 					return (tmp);
// 				}

// 				bool
// 				operator==(const ReverseIterator &other) const
// 				{
// 					return (m_ptr == other.m_ptr);
// 				}

// 				bool
// 				operator!=(const ReverseIterator &other) const
// 				{
// 					return (m_ptr != other.m_ptr);
// 				}

// 				T&
// 				operator*()
// 				{
// 					return (*m_ptr);
// 				}

// 				T*
// 				value()
// 				{
// 					return (m_ptr);
// 				}
// 		};

// 		template <class T>
// 		class ConstReverseIterator
// 		{
		
// 			private:
// 				T* m_ptr;

// 			public:
// 				ConstReverseIterator() : 
// 					m_ptr(NULL)
// 				{
// 				}

// 				ConstReverseIterator(T *ptr) :
// 					m_ptr(ptr)
// 				{
// 				}

// 				ConstReverseIterator(const T* ptr) : m_ptr(ptr)
// 				{
// 				}

// 				ConstReverseIterator(const ConstReverseIterator &other) :
// 					m_ptr(other.m_ptr)
// 				{
// 				}

// 				ConstReverseIterator
// 				operator=(const ConstReverseIterator &other)
// 				{
// 					m_ptr = other.m_ptr;
// 					return (*this);
// 				}

// 				ConstReverseIterator
// 				operator++()
// 				{
// 					m_ptr--;
// 				}

// 				ConstReverseIterator
// 				operator++(int)
// 				{
// 					ConstReverseIterator tmp(*this);
// 					operator++();
// 					return (tmp);
// 				}

// 				ConstReverseIterator &
// 				operator--()
// 				{
// 					m_ptr--;
// 					return (*this);
// 				}

// 				ConstReverseIterator
// 				operator--(int)
// 				{
// 					ConstReverseIterator tmp(*this);
// 					operator--();
// 					return (tmp);
// 				}

// 				bool
// 				operator==(const ConstReverseIterator &other) const
// 				{
// 					return (m_ptr == other.m_ptr);
// 				}

// 				bool
// 				operator!=(const ConstReverseIterator &other) const
// 				{
// 					return (m_ptr != other.m_ptr);
// 				}

// 				T&
// 				operator*() const
// 				{
// 					return (*m_ptr);
// 					//return (static_cast<const Node*>(m_node)->value());
// 				}

// 				T *
// 				value() const
// 				{
// 					return (m_ptr);
// 				}
// 			};


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