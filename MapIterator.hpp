/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:38:21 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/02 11:14:09 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MapIterator_HPP
# define MapIterator_HPP



namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct MapIterator
	{
		typedef T         value_type; //Type of elements pointed by the MapIterator.

		typedef Distance  difference_type; //Type to represent the difference between two MapIterators.
		typedef Pointer   pointer;//Type to represent a pointer to an element pointed by the MapIterator.
		typedef Reference reference;//Type to represent a reference to an element pointed by the MapIterator.
		typedef Category  MapIterator_category;//Category to which the MapIterator belongs to
	};

	struct input_MapIterator_tag {};
	struct output_MapIterator_tag {};
	struct forward_MapIterator_tag {};
	struct bidirectional_MapIterator_tag {};
	struct random_access_MapIterator_tag {};
	
	

	template<class T>
	class MapIterator //: public ft::MapIterator<ft::input_MapIterator_tag, T>
	{
		private:
			T *m_ptr;
			
		public:
			MapIterator() : 
				m_ptr(NULL)
			{
			}

			MapIterator(T* ptr):
				m_ptr(ptr)
			{
			}
			
			MapIterator(const T* ptr) :
				m_ptr(ptr)
			{
			}
			
			MapIterator(const MapIterator& other) : 
				m_ptr(other.m_ptr)
			{
			}
  			
			MapIterator
			operator=(const MapIterator &other)
			{
				m_ptr = other.m_ptr;
				return (*this);
			}
			
			MapIterator& 
			operator++()
			{
				m_ptr++;
				return (*this);
			}
			
  			MapIterator
			operator++(T) // ou int?
			{
				MapIterator tmp(*this);
				operator++();
				return (tmp);
			}
			
			MapIterator& 
			operator--()
			{
				m_ptr--;
				return (*this);
			}
			
  			MapIterator
			operator--(T) // ou int?
			{
				MapIterator tmp(*this);
				operator--();
				return (tmp);
			}
			
  			bool
			operator==(const MapIterator& other) const
			{
				return (m_ptr == other.m_ptr);
			}
			
  			bool
			operator!=(const MapIterator& other) const
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
	class ConstMapIterator
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
			ConstMapIterator() : 
				m_ptr(NULL)
			{
			}

			ConstMapIterator(T* ptr):
				m_ptr(ptr)
			{
			}
			
			ConstMapIterator(const T* ptr) :
				m_ptr(ptr)
			{
			}
			
			ConstMapIterator(const ConstMapIterator& other) : 
				m_ptr(other.m_ptr)
			{
			}
  			
			ConstMapIterator
			operator=(const ConstMapIterator &other)
			{
				// m_ptr = other.m_ptr;
				return (*this);
			}
			
			ConstMapIterator& 
			operator++()
			{
				m_ptr++;
				return (*this);
			}
			
  			ConstMapIterator
			operator++(T) // ou int?
			{
				ConstMapIterator tmp(*this);
				operator++();
				return (tmp);
			}
			
			ConstMapIterator& 
			operator--()
			{
				m_ptr--;
				return (*this);
			}
			
  			ConstMapIterator
			operator--(T) // ou int?
			{
				ConstMapIterator tmp(*this);
				operator--();
				return (tmp);
			}
			
  			bool
			operator==(const ConstMapIterator& other) const
			{
				std::cout << "ICI\n";
				return (m_ptr == other.m_ptr);
			}
			
  			bool
			operator!=(const ConstMapIterator& other) const
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
	
		// listConstMapIterator() : m_node(NULL)
		// {
		// }

		// listConstMapIterator(Node *node) : m_node(node)
		// {
		// }

		// listConstMapIterator(const Node *node) : m_node(node)
		// {
		// }

		// listConstMapIterator(const listConstMapIterator &other) : m_node(other.m_node)
		// {
		// }

		// listConstMapIterator
		// operator=(const listConstMapIterator &other)
		// {
		// 	m_node = other.m_node;
		// 	return (*this);
		// }

		// listConstMapIterator
		// operator++()
		// {
		// 	m_node = m_node->next();
		// 	return (*this);
		// }

		// listConstMapIterator
		// operator++(int)
		// {
		// 	listConstMapIterator tmp(*this);
		// 	operator++();
		// 	return (tmp);
		// }

		// listConstMapIterator &
		// operator--()
		// {
		// 	m_node = m_node->previous();
		// 	return (*this);
		// }

		// listConstMapIterator
		// operator--(int)
		// {
		// 	listConstMapIterator tmp(*this);
		// 	operator--();
		// 	return (tmp);
		// }

		// bool
		// operator==(const listConstMapIterator &other) const
		// {
		// 	return (m_node == other.m_node);
		// }

		// bool
		// operator!=(const listConstMapIterator &other) const
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

	template <class MapIterator>
		struct MapIterator_traits
		{
			typedef typename MapIterator::difference_type difference_type;
			typedef typename MapIterator::value_type value_type;
			typedef typename MapIterator::pointer pointer;
			typedef typename MapIterator::reference reference;
			typedef typename MapIterator::MapIterator_category MapIterator_category;
		};
		
			// typedef typename ft::MapIterator_traits<MapIterator>::MapIterator_category MapIterator_type;
			// typedef typename ft::MapIterator_traits<MapIterator>::value_type MapIterator_value;
			// typedef	typename ft::MapIterator_traits<MapIterator>::difference_type difference_type;
			// typedef typename ft::MapIterator_traits<MapIterator>::pointer pointer;
			// typedef typename ft::MapIterator_traits<MapIterator>::reference reference;

		template <class T>
		class ReverseMapIterator
		{
			private:
				T *m_ptr;

			public:
				ReverseMapIterator() : 
					m_ptr(NULL)
				{
				}

				ReverseMapIterator(T* ptr):
					m_ptr(ptr)
				{
				}
				
				ReverseMapIterator(const T* ptr) :
					m_ptr(ptr)
				{
				}
				
				ReverseMapIterator(const ReverseMapIterator& other) : 
					m_ptr(other.m_ptr)
				{
				}
				
				ReverseMapIterator
				operator=(const ReverseMapIterator &other)
				{
					m_ptr = other.m_ptr;
					return (*this);
				}
			
				ReverseMapIterator
				operator++()
				{
					m_ptr--;
					return (*this);
				}

				ReverseMapIterator
				operator++(int)
				{
					ReverseMapIterator tmp(*this);
					operator++();
					return (tmp);
				}

				ReverseMapIterator &
				operator--()
				{
					m_ptr++;
					return (*this);
				}

				ReverseMapIterator
				operator--(int)
				{
					ReverseMapIterator tmp(*this);
					operator--();
					return (tmp);
				}

				bool
				operator==(const ReverseMapIterator &other) const
				{
					return (m_ptr == other.m_ptr);
				}

				bool
				operator!=(const ReverseMapIterator &other) const
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
		class ConstReverseMapIterator
		{
		
			private:
				T* m_ptr;

			public:
				ConstReverseMapIterator() : 
					m_ptr(NULL)
				{
				}

				ConstReverseMapIterator(T *ptr) :
					m_ptr(ptr)
				{
				}

				ConstReverseMapIterator(const T* ptr) : m_ptr(ptr)
				{
				}

				ConstReverseMapIterator(const ConstReverseMapIterator &other) :
					m_ptr(other.m_ptr)
				{
				}

				ConstReverseMapIterator
				operator=(const ConstReverseMapIterator &other)
				{
					m_ptr = other.m_ptr;
					return (*this);
				}

				ConstReverseMapIterator
				operator++()
				{
					m_ptr--;
				}

				ConstReverseMapIterator
				operator++(int)
				{
					ConstReverseMapIterator tmp(*this);
					operator++();
					return (tmp);
				}

				ConstReverseMapIterator &
				operator--()
				{
					m_ptr--;
					return (*this);
				}

				ConstReverseMapIterator
				operator--(int)
				{
					ConstReverseMapIterator tmp(*this);
					operator--();
					return (tmp);
				}

				bool
				operator==(const ConstReverseMapIterator &other) const
				{
					return (m_ptr == other.m_ptr);
				}

				bool
				operator!=(const ConstReverseMapIterator &other) const
				{
					return (m_ptr != other.m_ptr);
				}

				T&
				operator*() const
				{
					return (*m_ptr);
					//return (static_cast<const Node*>(m_node)->value());
				}

				T *
				value() const
				{
					return (m_ptr);
				}
			};


}
#endif
// template<class Iter>
// class ReverseMapIterator : public Iter
// {
// 	typedef typename Iter::value_type value_type;
// 	typedef typename Iter::pointer pointer;
// 	typedef typename Iter::const_pointer const_pointer;
// 	typedef typename Iter::reference reference;
// 	typedef typename Iter::const_reference const_reference;
// }