/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:45:55 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/04 20:27:27 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <iostream>
#include <exception>

/*https://www.geeksforgeeks.org/deletion-binary-tree/*/

namespace ft
{
	template< class T1, class T2>
	class pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
		
		private:
			T1 first;
			T2 second;

		public:
			pair() : first(), second()
			{
			}

			pair(const T1& x,const T2& y) : first(x), second(y)
			{
			}

			template< class U1, class U2 >
			pair(const pair<U1, U2>& p ) : first(p.key()), second(p.value())
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
			
		//	friend pair<T1,T2> make_pair(T1 t, T2 u);
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
			return (x < y);
		}
	};
	

	template< class Key, class T > class MapNode
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const Key, T> value_t;
			// typedef size_t size_type;
			// typedef ptrdiff_t difference_type;
			// typedef Compare key_compare;
		//	typedef Allocator allocator_t;

		private:
		//	allocator_t m_allocator;
			MapNode *m_parent;
			MapNode *m_left;
			MapNode *m_right;
			value_t m_pair;
			int m_color;
			

		public:
			// MapNode(const allocator_t &alloc = allocator_t()) : m_allocator(alloc)
			// {
			// }
			MapNode() : m_pair(value_t())
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
			// MapNode() : va
			// {
			// }
			
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
				m_left = l;
			}

			void right(MapNode* r)
			{
				m_right = r;
			}
			
			value_t& pair()
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
			isLeaf()
			{
				return (m_left == NULL && m_right == NULL);
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
	};

	template <class Key, class T>
	class MapIterator
	{
	public:
		typedef T value_t;
		typedef value_t &reference;

	private:
		typedef MapNode<Key, T> MapNode;

	private:
		MapNode *m_node;

	public:
		MapIterator() : m_node(NULL)
		{
		}

		MapIterator(MapNode *node) : m_node(node)
		{
		}

		MapIterator(const MapNode *node) : m_node(node)
		{
		}

		MapIterator(const MapIterator &other) : m_node(other.m_node)
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
			if (m_node->hasRight())
				m_node = m_node->right();
			else
			{
				if (m_node == m_node->parent()->left())
					m_node == m_node->parent();
				else
				{
					while (m_node == m_node->parent()->right())
						m_node = m_node->parent();		
				}
			}
			return (*this);
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
			if (m_node->hasLeft())
				m_node = m_node->left();
			else
			{
				if (m_node == m_node->parent()->right())
					m_node == m_node->parent();
				else
				{
					while (m_node == m_node->parent()->left())
						m_node = m_node->parent();		
				}
			}
			return (*this);
		}

		MapIterator
		operator--(int)
		{
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

		reference
		operator*() const
		{
			return (m_node->value());
		}

		MapNode *node() const
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
			typedef pair<Key, T> value_t;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Allocator allocator_t;
			typedef typename allocator_t::reference reference;
			typedef typename allocator_t::const_reference const_reference;
			typedef typename allocator_t::pointer pointer;
			typedef typename allocator_t::const_pointer const_pointer;
			typedef MapIterator<Key, T> iterator;
			// typedef ConstMapIterator<T> const_iterator;
			// typedef ft::ReverseMapIterator<T> reverse_iterator;
			// typedef ft::ConstReverseMapIterator<T> const_reverse_iterator;
			typedef typename ft::MapNode<Key, T> MapNode;
			//typedef insert_return_type; // rien compris


		// private:
		// 	typedef typename Allocator::template rebind<MapNode>::other MapNodeAlloc;
		
		public:
			class value_compare
			{
				public:
					typedef bool result_type;
					typedef value_t first_argument_type;
					typedef value_t second_argument_type;
					
				protected:
					Compare m_comp;
				
				public:
				
			};

		private:
			allocator_t m_allocator;
			key_compare m_comp;
			// MapNodeAlloc m_allocMapNode;
			MapNode* m_root;
			MapNode *m_first;
			MapNode *m_end;
			int m_size;

		public:
				explicit map (const key_compare& comp = key_compare(),
					const allocator_t& alloc = allocator_t()) :
						m_comp(comp),
						m_allocator(alloc),
						m_root(NULL),
						m_first(NULL),
						m_end(NULL),
						m_size(0)
				{
					std::cout << "ICI\n";
					m_end = m_allocator.allocate(1);
					m_allocator.construct(m_end, MapNode());
					// m_first = m_end;
				}
				
				template <class InputMapIterator>
				map (InputMapIterator first, InputMapIterator last,
				const key_compare& comp = key_compare(),
				const allocator_t& alloc = allocator_t()) :
					m_comp(comp),
					m_allocator(alloc),
					m_root(NULL),
					m_size(0)
				{
					   
				}

				map (const map& x)
				{
					
				}

				iterator begin()
				{
					return(iterator(m_first));
				}

				// const_iterator begin() const
				// {
				// 	return (const_iterator(m_first));
				// }

				iterator end()
				{
					return(iterator(m_end));
				}

				// const_iterator end() const
				// {
				// 	return (const_iterator(m_end));
				// }

				// reverse_iterator rbegin()
				// {
				// 	return (reverse_iterator(m_end->previous()));
				// }

				// const_reverse_iterator rbegin() const
				// {
				// 	return (const_reverse_iterator(m_end->previous()));
				// }

				// reverse_iterator rend()
				// {
				// 	return (reverse_iterator(m_begin));
				// }

				// const_reverse_iterator rend() const
				// {
				// 	return (const_reverse_iterator(m_begin));
				// }

				/*CAPACITY*/
				
				bool empty() const
				{
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
				insert (const value_t& val)
				{
					pair<iterator,bool> ret;
					// if (ptr = exist_equal(val))
					// 	return (make_pair(iterator(ptr), false));
					// check that key of the pair does not exist
					//find the location
					// inserts
					// rotates
					// increase the size
					// returns pair
					
					MapNode* tmp = NULL;
					ret = search_insert(tmp, val);
					if (ret.value() && !m_root)
						m_root = tmp;
					return(ret);
				}
				

				void erase (iterator position)
				{
					MapNode *substitute = NULL;
					
					if (position.node() == m_root)
					{
						if (m_root->isLeaf())
							newRoot(substitute, position);
						else if (m_root->hasOneChild())
						{
							substitute = identifyTheChild(m_root);
							newRoot(substitute, position);
						}
						else
						{
							int side = highestHigh(m_root);
							substitute = identifyTheDeepestChild(side, position.node());
							cutTheApronStrings(substitute);
							newRoot(substitute, position);
						}
					}
					else
					{
						if (position.node()->isLeaf())
						{
							destroyMapNode(position);
							m_size--;
						}
						else if (position.node()->hasOneChild())
						{
							substitute = identifyTheChild(position.node());
							adoption(substitute, substitute);
							destroyMapNode(position);
							m_size--;
						}
						else
						{
							int side = position.node()->identifyParentSize();
							substitute = identifyTheDeepestChild(side, position.node());
							cutTheApronStrings(substitute);
							adoption(substitute, position.node());
							destroyMapNode(position);
							m_size--;
							
						}
					}
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
					while(!(!m_comp(found->key(), k) && !m_comp(found->key(), k)))
					{
						if (m_comp(k, found->key()))
							found = found->left();
						else if (m_comp(found->key(), k))
							found = found->right();
					}
					if (found)
						return(iterator(found));
					else
						return (end());
				}


				
				
			private:
			
				pair<iterator,bool>
				search_insert(MapNode *node, const value_t& val)
				{
					if (node == NULL)
					{
						node = m_allocator.allocate(1);
						m_allocator.construct(node, val);
						(node)->left(NULL);
						(node)->right(NULL);
						m_size++;
						iterator it = iterator(node);
						return (make_pair<iterator, bool>(it, true));
					}
					else
					{
						if (val.key() == (node)->key())
							return (make_pair<iterator, bool>(iterator(node), false));
						if (val.key() < (node)->key())
						{
							MapNode *newNode = (node)->left();
							return(search_insert(newNode, val));
						}
						else
							return(search_insert(node->right(), val));
					}
				}

				void destroyMapNode(iterator pos)
				{
					m_allocator.destroy(pos.node());
					m_allocator.deallocate(pos.node(), 1);	
				}
				
				void adoption(MapNode *child, MapNode *node)
				{
					child->parent(node->parent());
					int parentSide = node->identifyParentSide();
					if (parentSide == 0)
						node->parent()->left(child);
					else
						node->parent()->right(child);
				}

				void cutTheApronStrings(MapNode *child)
				{
					if (child->identifyParentSide() == 0)
						child->parent()->left(NULL);
					else
						child->parent->right(NULL);
				}

				void newRoot(MapNode* substitute, iterator pos)
				{
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
					if (side == 1)
						return(identifyDeepestLeft(node->left()));
					else
						return(identifyDeepestRight(node->right()));
				}

				MapNode*
				identifyDeepestLeft(MapNode* node)
				{
					MapNode* tmp = node;
					while (!(tmp->isLeaf()))
						node = node->left();
				}

				MapNode*
				identifyDeepestRight(MapNode* node)
				{
					MapNode* tmp = node;
					while (!(tmp->isLeaf()))
						node = node->right();
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
	};
};
#endif