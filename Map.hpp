/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:45:55 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/07 16:39:21 by alicetetu        ###   ########.fr       */
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
				if (this != l)
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
			MapNode *tmp;
			if (m_node->hasRight())
			{
				m_node = identifyDeepestLeft(m_node->right());
				if (m_node == NULL && m_node->hasRight())
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
					}	
				}
			}
			return (*this);
		}

		MapNode*
		identifyDeepestLeft(MapNode* node)
		{
		//	std::cout << "trouble node: " << node << " - " << node->hasLeft() << "\n" << std::flush;
			MapNode* tmp = node;
			while (tmp->hasLeft())
				tmp = tmp->left();
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
			// std::cout << "address:" << m_node << std::endl;
			// std::cout << "value: " << m_node->value() << std::endl;
			return (m_node->value());
		}

		MapNode *node() const
		{
			return (m_node);
		}
	};

	
	template <class Key, class T>
	class ConstMapIterator
	{
	public:
		typedef const T value_t;
		typedef const value_t &reference;
		typedef const value_t& const_reference;

	private:
		typedef MapNode<Key, T> MapNode;

	private:
		MapNode *m_node;

	public:
		ConstMapIterator() : m_node(NULL)
		{
		}

		ConstMapIterator(MapNode *node) : m_node(node)
		{
		}

		ConstMapIterator(const MapNode *node) : m_node(node)
		{
		}

		ConstMapIterator(const ConstMapIterator &other) : m_node(other.m_node)
		{
		}

		ConstMapIterator
		operator=(const ConstMapIterator &other)
		{
		//	m_node = other.m_node;
			return (*this);
		}

		ConstMapIterator
		operator++()
		{
			MapNode *tmp;
			if (m_node->hasRight())
			{
				m_node = identifyDeepestLeft(m_node->right());
				if (m_node == NULL && m_node->hasRight())
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
					}	
				}
			}
			return (*this);
		}

		MapNode*
		identifyDeepestLeft(MapNode* node)
		{
		//	std::cout << "trouble node: " << node << " - " << node->hasLeft() << "\n" << std::flush;
			MapNode* tmp = node;
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

		const_reference
		operator*() const
		{
			// std::cout << "address:" << m_node << std::endl;
			// std::cout << "value: " << m_node->value() << std::endl;
			return (m_node->value());
		}

		const MapNode *node() const
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
			typedef ConstMapIterator<Key, T> const_iterator;
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
					m_comp(comp),
					m_allocator(alloc),
					m_root(NULL),
					m_size(0)
				{
					   createEndNode();
				}

				map (const map& x) : 
					m_allocator(x.m_allocator),
					m_comp(x.m_comp),
					m_root(NULL),
					m_first(NULL),
					m_end(x.m_end),
					m_size(x.m_size)

				{
					createEndNode();
					insert(x.first(), x.end());
					
				}

				
				T& operator[](const Key& key)
				{
					iterator it = find(key);
					return(*it);
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
										
					MapNode* tmp = createNode(val);
					MapNode* root_copy = m_root;
					ret = search_insert(0, 0, root_copy, tmp);
					if (ret.value() && !m_root)
					{
						iterator it = ret.key();
						m_root = it.node();
						std::cout << m_root->value() << std::endl;
					}
					return(setLimitsPair(ret));
				}
				
				iterator
				insert (iterator position, const value_t& val)
				{
					return(insert(val).Key());
				}
				
				template <class InputIterator>
				void insert (InputIterator first, InputIterator last)
				{
					iterator f = first;
					iterator l = last;
					for (; f!= l ; f++)
						insert(*f);
				}
				
				void erase (iterator position)
				{
					MapNode *substitute = NULL;
					
					if (position.node() == m_root)
					{
						//std::cout << "ROOT\n";
						if (m_root->isLeaf(m_end))
						{
							newRoot(substitute, position);
							m_first = m_end = m_root;
						}
						else if (m_root->hasOneChild())
						{
							substitute = identifyTheChild(m_root);
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
						// if (position.node()->isLeaf(m_end))
						// {
						// 	std::cout << "LEAF\n";
						// 	// destroyMapNode(position);
						// 	// setLimits();
						// 	// m_size--;
						// }
						if (position.node()->hasOneChild())
						{
							std::cout << "ONE CHILD\n";
							substitute = identifyTheChild(position.node());
							adoption(substitute, position.node());
							// destroyMapNode(position);
							// m_size--;
						}
						else if (!(position.node()->isLeaf(m_end)))
						{
							std::cout << "TWO CHILDREN\n";
							int side = position.node()->identifyParentSize();
							substitute = identifyTheDeepestChild(side, position.node());
						//	std::cout << "substitute: " << substitute->value() << std::endl;
							cutTheApronStrings(substitute);
							adoption(substitute, position.node());
							// destroyMapNode(position);
							// m_size--;
						}
						destroyMapNode(position);
						setLimits();
						m_size--;
					}
				}

				size_type
				erase(const key_type& k)
				{
					size_type size = 0;
					iterator found;
					while((found = find(k)) != m_end)
					{
						erase(found);
						size++;
					}
					return (size);
				}

				
				void erase(iterator first, iterator last)
				{
					while (first != last)
					{
						iterator tmp = first;
						first++;
						erase(tmp);
					}
				}
				
				void swap(map &x)
				{
					map copy(*this);
					*this = x;
					x = copy;
				//copy.clear();					
				}

				void clear()
				{
					iterator first = begin();
					iterator last = end();
					erase(first, last);
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

				const iterator find(const key_type &k) const
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
						return(const_iterator(found));
					else
						return (end());
				}
				
				size_type count (const key_type& k) const
				{
					size_type size = 0;
					iterator found;
					while((found = find(k)) != m_end)
						size++;
					return (size);
				}

				iterator lower_bound (const key_type& k)
				{
					iterator found = begin();
					iterator ite = end();
				
					while(key_comp((*found)->key(), k) && found != ite)
						found++;
					
					return(found);
				}
				
				const_iterator lower_bound (const key_type& k) const
				{
					const_iterator found = begin();
					const_iterator ite = end();
				
					while(key_comp((*found)->key(), k) && found != ite)
						found++;
					
					return(found);
				}
				
				iterator upper_bound (const key_type& k)
				{
					iterator found = begin();
					iterator ite = end();
				
					while(key_comp((*found)->key(), k) && found != ite)
						found++;
					if (*found != ite && !(key_found(k, *found)->key()))
						found++;
					return(found);
				}

				const_iterator upper_bound (const key_type& k) const
				{
					const_iterator found = begin();
					const_iterator ite = end();
				
					while(key_comp((*found)->key(), k) && found != ite)
						found++;
					if (*found != ite && !(key_found(k, *found)->key()))
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
				createNode(const value_t& val)
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
					return (make_pair<iterator, bool>(it_x, p.value()));
				}

				void
				setLimits()
				{
					MapNode* first = NULL;
					MapNode* end = NULL;
					if (m_root != m_end)
					{
						if (m_root->hasLeft())
							m_first = identifyDeepestLeft(m_root->left());
						else
							m_first = m_root;
						if (m_root->hasRight())
						{
							end = identifyDeepestRight(m_root->right());
						//std::cout << "end: " << end->value() << std::endl;
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
						// if (!(m_comp(val.key(), node->key())) && !(m_comp(node->key(), val.key())))
						// 	return (make_pair<iterator, bool>(iterator(node), false));
						//std::cout << "val: " << node->key() << " _ node: " << pos->key() << std::endl;
						if (m_comp(node->key(), pos->key()))
						{
							//std::cout << "left\n";
							return(search_insert(pos, 0, pos->left(), node));
						}
						else
						{
							//std::cout << "right\n";
							return(search_insert(pos, 1, pos->right(), node));
						}
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
				//	std::cout << " side : " << side << std::endl;
					if (side == 1)
					{
						child = identifyDeepestLeft(node->left());
						if (child->isLeaf(m_end)) // complete for end
						{
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
						child = identifyDeepestRight(node->right());
						if (child->isLeaf(m_end)) // complete for end
						{
							connection(child, 0, node->right());
							if (child != node->right())
								connection(child, 1, node->right());
							else
								child->right(NULL);
						}
						else
						{
							connection(child, 1, child->left());
							connection(child, 0, node->left());
						}
					}
					return(child);
				}

				MapNode*
				identifyDeepestLeft(MapNode* node)
				{
					MapNode* tmp = node;
					while (tmp->hasLeft())
						tmp = tmp->left();
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
		
	}
};
#endif