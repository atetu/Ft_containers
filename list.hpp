/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:34:41 by alicetetu         #+#    #+#             */
/*   Updated: 2021/02/18 17:20:20 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <iostream>
#include "Iterator.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class Node
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		//	typedef Iterator<T> iterator;
		// typedef listConstIterator<T> const_iterator;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<iterator> const_reverse_iterator;
		// typedef ft::iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;

	private:
		value_type m_val;
		allocator_type m_allocator;
		Node *m_next;
		Node *m_previous;

	public:
		Node(const allocator_type &alloc = allocator_type()) : m_allocator(alloc)
		{
		}

		Node(const value_type &val, const allocator_type &alloc = allocator_type()) : m_val(val),
																					  m_allocator(alloc)
		{
		}

		~Node()
		{
		}

		Node
			&
			operator=(const Node &other)
		{
			m_val = other.m_val;
			m_allocator = other.m_allocator;
			m_next = other.m_next;
			m_previous = other.m_previous;
		}
		void
		connect(Node *next)
		{
			// std::cout << "next function\n"
			// 		  << std::endl;
			m_previous = next->previous();
			std::cout << "HERE\n";
			m_next = next;

			if (m_previous)
				m_previous->next(this);
			if (next)
				next->previous(this);
		}

		void
		connect(Node *previous, Node *next)
		{
			std::cout << "previous next function\n"
					  << std::endl;
			m_previous = previous;
			m_next = next;

			if (m_previous)
				m_previous->next(this);
			if (next)
				next->previous(this);
		}

		void
		connect_prev_next(Node *previous, Node *next)
		{
			previous->next(next);
			next->previous(previous);
		}
		
		void deconnect()
		{
			m_previous->next(m_next);
			m_next->previous(m_previous);
		}

		void
		next(Node *next)
		{
			m_next = next;
		}

		Node *
		next(void)
		{
			return (m_next);
		}

		void
		previous(Node *previous)
		{
			m_previous = previous;
		}

		Node *
		previous(void)
		{
			return (m_previous);
		}

		value_type &
		value()
		{
			return (m_val);
		}
	};

	template <class T>
	class listIterator
	{
	public:
		typedef T value_type;
		typedef value_type &reference;

	private:
		typedef Node<T> Node;
		//			typedef ft::Node<T> node;

	private:
		Node *m_node;

	public:
		listIterator() : m_node(NULL)
		{
		}

		listIterator(Node *node) : m_node(node)
		{
		}

		listIterator(const Node *node) : m_node(node)
		{
		}

		listIterator(const listIterator &other) : m_node(other.m_node)
		{
		}

		listIterator
		operator=(const listIterator &other)
		{
			m_node = other.m_node;
			return (*this);
		}

		listIterator
		operator++()
		{
			m_node = m_node->next();
			return (*this);
		}

		listIterator
		operator++(int) // ou int?
		{
			listIterator tmp(*this);
			operator++();
			return (tmp);
		}

		listIterator &
		operator--()
		{
			m_node = m_node->previous();
			std::cout << "--\n";
			return (*this);
		}

		listIterator
		operator--(int) // ou int?
		{
			listIterator tmp(*this);
			operator--();
			return (tmp);
		}

		bool
		operator==(const listIterator &other) const
		{
			return (m_node == other.m_node);
		}

		bool
		operator!=(const listIterator &other) const
		{
			return (m_node != other.m_node);
		}

		value_type
		operator*()
		{
			return (m_node->value());
		}

		Node *
		node()
		{
			return (m_node);
		}
	};

	template <typename T, typename Alloc = std::allocator<T> >
	class list
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		//	typedef Iterator<T> iterator;
		typedef listIterator<T> iterator;
		//	typedef Iterator<const T> const_iterator;
		typedef ft::ReverseIterator<iterator> reverse_iterator;
		// typedef ft::ReverseIterator<iterator> const_reverse_iterator;
		// typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;

		typedef typename ft::Node<T> Node;

	private:
		typedef typename Alloc::template rebind<Node>::other NodeAlloc;

	private:
		Alloc m_allocator;
		NodeAlloc m_allocNode;
		size_type m_size;
		Node *m_begin;
		Node *m_first;
		Node *m_end;

		// iterator m_end;
		// iterator m_iterator;


	private:
		void
		init()
		{
			m_end->previous(m_begin);
			m_begin->next(m_end);
			m_first = m_end;
			m_size = 0;
		}
		
		void
		reduce_size()
		{
			m_size--;
		}

	public:
		Node *
		allocate(const T &value)
		{
			Node *node = m_allocNode.allocate(1);
			m_allocNode.construct(node, value);
			return (node);
		}

		explicit list(const allocator_type &alloc = allocator_type()) : //Constructs an empty list with zero elements.
																		m_allocator(alloc)
		{
			m_end = m_allocNode.allocate(1);
			m_allocNode.construct(m_end, value_type());
			m_begin = m_allocNode.allocate(1);
			m_allocNode.construct(m_begin, value_type());
			m_end->previous(m_begin);
			//m_end->next(NULL);
			m_begin->next(m_end);
			m_first = m_end;
			m_size = 0;
		}

		//Constructs a new list with n elements and assigns val to each element of list.
		list(size_type n, const_reference val = value_type(), const allocator_type &alloc = allocator_type())
		{
		}

		explicit list(size_type n) : m_size(n)
		{
		}
		// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) //Constructs a list with as many elements as in range of first to last.
		// {

		// }
		list(const list &other) // Constructs a list with copy of each elements present in existing list
		{
		}

		~list()
		{
		}

		list
			&
			operator=(const list &other)
		{
			m_allocator = other.m_allocator;
			m_allocNode = other.m_allocNode;
			m_size = other.m_size;
			m_begin = other.m_begin;
			m_first = other.m_first;
			m_end = other.m_end;
		}

	public:
		/*ITERATORS*/

		iterator begin(void)
		{
			return (iterator(m_first));
		}

		// const_iterator begin() const
		// {
		// 	return (const_iterator(m_first));
		// }

		iterator end(void)
		{
			return (iterator(m_end));
		}

		// const_iterator end() const
		// {
		// 	return (const_iterator(m_end));
		// }

		// const_iterator cbegin() const //c11
		// {
		// 	return (const_iterator(m_first));
		// }

		// const_iterator cend() const
		// {
		// 	return (const_iterator(m_end));
		// }

		reverse_iterator rbegin()
		{
			return (reverse_iterator(m_end));
		}

		// const_reverse_iterator rbegin() const
		// {
		// 	return (const_reverse_iterator(m_end));
		// }

		// reverse_iterator rend()
		// {
		// 	return (reverse_iterator(m_begin));
		// }

		// const_reverse_iterator rend() const
		// {
		// 	return (const_reverse_iterator(m_begin));
		// }

		/*ELEMENT ACCESS*/

		reference front()
		{
			return (m_first->value());
		}

		const_reference front() const
		{
			return (m_first->value());
		}

		reference back(void)
		{
			return ((m_end->previous())->value());
		}

		const_reference back(void) const
		{
			return ((m_end->previous())->value());
		}

		/*CAPACITY*/

		bool
		empty() const
		{
			return (m_first == m_end);
		}

		size_type
		size() const
		{
			return (m_size);
		}

		// size_type
		// max_size() const
		// {
		// 	return (std::numeric_limits<difference_type>::max());
		// }

		/*MODIFIERS*/

		template <class InputIterator>
		void
		assign(InputIterator first, InputIterator last)
		{
			//list list;
			this->clear();
			while (first != last)
				push_back(*first++);
		}

		void assign(size_type n, const value_type &val)
		{
			this->clear();
			for (size_type count = 0; count < n; count++)
				this->push_back(val);
		}

		void
		push_back(const value_type &val)
		{
			Node *node = m_allocNode.allocate(1);
			m_allocNode.construct(node, val);

			if (m_first == m_end)
			{
				node->connect(m_end);
				m_begin->next(node);
				m_first = node;
			}
			else
			{
				std::cout << "INSIDE\n";
				node->connect(m_end);
				std::cout << "AFTER INSIDE\n";
			}

			m_size++;
			// ft::construct_copy(&(node->data()), val);
			// new (&(node->data()) (val);
		}

		void pop_back()
		{
			if (m_size != 0)
			{
				erase(iterator(m_end->previous()));
				m_size--;
			}
			if (m_size == 0)
				m_first = m_end;
		}
		// if (this->_first == this->_end)
		//     this->_first = new_elem;
		// this->_size++;
		// }

		iterator insert(iterator pos, const T &value) // already allocated?
		{
			iterator it(m_first);
			iterator ite(m_end);

			while (it != pos && it != m_end)
				it++;

			Node *node = allocate(1);
			m_allocNode.construct(node, value);
			if (pos == m_first)
			{
				if (m_first == m_end)
				{
					node->connect(m_end);
					m_begin->next(node);
					m_first = node;
				}
				else
				{
					node->connect(m_first);
					//	m_begin->next(node);
					m_first = node;
				}
			}
			else if (pos == m_end)
			{
				node->connect(m_end);
			}
			else
				node->connect(it.node()->previous(), it.node());

			m_size++;
			return (iterator(node));
		}

		template <class InputIt>
		void insert(iterator pos, InputIt first, InputIt last)
		{
			while (first != last)
			{
				insert(pos, *first);
				first++;
			}
		}

		iterator
		erase(iterator pos)
		{
			if (pos == m_first)
			{
				if (m_first == m_end)
				{
					return (iterator(m_end));
				}
				else
				{
					Node *newFirst = pos.node()->next();
					m_begin->next(newFirst);
					newFirst->previous(m_begin);
					m_first = newFirst;
					m_size--;
					m_allocNode.destroy(pos.node());
					m_allocNode.deallocate(pos.node(), 1);
					return (iterator(newFirst));
				}
			}
			else if (pos == m_end)
				return (iterator(m_end));

			//std::cout << "ici\n";
			Node *previous = pos.node()->previous();
			Node *next = pos.node()->next();
			//	std::cout << "node: " << pos.node()->value() << std::endl;
			m_allocNode.destroy(pos.node());
			m_allocNode.deallocate(pos.node(), 1);

			//	std::cout << "la\n";
			previous->next(next);
			//			std::cout << "pouet\n";
			next->previous(previous);
			//				std::cout << "hello\n";
			m_size--;
			return (iterator(next));
		}

		iterator
		erase(iterator first, iterator last)
		{
			iterator tmp;
			while (first != last)
			{
				tmp = first;
				first++;
				erase(tmp);
			}
			return (last);
		}

		void swap(list &x)
		{
			size_type sizeCopy = m_size;
			Node *beginCopy = m_begin;
			Node *firstCopy = m_first;
			Node *endCopy = m_end;

			m_size = x.size();
			m_begin = x.begin();
			m_first = x.first();
			m_end = x.end();

			x.size(sizeCopy);
			x.begin(beginCopy);
			x.first(firstCopy);
			x.end(endCopy);
		}

		void resize(size_type n, value_type val = value_type())
		{
			int count = 0;
			Node *tmp = m_first;
			Node *save = NULL;

			if (n < m_size)
			{
				while (count <= n)
				{
					if (count != 0)
						tmp = tmp->next();
					if (count == n - 1)
					{
						m_end->previous(tmp);
						save = tmp->next();
						tmp->next(m_end);
						tmp = save;
					}
					count++;
				}

				while (count < m_size)
				{
					save = tmp->next();
					m_allocNode.destroy(tmp);
					m_allocNode.deallocate(tmp, 1);
					tmp = save;
					count++;
				}
				m_size = n;
			}
			else if (n > m_size)
			{
				Node *cur = m_end->previous();
				while (m_size != n)
					this->push_back(val);
			}
		}

		void clear()
		{
			iterator it(m_first);
			iterator ite(m_end);
			Node *next;

			while (m_first != m_end)
			{
				next = m_first->next();
				m_allocNode.destroy(m_first);
				m_allocNode.deallocate(m_first, 1);
				m_first = next;
			}
			m_end->previous(m_begin);
			m_begin->next(m_end);
			m_first = m_end;
			m_size = 0;
		}

		void splice(iterator position, list &x)
		{
			iterator x_it = x.begin();
			iterator x_ite = x.end();
			Node *tmp;
			int x_size = 0;
			int first_indicator = 0;
			
			if (position.node() == m_first)
				first_indicator = 1;
		
			while (x_it != x_ite)
			{
				tmp = x_it.node()->next();
				x_it.node()->deconnect();
				x_it.node()->connect(position.node()->previous(), position.node());
			
				x_it = iterator(tmp);
				m_size++;
				if (first_indicator)
					m_first = position.node()->previous();
				first_indicator = 0;
			}
			x.init();
		}

		void splice(iterator position, list &x, iterator i)
		{
			iterator x_it = x.begin();
			iterator x_ite = x.end();
			Node *tmp;
			int x_size = 0;
			int first_indicator = 0;
			int x_first_indicator = 0;

			if (i == x_it) // not sure about that, the real one aborts
				return;	
			if (position.node() == m_first)
				first_indicator = 1;
			if (i.node() == x_it.node())
				x_first_indicator = 1;
			i.node()->deconnect();
			i.node()->connect(position.node()->previous(), position.node());
			m_size++;
			if (first_indicator)
				m_first = position.node()->previous();
			x.reduce_size();
			if (x_first_indicator)
				x.init();
		}

		void splice(iterator position, list &x, iterator first, iterator last)
		{
			iterator x_it = x.begin();
			Node *tmp;
			int first_indicator = 0;
			int x_first_indicator = 0;
			
			if (position.node() == m_first)
				first_indicator = 1;
			if (first.node() == x_it.node())
				x_first_indicator = 1;
			while (first != last)
			{
				std::cout <<"Ici:" << first.node()->value() << std::endl;
				tmp = first.node()->next();
				first.node()->deconnect();
				first.node()->connect(position.node()->previous(), position.node());
			
				first = iterator(tmp);
				m_size++;
				if (first_indicator)
					m_first = position.node()->previous();
				first_indicator = 0;
				x.reduce_size();
			}
			if (x_first_indicator)
				x.init();
		}

		void remove(const value_type &val)
		{
			iterator it(m_first);
			iterator ite(m_end);

			while (it != m_end)
			{
				if (*it == val)
					it = erase(it);
				else
					it++;
			}
		}

		template <class Predicate>
		void remove_if(Predicate pred)
		{
			iterator it(m_first);
			iterator ite(m_end);

			while (it != m_end)
			{
				if (pred(*it))
					it = erase(it);
				else
					it++;
			}
		}

		void unique()
		{
			iterator it(m_first);
			iterator it_first(m_first);
			iterator it_previous;
			iterator ite(m_end);

			while (it != m_end)
			{
				if (it != it_first)
				{
					if (*it_previous == *it)
					{
						it = erase(it);
						continue;
					}
				}
				else
				{
					it_previous = it;
					it++;
				}
			}
		}

		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			iterator it(m_first);
			iterator it_first(m_first);
			iterator it_previous;
			iterator ite(m_end);

			while (it != m_end)
			{
				if (it != it_first)
				{
					if (binary_pred, *it, *it_previous)
					{
						it = erase(it);
						continue;
					}
				}
				else
				{
					it_previous = it;
					it++;
				}
			}
		}

		void merge(list &x)
		{
			iterator it(m_first);
			iterator it_first(m_first);
			iterator it_previous;
			iterator ite(m_end);

			iterator itx = x.begin();
			iterator itx_first = x.begin();
			iterator itx_previous;
			iterator itex = x.end();

			Node *tmp;

			int notSorted = 0;

			if (x.empty())
				return;
			while (it != ite)
			{
				if (it != it_first)
				{
					if (it.node()->previous()->value() > it.node()->value())
					{	
						notSorted = 1;
						break;
					}
				}
				it++;
			}
			if (!notSorted)
			{
				while (itx != itex)
				{
					if (itx != itx_first)
					{
						if (*itx_previous > *itx)
							notSorted = 1;
						break;
					}
					itx++;
				}
			}
			if (!notSorted)
			{
				ite--;
				splice(ite, x);
				return;
			}
			it = begin();
			ite = end();
			itx = x.begin();
			itex = x.end();

			while (it != ite && itx != itex)
			{
				if (*it > *itx)
				{
					tmp = itx.node()->next();
					splice(it, x, itx);
					itx = iterator(tmp);
				}
				else
					it++;
			}
			if (itx != itex)
				splice(ite, x);
		}

		template<class Compare>
		void merge(list& x, Compare comp)
		{
			
		}

		void sort()
		{
			iterator it(m_first);
			iterator it_first(m_first);
			iterator ite(m_end);
			iterator before_end = ite;
			before_end--;
			iterator to_compare;
			Node *new_it;
			Node *new_next;
			Node *prev_it;
			Node *next_it;
			Node *prev_compare;
			Node *next_compare;
		
			int notSorted = 0;
			to_compare = it;
			to_compare++;
	//		std::cout << "First:" << *it << std::endl;
	//		std::cout << "To compare:" << *to_compare << std::endl;
			while (it != before_end)
			{
				// if (it != it_first)
				// {
			//	to_compare = it;
			//	to_compare++;
				while(to_compare != ite)
				{
				// 	std::cout << "First:" << *it << std::endl;
				// 	std::cout << "To compare:" << *to_compare << std::endl;
				// 	std::cout << "to compare: " << to_compare.node()->value() << std::endl;
					if (*it > *to_compare)
					{	
						// std::cout << "IT:" << it.node()->value()<< std::endl;
						// std::cout << "TO_compare: " << *to_compare<< std::endl;
						new_it = to_compare.node();
						new_next = it.node();
						prev_it = it.node()->previous();
						next_it = it.node()->next();
						prev_compare = to_compare.node()->next();
						next_compare = to_compare.node()->next();
						if (it.node() == m_first)
							m_first = new_it;
							
						new_it->connect(prev_it, next_it);
						new_next->connect(prev_compare, next_compare);
						it = new_it;
						to_compare = new_next;
					//	std::cout << "ICI\n";
					}
					if (to_compare != ite)
						to_compare++;
					std::cout << "POUET\n";
			//		std::cout << "to compare: " << to_compare.node()->value() << std::endl;
				}
				// }
				it++;
				std::cout << "OUT\n";
				if (it != before_end)
				{
					to_compare = it;
					to_compare++;
				}
			}	
		}
		
	};

} // namespace ft

#endif