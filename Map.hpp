/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:45:55 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/12 15:55:27 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <iostream>
#include <exception>
#include "ReverseIterator.hpp"

/*https://www.geeksforgeeks.org/deletion-binary-tree/*/

namespace ft
{
	template< class T1, class T2>
	struct pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
		
			T1 first;
			T2 second;

		public:
			pair() : first(), second()
			{
			}

			pair(const T1& x,const T2& y) :first(x), second(y)
			{
			}

			template< class U1, class U2 >
			pair(const pair<U1, U2>& p ) : first(p.first), second(p.second)
			{
				
			}
			
			~pair()
			{	
			}
			
			pair& operator=(const pair& other)
			{
				if (this != &other)
				{
					first = other.first;
					second = other.second;
				}
				return (*this);
			}

			T1 & key()
			{
				return (first);
			}
		
			const T1 & key() const
			{
				return (first);
			}
			
			T2&
			value()
			{
				return (second);
			}

			const T2&
			value() const
			{
				return (second);
			}
			
	};

	template<class T1, class T2>
	pair<T1,T2> make_pair(T1 t, T2 u)
	{
		return (pair<T1, T2>(t, u));
	}
	
	template <class T>
	struct less : std::binary_function <T,T,bool> // binary function to implement
	{
		bool operator() (const T& x, const T& y) const 
		{
			//std::cout << "less\n";
		//std::cout << "x: " << x << " - y: "<< y << std::endl;
			return (x < y);
		}
	};
	
	template< class Key, class T > class MapNode
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const Key, T> value_type;
			// typedef size_t size_type;
			// typedef ptrdiff_t difference_type;
			// typedef Compare key_compare;
		//	typedef Allocator allocator_t;

		private:
		//	allocator_t m_allocator;
			MapNode *m_parent;
			MapNode *m_left;
			MapNode *m_right;
			value_type m_pair;
			int m_color;
			

		public:
			// MapNode(const allocator_t &alloc = allocator_t()) : m_allocator(alloc)
			// {
			// }
			MapNode() : m_pair(value_type())
			{
			}
		
			MapNode(pair<const Key, T> p) : m_pair(p)
			{
			}
			
			MapNode(const MapNode &other) :
				m_parent(other.m_parent),
				m_left(other.m_left),
				m_right(other.m_right),
				m_pair(other.m_pair)
				
			{
			}
			
			~MapNode()
			{
			}
			
			MapNode* left()
			{
				return (m_left);
			}

			MapNode* right()
			{
				return (m_right);
			}
			
			void left(MapNode* l)
			{
				if (this != l)
					m_left = l;
			}

			void right(MapNode* r)
			{
				m_right = r;
			}
			
			value_type& getPair()
			{
				return (m_pair);
			}

			const Key& key() const
			{
				return (m_pair.key());
			}

			T& value()
			{
				return (m_pair.value());
			}

			bool
			isLeaf(MapNode* end)
			{
				return (m_left == NULL && (m_right == NULL || m_right == end));
			}

			bool
			hasRight()
			{
				return (m_right != NULL);
			}

			bool
			hasLeft()
			{
				return (m_left != NULL);
			}

			MapNode*
			parent()
			{
				return (m_parent);
			}

			bool
			hasOneChild()
			{
				return ((m_left && !m_right) || (!m_left && m_right));
			}

			int
			onlyChild()
			{
				if (m_left)
					return(0);
				else
					return(1);
			}

			int
			identifyParentSide()
			{
				if (this == m_parent->left())
					return(0);
				else
					return(1);
			}

			void
			parent(MapNode *node)
			{
				m_parent = node;	
			}

			int
			identifyParentSize()
			{
				if (this == parent()->left())
					return (0);
				else
					return (1);
			}

			
	};

	template <class Key, class T>
	class MapIterator
	{
	public:
		typedef pair<Key, T> value_type;
		typedef pair<const Key, T> const_value_type;
		typedef value_type* pointer;
		typedef const_value_type* const_pointer;
        //typedef const value_type* const_pointer;
		typedef value_type &reference;

	// protected:
	// 	typedef MapNode<Key, T> MapNode;

	protected:
		MapNode<Key, T> *m_node;

	public:
		MapIterator() : m_node(NULL)
		{
		}

		MapIterator(MapNode<Key, T> *node) : m_node(node)
		{
		}

		MapIterator(const MapNode<Key, T> *node) : m_node(node)
		{
		}

		MapIterator(const MapIterator &other) : m_node(other.m_node)
		{
		}

		~MapIterator()
		{
		}

		MapIterator
		operator=(const MapIterator &other)
		{
			m_node = other.m_node;
			return (*this);
		}

		MapIterator
		operator++()
		{
			MapNode<Key, T> *tmp;
		//	std::cout<< "NOde: " << m_node->value() << std::endl;
			if (m_node->hasRight())
			{
				m_node = identifyDeepestLeft(m_node->right());
			//	std::cout << "node" << m_node << std::endl;
				// if (m_node != NULL && m_node->hasRight())
				// {
				// 	std::cout << "inside\n";
				// 	m_node = m_node->right();
				// }
			}
			else
			{
			//	std::cout << "parent: " << m_node->parent();
				if (m_node == m_node->parent()->left())
					m_node = m_node->parent();
				else
				{
					tmp = m_node->parent();
					m_node = tmp->parent();
					if (tmp == m_node->right())
					{
						while (m_node == m_node->parent()->right())
							m_node = m_node->parent();
						m_node = m_node->parent();
					}	
				}
			}
			return (*this);
		}

		MapNode<Key, T>*
		identifyDeepestLeft(MapNode<Key, T>* node)
		{
		//	std::cout << "trouble node: " << node << " - " << node->hasLeft() << "\n" << std::flush;
			MapNode<Key, T>* tmp = node;
			while (tmp->hasLeft())
				tmp = tmp->left();
			return(tmp);
		}
		
		MapNode<Key, T>*
		identifyDeepestRight(MapNode<Key, T>* node)
		{
		//	std::cout << "trouble node: " << node << " - " << node->hasLeft() << "\n" << std::flush;
			MapNode<Key, T>* tmp = node;
			while (tmp->hasRight())
				tmp = tmp->right();
			return(tmp);
		}
		
		MapIterator
		operator++(int)
		{
			MapIterator tmp(*this);
			operator++();
			return (tmp);
		}

		MapIterator &
		operator--()
		{
			// if (m_node->hasLeft())
			// 	m_node = m_node->left();
			// else
			// {
			// 	if (m_node == m_node->parent()->right())
			// 		m_node = m_node->parent();
			// 	else
			// 	{
			// 		while (m_node == m_node->parent()->left())
			// 			m_node = m_node->parent();		
			// 	}
			// }

			MapNode<Key, T> *tmp;
			if (m_node->hasLeft())
			{
			//	std::cout << "ICI\n" << std::flush;
				m_node = identifyDeepestRight(m_node->left());
				// if (m_node == NULL && m_node->hasRight())
				// 	m_node = m_node->right();
			}
			else
			{
				if (m_node == m_node->parent()->right())
				{
						// std::cout << "LA\n" << std::flush;
					m_node = m_node->parent();
				}
				else
				{
						// std::cout << "HELLO\n" << std::flush;
					tmp = m_node->parent();
					m_node = tmp->parent();
					if (tmp == m_node->left())
					{
						while (m_node == m_node->parent()->left())
							m_node = m_node->parent();
						m_node = m_node->parent();
					}	
				}
			}
			
			return (*this);
		}

		MapIterator
		operator--(int)
		{
				// std::cout << "ICIIIIII\n" << std::flush;
			MapIterator tmp(*this);
			operator--();
			return (tmp);
		}

		bool
		operator==(const MapIterator &other) const
		{
			return (m_node == other.m_node);
		}

		bool
		operator!=(const MapIterator &other) const
		{
			return (m_node != other.m_node);
		}

		pair<const Key, T>&
		operator*()
		{
			// std::cout << "address:" << m_node << std::endl;
			// std::cout << "value: " << m_node->value() << std::endl;
			return (m_node->getPair());
		}

		pair<const Key, T>*
		operator->() const
		{
			return(&(m_node->getPair()));
		}

		MapNode<Key, T> *node() const
		{
			return (m_node);
		}

		MapIterator
		base() const
		{
			return(*this);
		}
		// friend bool operator== (const MapIterator<Key, T>& lhs,
		// const MapIterator<Key, T>& rhs);
	};


	template <class Key, class T>
	bool operator== (const MapIterator<Key, T>& lhs,
	const MapIterator<Key, T>& rhs)
	{
		// ft::map<Key, T>::MapIterator<Key, T>::key_compare l_key_comp = lhs.key_comp();
	//typename ft::map<Key, T>::key_compare r_key_comp = rhs.key_comp();
        if (lhs->first == rhs->first && lhs->second== rhs->second)
			return(true);
		else
			return(false);
    }

	template <class Key, class T>
	bool operator!= (const MapIterator<Key, T>& lhs,
	const MapIterator<Key, T>& rhs)
	{
		return(!(lhs == rhs));
    }

	template <class Key, class T>
	bool operator< (const MapIterator<Key, T>& lhs,
	const MapIterator<Key, T>& rhs)
	{
		return(lhs->first < rhs->first);
	}

	template <class Key, class T>
	bool operator<= (const MapIterator<Key, T>& lhs,
	const MapIterator<Key, T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T>
	bool operator> (const MapIterator<Key, T>& lhs,
	const MapIterator<Key, T>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T>
	bool operator>= (const MapIterator<Key, T>& lhs,
	const MapIterator<Key, T>& rhs)
	{
		return (!(lhs < rhs));
	}
		
	template <class Key, class T>
	class ConstMapIterator
	{
	public:
		typedef const pair<Key, T> value_type;
		typedef const value_type &reference;
		typedef const value_type& const_reference;

	// private:
	// 	typedef MapNode<Key, T><Key, T><Key, T> MapNode<Key, T>;

	private:
		MapNode<Key, T> *m_node;

	public:
		ConstMapIterator() : m_node(NULL)
		{
		}

		ConstMapIterator(MapNode<Key, T> *node) : m_node(node)
		{
		}

		ConstMapIterator(const MapNode<Key, T> *node) : m_node(node)
		{
		}

		ConstMapIterator(const ConstMapIterator &other) : m_node(other.m_node)
		{
		}

		~ConstMapIterator()
		{
		}
		
		ConstMapIterator
		operator=(const ConstMapIterator &other)
		{
			m_node = other.m_node;
			return (*this);
		}

		ConstMapIterator
		operator++()
		{
		//	std::cout << "ici\n";
			MapNode<Key, T> *tmp;
			if (m_node->hasRight())
			{
				m_node = identifyDeepestLeft(m_node->right());
				if (m_node != NULL && m_node->hasRight())
					m_node = m_node->right();
			}
			else
			{
				if (m_node == m_node->parent()->left())
					m_node = m_node->parent();
				else
				{
					tmp = m_node->parent();
					m_node = tmp->parent();
					if (tmp == m_node->right())
					{
						while (m_node == m_node->parent()->right())
							m_node = m_node->parent();
						m_node = m_node->parent();
					}	
				}
			}
			return (*this);
		}

		MapNode<Key, T>*
		identifyDeepestLeft(MapNode<Key, T>* node)
		{
		//	std::cout << "trouble node: " << node << " - " << node->hasLeft() << "\n" << std::flush;
			MapNode<Key, T>* tmp = node;
			while (tmp->hasLeft())
				tmp = tmp->left();
			return(tmp);
		}
		
		ConstMapIterator
		operator++(int)
		{
			ConstMapIterator tmp(*this);
			operator++();
			return (tmp);
		}

		ConstMapIterator &
		operator--()
		{
			if (m_node->hasLeft())
				m_node = m_node->left();
			else
			{
				if (m_node == m_node->parent()->right())
					m_node = m_node->parent();
				else
				{
					while (m_node == m_node->parent()->left())
						m_node = m_node->parent();
					m_node = m_node->parent();
				}
			}
			return (*this);
		}

		ConstMapIterator
		operator--(int)
		{
			ConstMapIterator tmp(*this);
			operator--();
			return (tmp);
		}

		bool
		operator==(const ConstMapIterator &other) const
		{
			return (m_node == other.m_node);
		}

		bool
		operator!=(const ConstMapIterator &other) const
		{
			return (m_node != other.m_node);
		}

		const value_type
		operator*() const
		{
			// std::cout << "address:" << m_node << std::endl;
			// std::cout << "value: " << m_node->value() << std::endl;
			return (m_node->getPair());
		}

		pair<const Key, T>*
		operator->() const
		{
			return(&(m_node->getPair()));
		}

		const MapNode<Key, T> *node() const
		{
			return (m_node);
		}
	};



	template< typename Key, typename T, typename Compare = ft::less<Key>, typename Allocator = std::allocator<ft::MapNode<Key, T> > >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<Key, T> value_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Allocator allocator_t;
			typedef typename allocator_t::reference reference;
			typedef typename allocator_t::const_reference const_reference;
			typedef typename allocator_t::pointer pointer;
			typedef typename allocator_t::const_pointer const_pointer;
			typedef MapIterator<Key, T> iterator;
			typedef ConstMapIterator<Key, T> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;

		private:
			typedef typename ft::MapNode<Key, T> MapNode;
		
		public:
			class value_compare
			{
				public:
				value_compare (Compare c) : m_comp(c) {}
					typedef bool result_type;
  					typedef value_type first_argument_type;
  					typedef value_type second_argument_type;
  					bool operator() (const value_type& x, const value_type& y) const
  					{
    					return m_comp(x.first, y.first);
  					}
					
				protected:
					Compare m_comp;
					
			};

		private:
			allocator_t m_allocator;
			key_compare m_comp;
			MapNode* m_root;
			MapNode *m_first;
			MapNode *m_end;
			int m_size;

		public:
				explicit map (const key_compare& comp = key_compare(),
					const allocator_t& alloc = allocator_t()) :
						m_allocator(alloc),
						m_comp(comp),
						m_root(NULL),
						m_first(NULL),
						m_end(NULL),
						m_size(0)
				{
				//	std::cout << "ICI\n";
					createEndNode();
					// m_end = m_allocator.allocate(1);
					// m_allocator.construct(m_end, MapNode());
					// m_end->left(NULL);
					// m_end->right(NULL);
					// m_first = m_end;
				}
				
				template <class InputMapIterator>
				map (InputMapIterator first, InputMapIterator last,
				const key_compare& comp = key_compare(),
				const allocator_t& alloc = allocator_t()) :
					m_allocator(alloc),
					m_comp(comp),
					m_root(NULL),
					m_size(0)
				{
					createEndNode();
					m_first = m_root = createNode(first.node()->getPair());
					connection(m_root, 1, m_end);
					iterator tmp = first;
					if (first != last)
						tmp++;
					while (tmp != last)
					{
						insert(*tmp);
						tmp++;
					}
					
				}
				
				map (const map& x) : 
					m_allocator(x.m_allocator),
					m_comp(x.m_comp),
					m_root(NULL),
					m_first(NULL),
					m_size(x.m_size)
				{
					createEndNode();
					const MapNode *e = x.end().node();
					m_root = createNode((x.m_root)->getPair());
					//std::cout << "Root: " << m_root << " - " <<  m_root->key() << std::endl;
				//	std::cout <<  "source left: " <<x.m_root->left()->left() << std::endl;
					copyNodes(m_root, x.m_root, e);
				//	std::cout << "Left: " << m_root->left() << std::endl;
					m_first = identifyDeepestLeft(m_root->left());
					if(m_first == NULL) // CHECK ICI!!!!!
						m_first = m_root;
					iterator it = begin();
					iterator ite = end();
					// while(it != ite)
					// {
					// 	std::cout << it.node() << "\n" << std::flush;
					// 	it++;
					// }
			//		std::cout << "end: " << m_end->parent()->value()<< std::endl;
					
				}

				~map()
				{
					clear();
					destroyMapNode(m_end);
				}
				
				T& operator[](const Key& key)
				{
					iterator it = find(key);
					return((*it).value());
				}

				map&
				operator=(const map& other)
				{
					clear();
					// createEndNode();
					MapNode* root = other.m_root;
					// std::cout << "ROOT:" << root << std::endl;
					// std::cout << "ROOT:" << root->key() << std::endl;
					m_root = createNode(root->getPair());
					copyNodes(m_root, other.m_root, other.end().node());
					m_first = identifyDeepestLeft(m_root->left());
					if (m_first == NULL)
						m_first = m_root;
					// std::cout << "root left: " << m_root->left() << std::endl;
					// std::cout << "end: " <<  m_end << std::endl;
					return(*this);
				}

				// MapNode*
				// root()
				// {
				// 	return(m_root);
				// }
				
				iterator begin()
				{
					return(iterator(m_first));
				}

				const_iterator begin() const
				{
					return (const_iterator(m_first));
				}

				iterator end()
				{
					return(iterator(m_end));
				}

				const_iterator end() const
				{
					return (const_iterator(m_end));
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
				
				bool empty() const
				{
					// std::cout << "EMPTY\n";
					// std::cout << "size: " << m_size << std::endl;
					// std::cout << "root: " << m_root << std::endl;
					// std::cout << "first: " << m_first << std::endl;
					// std::cout << "end: " << m_end << std::endl;
					return (m_size == 0);
				}

				size_type size() const
				{
					return (m_size);
				}
				
				size_type max_size() const
				{
					return (std::numeric_limits<size_type>::max() / sizeof(MapNode)); // not sure...
				}
	
				/*MODIFIERS*/
				
				pair<iterator,bool>
				insert (const value_type& val)
				{
					pair<iterator,bool> ret;
										
					MapNode* tmp = createNode(val);
					MapNode* root_copy = m_root;
					ret = search_insert(0, 0, root_copy, tmp);
					if (ret.value() && !m_root)
					{
						iterator it = ret.key();
						m_root = it.node();
					//	std::cout << m_root->value() << std::endl;
					}
					return(setLimitsPair(ret));
				}
				
				iterator
				insert (iterator position, const value_type& val)
				{
					(void)position;
					return((insert(val)).first);
				}
				
				template <class InputIterator>
				void insert (InputIterator first, InputIterator last,
				typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
				{
					iterator f = first;
					iterator l = last;
					
					for (; f!= l ; f++)
						insert(*f);
				}
				
				void erase (iterator position)
				{
					//std::cout << "erase" << position->first << " - " << m_root->value() << std::endl;
					MapNode *substitute = NULL;
					
					if (position.node() == m_root)
					{
						// std::cout << "ROOT\n";
						if (m_root->isLeaf(m_end))
						{
							newRoot(substitute, position);
							m_first = m_root = m_end ;
						}
						else if (m_root->hasOneChild())
						{
							substitute = identifyTheChild(m_root);
							// std::cout << "HHHHEEERRRE\n";
							// if (substitute == m_end)
							// 	std::cout << "EENNNDD\n";
							newRoot(substitute, position);
							setLimits();
						}
						else
						{
							int side = highestHigh(m_root);
							substitute = identifyTheDeepestChild(side, position.node());
							cutTheApronStrings(substitute);
							newRoot(substitute, position);
							setLimits();
						}
					}
					else
					{
						if (position.node()->isLeaf(m_end))
						{
							// std::cout << "LEAF\n";
							// std::cout << "First: " << position->first<< std::endl;
							// std::cout << "Right: " << position.node()->right()<< std::endl;
							if (position.node()->identifyParentSide() == 0)
								position.node()->parent()->left(NULL);
							else
								position.node()->parent()->right(NULL);
							// destroyMapNode(position);
							// setLimits();
							// m_size--;
						}
						if (position.node()->hasOneChild())
						{
							// std::cout << "ONE CHILD\n";
							substitute = identifyTheChild(position.node());
							adoption(substitute, position.node());
							// destroyMapNode(position);
							// m_size--;
						}
						else if (!(position.node()->isLeaf(m_end)))
						{
							// std::cout << "TWO CHILDREN\n";
							// std::cout << "position:" << position->first << std::endl;
							int side = position.node()->identifyParentSize();
							substitute = identifyTheDeepestChild(side, position.node());
							// std::cout << "substitute: " << substitute->value() << std::endl;
							// std::cout << "new right: " << substitute->right()->value() << std::endl;
							cutTheApronStrings(substitute);
							// std::cout << "new right2: " << substitute->right()->value() << std::endl;
							adoption(substitute, position.node());
							// std::cout << "new right3: " << substitute->right()->value() << std::endl;
							// destroyMapNode(position);
							// m_size--;
						}
						// std::cout << "sub: " << substitute << std::endl;
						destroyMapNode(position);
					//	std::cout << "new right2: " << substitute->right()->value() << std::endl;
						setLimits();
					//	std::cout << "new right3: " << substitute->right()->value() << std::endl;
						m_size--;
					}
				//	m_root = m_first = m_end;
					// std::cout << "First: " << m_first << std::endl;
					// std::cout << "Root: " << m_root << std::endl;
					// std::cout << "End: " << m_end << std::endl;
					// std::cout << "Size: " << m_size << std::endl;
				}

				size_type
				erase(const key_type& k)
				{
					size_type size = 0;
					iterator found = find(k).node();
					// std::cout << "Found: " << found->first << std::endl;
					while(found != m_end)
					{
							// std::cout << "Found: " << found->first << std::endl;
						erase(found);
						size++;
						found = find(k).node();
					}
					return (size);
				}

				
				void erase(iterator first, iterator last)
				{
					// int e = 0;
					// if (last == end())
					// 	e = 1;
			//		std::cout << "SIZE: " << m_size << std::endl;
					while (first != last)
					{
			//			 std::cout << "First: " <<first->first << "\n" << std::flush;
					// 	std::cout << "tmp: " << first.node() << "\n" << std::flush;
					// //std::cout << "right: " << first.node()->right() << "\n" << std::flush;
						iterator tmp = first;
						++first;
						// std::cout << "next: " << first.node() << "\n" << std::flush;
						erase(tmp);
					}
					// if (e)
					// 	m_end = last.node();
					// s
					// td::cout << "endddddddd: " << m_end << std::endl;
				}
				
				void swap(map &x)
				{
					MapNode* first_copy = m_first;
					MapNode* end_copy = m_end;
					MapNode* root_copy = m_root;
					size_t size_copy = m_size;
					
					m_first = x.m_first;
					m_end = x.m_end;
					m_size = x.m_size;
					m_root = x.m_root;
					
					x.m_first = first_copy;
					x.m_end = end_copy;
					x.m_size = size_copy;
					x.m_root = root_copy;
					
					// std::cout << "Roooooot: " << m_root << " - " <<  m_root->key() << std::endl;
					// std::cout <<  "source left: " <<m_root->right()->left()->value() << std::endl;
					// map copy(*this);
					// iterator it = copy.begin();
					// iterator ite = copy.end();
					// while(it != ite)
					// {
					// 	std::cout << "it  : " << it->first << "\n" << std::flush;
					// 	it++;
					// }
					// std::cout << "Size: " << copy.size() << " - " << "Begin: " << (copy.begin()).node() << "\n" << std::flush;
					// std::cout << "Size: " << m_size << " - " << "Begin: " << m_first << "\n" << std::flush;
					
				
					// *this = x;
					// x = copy;
					// iterator it = x.begin();
					// iterator ite = x.end();
					// while(it != ite)
					// {
					// 	std::cout << "it  : " << it->first << "\n" << std::flush;
					// 	it++;
					// }
					// m_size =4;
				//copy.clear();					
				}

				void clear()
				{
					iterator first = begin();
				//	std::cout << "first: " << m_first << std::endl;
					iterator last = end();
					erase(first, last);
					//std::cout << "end CLER: " << m_end << std::endl;
				}

				/*OBSERVERS*/
				
				key_compare key_comp() const
				{
					return(m_comp);
				}
				
				value_compare value_comp() const
				{
					return(value_compare(m_comp));
				}
				
				/*OPERATION*/
				
				iterator find(const key_type &k)
				{
					MapNode* found;
					found = m_root;
				///	std::cout << "k = " << k << "/"  << found->key() << "\n" << std::flush;
					while(found && found != m_end && !(!m_comp(found->key(), k) && !m_comp(k, found->key())))
					{
				//		std::cout << "k = " << k << "/"  << found->key() << "\n" << std::flush;
						if (m_comp(k, found->key()))
							found = found->left();
						else if (m_comp(found->key(), k))
							found = found->right();
					}
					if (found && !m_comp(found->key(), k) && !m_comp(k, found->key()))
						return(iterator(found));
					else
						return (end());
				}

				const_iterator find(const key_type &k) const
				{
					MapNode* found;
					found = m_root;
				//	std::cout << "k = " << k << "/"  << found->key() << "\n" << std::flush;
					while(found && found != m_end && !(!m_comp(found->key(), k) && !m_comp(k, found->key())))
					{
					//	std::cout << "k = " << k << "/"  << found->key() << "\n" << std::flush;
						if (m_comp(k, found->key()))
						{
						//	std::cout << "k = " << k << " / inferieur a found:"  << found->key() << "\n" << std::flush;
							found = found->left();
						}
						else if (m_comp(found->key(), k))
						{
						//	std::cout << "found = " << k << " / inferieur a k:"  << found->key() << "\n" << std::flush;
							found = found->right();
						}
					}
					if (found&& !m_comp(found->key(), k) && !m_comp(k, found->key()))
						return(const_iterator(found));
					else
						return (const_iterator(end()));
				}
				
				size_type count (const key_type& k) const
				{
					size_type size = 0;
					// const_iterator found;
					// found = find(k);
					// std::cout << "Found: " << found->first << std::endl;
					// while(1)
					// {
					// 	found = find(k);
					// 	size++;
					// 	std::cout << "size: " << size << std::endl;
					// 	if (found.node() == m_end)
					// 		break;
					// }
					// return (size);

				// 	MapNode* found;
				// 	found = m_root;
				// ///	std::cout << "k = " << k << "/"  << found->key() << "\n" << std::flush;
				// 	while(found && found != m_end && !(!m_comp(found->key(), k) && !m_comp(k, found->key())))
				// 	{
				// //		std::cout << "k = " << k << "/"  << found->key() << "\n" << std::flush;
				// 		if (m_comp(k, found->key()))
				// 			found = found->left();
				// 		else if (m_comp(found->key(), k))
				// 			found = found->right();
				// 	}
				// 	if (found && !m_comp(found->key(), k) && !m_comp(k, found->key()))
				// 		return(iterator(found));
				// 	else
				// 		return (end());

					const_iterator f = begin();
					const_iterator l = end();
					// iterator ll = end();
					// l--;
					// l--;
					// ll--;
					// std::cout << l->first << std::endl;
						// std::cout << "end: " << end().node() << std::endl;
					while (f != l)
					{
						// std::cout << f->first << std::endl;
						if (!(m_comp(f->first, k)) && !(m_comp(k, f->first)))
							size++;
						f++;
						
					}
					return(size);
				}

				iterator lower_bound (const key_type& k)
				{
					iterator found = begin();
					iterator ite = end();
				
					while(key_comp()(found->first, k) && found != ite)
						found++;
					
					return(found);
				}
				
				const_iterator lower_bound (const key_type& k) const
				{
					const_iterator found = begin();
					const_iterator ite = end();
				
					while(key_comp()(found->first, k) && found != ite)
						found++;
					
					return(found);
				}
				
				iterator upper_bound (const key_type& k)
				{
					iterator found = begin();
					iterator ite = end();
				
					while(key_comp()(found->first, k) && found != ite)
						found++;
					if (found != ite && !(key_comp()(k, found->first)))
						found++;
					return(found);
				}

				const_iterator upper_bound (const key_type& k) const
				{
					const_iterator found = begin();
					const_iterator ite = end();
				
					while(key_comp()(found->first, k) && found != ite)
						found++;
					if (found != ite && !(key_comp()(k, found->first)))
						found++;
					return(found);
				}

				pair<const_iterator,const_iterator>
				equal_range (const key_type& k) const
				{
					const_iterator lower = lower_bound(k);
					const_iterator upper = upper_bound(k);
					return(make_pair(lower, upper));
				}
				
				pair<iterator,iterator>
				equal_range (const key_type& k)
				{
					iterator lower = lower_bound(k);
					iterator upper = upper_bound(k);
					return(make_pair(lower, upper));
				}
				
				// MapNode*
				// root() const
				// {
				// 	return (m_root);
				// }

			// friend bool operator== (const MapIterator<Key, T>& lhs,
			// const MapIterator<Key, T>& rhs);
			private:

				void
				createEndNode()
				{
					m_end = m_allocator.allocate(1);
					m_allocator.construct(m_end, MapNode());
					m_end->left(NULL);
					m_end->right(NULL);
					m_first = m_end;
				}
				
				MapNode*
				createNode(const value_type& val)
				{
					MapNode *node = NULL;
					node = m_allocator.allocate(1);
					m_allocator.construct(node, val);
					node->left(NULL);
					node->right(NULL);
					return(node);
				}
				
				pair<iterator,bool>
				setLimitsPair(pair<iterator,bool> p)
				{
					iterator it = p.key();
					MapNode *node = it.node();
					if (it.node() == m_root)
					{
						m_first = m_root;
					//	std::cout << "Ici: " << m_first->value() << "\n" << std::endl;
						m_root->right(m_end);
						m_end->parent(m_root);
					}
					else
					{
						if (node->parent() == m_first && node == m_first->left())
							m_first = node;
						if (node->parent() == m_end->parent() && node == node->parent()->right())
						{
							m_end->parent(node);
							node->right(m_end);
						}
					}
					iterator it_x = iterator(node);
				//	std::cout << "FFFFFIIIIRRRSSSTTT: " << m_first->value() << std::endl;
					return (make_pair<iterator, bool>(it_x, p.value()));
				}

				void
				setLimits()
				{
					// MapNode* first = NULL;
					MapNode* end = NULL;
					// std::cout << "Root: " << m_root << " - " << m_root->key() << std::endl;
					// 	std::cout << "End: " << m_end << std::endl;
					if (m_root != m_end)
					{
						if (m_root->hasLeft())
							m_first = identifyDeepestLeft(m_root->left());
						else
							m_first = m_root;
						if (m_root->hasRight() && m_root->right() != m_end)
						{
							end = identifyDeepestRight(m_root->right());
						//	std::cout << "end: " << end->value() << std::endl;
							connection(end, 1, m_end);
						}
						else
							connection(m_root, 1, m_end);
					}
					
				}
			
				pair<iterator,bool>
				search_insert(MapNode *parent, int side, MapNode *pos, MapNode *node)
				{
					// std::cout << "SEARCH\n";
					// std::cout << "Parent : "<< parent << std::endl;
					// if (pos)
					// 	std::cout << "Pos : "<< pos->value() << std::endl;
					// std::cout << "Pos : "<< node->value() << std::endl;
					// if (parent)
					// 	std::cout << "Parent value : "<< parent->value() << std:: endl;
					if (pos == NULL || pos == m_end)
					{
						// std::cout << "THE END\n";
						if (parent)
						{
							// std::cout << "Parent value : "<< parent->value() << std:: endl;
							node->parent(parent);
							if (side == 0)
								parent->left(node);
							else
								parent->right(node);
						}
						else
						{
							node->parent(NULL);
							m_root = m_first = node;
						}
						
						m_size++;
						iterator it = iterator(node);
						return (make_pair<iterator, bool>(it, true));
					}
					else
					{
						if (m_comp(node->key(), pos->key()))
							return(search_insert(pos, 0, pos->left(), node));
						else
							return(search_insert(pos, 1, pos->right(), node));
					}
				}

				void copyNodes(MapNode* parent, MapNode* source, const MapNode *end)
				{
				//	std::cout <<  "SOURCE: " << source->key() << std::endl;
			//		std::cout <<  "source right: " << source->right()->right << std::endl;
				//	std::cout <<  "source left: " << source->left()->left() << std::endl;
					MapNode* source2 = source;
					if(source)
					{
						// if (parent == NULL)
						// 	parent = source;
						if(source->hasLeft())
						{
							// std::cout << "LLLLLEEEFFFT\n" << std::flush;
							source = source->left();
							MapNode *node = createNode(source->getPair());
							connection(parent, 0, node);
							copyNodes(node, source, end);
							// std::cout << "SORTIE\n";
						}
						source = source2;
						// std::cout << "right:  " << source->right() << std::endl;
						if(source2->hasRight() && source2->right() != end)
						{
							// std::cout << "RRIRIIIGHT\n" << std::flush;
							source = source->right();
							MapNode *node = createNode(source->getPair());
							connection(parent, 1, node);
							copyNodes(node, source, end);
						}

						else if (source->hasRight() && source->right() == end)
							connection(parent, 1, m_end);
					}
					return;
				}

				void destroyMapNode(iterator pos)
				{
					m_allocator.destroy(pos.node());
					m_allocator.deallocate(pos.node(), 1);	
				}
				
				void adoption(MapNode *child, MapNode *node)
				{
					child->parent(node->parent());
					// std::cout << "child: " << child->value() << std::endl;
					// std::cout << "parent: " << child->parent() << std::endl;
					int parentSide = node->identifyParentSide();
					//std::cout << "parent Side : " << parentSide << std::endl;
					if (parentSide == 0)
						node->parent()->left(child);
					else
						node->parent()->right(child);
					// child->left(node->left());
					// child->right(node->right());
					//std::cout << "HERE\n" << std::flush;
				}

				void cutTheApronStrings(MapNode *child)
				{
					if (child->identifyParentSide() == 0)
						child->parent()->left(NULL);
					else
					{
						//std::cout << "all good\n";
						child->parent()->right(NULL);
					}
				}

				void newRoot(MapNode* substitute, iterator pos)
				{
				//	std::cout << "substitutde: " << substitute << std::endl;
					destroyMapNode(pos);
					m_root = substitute;
					m_size--;
				}

				MapNode*
				identifyTheChild(MapNode *node)
				{
					if (node->onlyChild() == 0)
						return(node->left());
					else
						return(node->right());
				}

				MapNode*
				identifyTheDeepestChild(int side, MapNode *node)
				{
					MapNode* child = NULL;
					//std::cout << " node : " << node->value() << std::endl;
					if (side == 1)
					{
						if(node->left()->hasRight() && node->left()->hasLeft())
							child = identifyDeepestLeft(node->left()->right());
						else
						{
							// if (node->left()->hasRight())
							// 	child = node->left()->right();
							// else if (node->left()->hasLeft())
							// 	child = node->left()->left();
							// else
								child = node->left();
						}		
						if (child->isLeaf(m_end))
						{
							std::cout << "leaf\n";
							connection(child, 1, node->right());
							if (child != node->left())
								connection(child, 0, node->left());
							else
								child->left(NULL);
						}
						else
						{
							connection(child, 0, child->right());
							connection(child, 1, node->right());
						}	
					}
					else
					{
						//child = identifyDeepestRight(node->right());
						if(node->right()->hasLeft() && node->right()->hasRight())
							child = identifyDeepestRight(node->right()->left());
						else
						{
							// if (node->right()->hasLeft())
							// 	child = node->right()->left();
							// else if (node->left()->hasLeft())
							// 	child = node->left()->left();
							// else
								child = node->right();
						}	
						if (child->isLeaf(m_end)) // complete for end
						{
							std::cout << "1\n";
							connection(child, 0, node->left());
							if (child != node->right())
								connection(child, 1, node->right());
							else
								child->right(NULL);
						}
						else
						{
							std::cout << "2\n";
							connection(child, 1, child->left());
							connection(child, 0, node->left());
						}
					}
					return(child);
				}

				MapNode*
				identifyDeepestLeft(MapNode* node)
				{
					// 
					
					MapNode* tmp = node;
					// std ::cout << tmp << "\n" << std::flush;
					if (tmp)
					{
						// std ::cout << tmp << "\n" << std::flush;
						//" - " << tmp->value() << "\n" << std::flush;
						while (tmp && tmp->hasLeft())
							tmp = tmp->left();
					}
				//	std ::cout << tmp << " - " << tmp->value() << "\n" << std::flush;
					return(tmp);
				}

				MapNode*
				identifyDeepestRight(MapNode* node)
				{
					MapNode* tmp = node;
					while (tmp->hasRight() && tmp->right() != m_end)
						tmp = tmp->right();
					return(tmp);
				}

				int
				highestHigh(MapNode *node)
				{
					if (maxDepth(node->left()) > maxDepth(node->right()))
						return(0);
					else
						return(1);
				}

				
				/*https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/*/
				int maxDepth(MapNode *node) 
				{
					if (node == NULL)
						return (-1);
					else
					{
						/* compute the depth of each subtree */
						int lDepth = maxDepth(node->left());
						int rDepth = maxDepth(node->right());
			
						/* use the larger one */
						if (lDepth > rDepth)
							return (lDepth + 1);
						else
							return (rDepth + 1);
					}
				}

				void connection(MapNode* parent, int side, MapNode *child)
				{
					if (side == 0)
						parent->left(child);
					else
						parent->right(child);
					
					child->parent(parent);
				}
				
	
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs,
	const map<Key,T,Compare,Alloc>& rhs )
	{
		typename ft::map<Key, T>::const_iterator lit = lhs.begin();
		typename ft::map<Key, T>::const_iterator lite = lhs.end();
		typename ft::map<Key, T>::key_compare l_key_comp = lhs.key_comp();

		typename ft::map<Key, T>::const_iterator rit = rhs.begin();
		typename ft::map<Key, T>::const_iterator rite = rhs.end();
		// typename ft::map<Key, T>::key_compare r_key_comp = rhs.key_comp();
		
		while(lit != lite && rit != rite)
		{
			if (l_key_comp(lit->first, rit->first) || l_key_comp(rit->first, lit->first))
				return(false);
			if (lhs.value_comp()(*lit, *rit) || lhs.value_comp()(*rit, *lit))
				return(false);
			lit++;
			rit++;
		}
		if (lit == lite && rit == rite)
			return(true);
		else
			return(false);
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs,
	const map<Key,T,Compare,Alloc>& rhs )
	{
		return(!(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs,
	const map<Key,T,Compare,Alloc>& rhs )
	{
		typename ft::map<Key, T>::const_iterator lit = lhs.begin();
		typename ft::map<Key, T>::const_iterator lite = lhs.end();
		typename ft::map<Key, T>::key_compare l_key_comp = lhs.key_comp();

		typename ft::map<Key, T>::const_iterator rit = rhs.begin();
		typename ft::map<Key, T>::const_iterator rite = rhs.end();
		// typename ft::map<Key, T>::key_compare r_key_comp = rhs.key_comp();
		
		while(lit != lite && rit != rite)
		{
			if (l_key_comp(lit->first, rit->first) || l_key_comp(rit->first, lit->first))
				return(l_key_comp(lit->first, rit->first));
			lit++;
			rit++;
		}
		if (lit == lite && rit == rite)
			return(false);
		else
			return(l_key_comp(lit->first, rit->first));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs,
	const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(rhs < lhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs,
	const map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs,
	const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}
};
#endif