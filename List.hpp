/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:34:41 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/16 15:17:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "ReverseIterator.hpp"
#include "utils.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class Node
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef T &reference;
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

		Node &
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
			m_previous = next->previous();
			m_next = next;
			if (m_previous)
				m_previous->next(this);
			if (next)
				next->previous(this);
		}

		void
		connect(Node *previous, Node *next)
		{
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
		next(void) const
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

		T &
		value()
		{
			return (m_val);
		}

		const T &
		value() const
		{
			return (m_val);
		}
	};

	template <class T>
	class listIterator
	{
	public:
		typedef T value_type;
		typedef const T const_value_type;
		typedef value_type &reference;
		typedef value_type *pointer;
		typedef const_value_type *const_pointer;

		static const bool listIt;
		
	private:
		Node<T> *m_node;

	public:
		listIterator() : m_node(NULL)
		{
		}

		listIterator(Node<T> *node) : m_node(node)
		{
		}

		listIterator(const Node<T> *node) : m_node(node)
		{
		}

		listIterator(const listIterator &other) : m_node(other.m_node)
		{
		}

		~listIterator()
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
		operator++(int)
		{
			listIterator tmp(*this);
			operator++();
			return (tmp);
		}

		listIterator &
		operator--()
		{
			m_node = m_node->previous();
			return (*this);
		}

		listIterator
		operator--(int)
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

		reference
		operator*() const
		{
			return (m_node->value());
		}

		Node<T> *node() const
		{
			return (m_node);
		}

		pointer
		operator->() const
		{
			return (&(m_node->value()));
		}

		listIterator
		base() const
		{
			return (*this);
		}
	};

	template <class T>
	const bool listIterator<T>::listIt = true;
		
	template <class T>
	class listConstIterator
	{
	public:
		typedef T value_type;
		typedef const T const_value_type;
		typedef value_type &reference;
		typedef const_value_type &const_reference;
		typedef value_type *pointer;
		typedef const_value_type *const_pointer;

		static const bool listIt;
		
	private:
		Node<T> *m_node;

	public:
		listConstIterator() : m_node(NULL)
		{
		}

		listConstIterator(Node<T> *node) : m_node(node)
		{
		}

		listConstIterator(const Node<T> *node) : m_node(node)
		{
		}

		listConstIterator(const listConstIterator &other) : m_node(other.m_node)
		{
		}

		~listConstIterator()
		{
		}

		listConstIterator
		operator=(const listConstIterator &other)
		{
			m_node = other.m_node;
			return (*this);
		}

		listConstIterator
		operator++()
		{
			m_node = m_node->next();
			return (*this);
		}

		listConstIterator
		operator++(int)
		{
			listConstIterator tmp(*this);
			operator++();
			return (tmp);
		}

		listConstIterator &
		operator--()
		{
			m_node = m_node->previous();
			return (*this);
		}

		listConstIterator
		operator--(int)
		{
			listConstIterator tmp(*this);
			operator--();
			return (tmp);
		}

		bool
		operator==(const listConstIterator &other) const
		{
			return (m_node == other.m_node);
		}

		bool
		operator!=(const listConstIterator &other) const
		{
			return (m_node != other.m_node);
		}

		const_reference
		operator*() const
		{
			return (m_node->value());
		}

		const_pointer
		operator->() const
		{
			return (&(m_node->value()));
		}

		const Node<T> *
		node() const
		{
			return (m_node);
		}

		listConstIterator
		base() const
		{
			return (*this);
		}
	};

	template <class T>
	const bool listConstIterator<T>::listIt = true;
	
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
		typedef listIterator<T> iterator;
		typedef listConstIterator<T> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
		typedef __gnu_cxx::ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef typename ft::Node<T> Node;
		typedef typename Alloc::template rebind<Node>::other NodeAlloc;

	private:
		Alloc m_allocator;
		NodeAlloc m_allocNode;
		size_type m_size;
		Node *m_begin;
		Node *m_first;
		Node *m_end;

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
		init_first()
		{
			m_first = m_begin->next();
		}

		void
		reduce_size()
		{
			m_size--;
		}

		void setSize(size_type s)
		{
			m_size = s;
		}

		void begin(Node *b)
		{
			m_begin = b;
		}

		void first(Node *f)
		{
			m_first = f;
		}

		void end(Node *e)
		{
			m_end = e;
		}

		Node *beginNode()
		{
			return (m_begin);
		}

		void create_list()
		{
			m_end = m_allocNode.allocate(1);
			m_allocNode.construct(m_end, value_type());
			m_begin = m_allocNode.allocate(1);
			m_allocNode.construct(m_begin, value_type());
			m_end->previous(m_begin);
			m_end->next(NULL);
			m_begin->next(m_end);
			m_first = m_end;
			m_size = 0;
		}
		
		Node *
		allocate(const T &value)
		{
			Node *node = m_allocNode.allocate(1);
			m_allocNode.construct(node, value);
			return (node);
		}

	public:
		
		explicit list(const allocator_type &alloc = allocator_type()) : m_allocator(alloc)
		{
			m_end = m_allocNode.allocate(1);
			m_allocNode.construct(m_end, value_type());
			m_begin = m_allocNode.allocate(1);
			m_allocNode.construct(m_begin, value_type());
			m_end->previous(m_begin);
			m_end->next(NULL);
			m_begin->next(m_end);
			m_first = m_end;
			m_size = 0;
		}

		//Constructs a new list with n elements and assigns val to each element of list.
		explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : m_allocator(alloc)
		{
			create_list();
			assign(n, val);
		}

		template <class InputIterator>
		list(InputIterator first, typename allow_if<InputIterator::listIt, InputIterator>::type last, const allocator_type &alloc = allocator_type()) : m_allocator(alloc)
		{
			create_list();
			this->assign(first, last);
		}

		// Constructs a list with copy of each elements present in existing list
		list(const list &other)
		{
			m_allocator = other.m_allocator;
			create_list();
			assign(other.begin(), other.end());
		}

		~list()
		{
			clear();
			m_allocNode.destroy(m_begin);
			m_allocNode.deallocate(m_begin, 1);
			m_allocNode.destroy(m_end);
			m_allocNode.deallocate(m_end, 1);
		}

		list &
		operator=(const list &other)
		{
			if (this != &other)
			{
				if (begin() != end())
					this->erase(begin(), end());
				const_iterator it = other.begin();
				const_iterator ite = other.end();
				while (it != ite)
				{
					push_back(*it);
					it++;
				}
			}
			return (*this);
		}

	public:
		/*ITERATORS*/

		iterator begin(void)
		{
			return (iterator(m_first));
		}

		const_iterator begin() const
		{
			return (const_iterator(m_first));
		}

		iterator end(void)
		{
			return (iterator(m_end));
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
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}

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
			return (m_size == 0);
		}

		size_type
		size() const
		{
			return (m_size);
		}

		size_type
		max_size() const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(Node));
		}

		/*MODIFIERS*/

		template <class InputIterator>
		void
		assign(InputIterator first, typename allow_if<InputIterator::listIt, InputIterator>::type last)
		{
			this->clear();

			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void assign(size_type n, const value_type &val)
		{
			this->clear();
			for (size_type count = 0; count < n; count++)
				this->push_back(val);
		}

		void
		push_front(const value_type &val)
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
				node->connect(m_first);
				m_first = node;
			}
			m_size++;
		}

		void pop_front()
		{

			if (m_size != 0)
			{
				Node *next = m_first->next();
				erase(iterator(m_first));
				m_size--;
				m_first = next;
			}
			if (m_size == 0)
				m_first = m_end;
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
				node->connect(m_end);

			m_size++;
		}

		void pop_back()
		{
			if (m_size != 0)
				erase(iterator(m_end->previous()));
			if (m_size == 0)
				m_first = m_end;
		}

		iterator insert(iterator pos, const T &value)
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

		void insert (iterator position, size_type n, const value_type& val)
		{
			for (size_type i = 0 ; i< n; i++)
			{
				position = insert(position, val);
			}
		}
		
		template <class InputIt>
		void insert(iterator pos, InputIt first, typename allow_if<InputIt::listIt, InputIt>::type last)
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

			Node *previous = pos.node()->previous();
			Node *next = pos.node()->next();
			m_allocNode.destroy(pos.node());
			m_allocNode.deallocate(pos.node(), 1);

			previous->next(next);
			next->previous(previous);

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
			m_begin = x.beginNode();
			m_first = x.begin().node();
			m_end = x.end().node();

			x.setSize(sizeCopy);
			x.begin(beginCopy);
			x.first(firstCopy);
			x.end(endCopy);
		}

		void resize(size_type n, value_type val = value_type())
		{
			size_type count = 0;
			Node *tmp = m_first;
			Node *save = NULL;

			if (n < m_size)
			{
				while (count < n)
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
				size_t size_copy = m_size;	
				while (count < size_copy)
				{
					if (count != size_copy)	
						save = tmp->next();
					m_allocNode.destroy(tmp);
					m_allocNode.deallocate(tmp, 1);
					if (count != size_copy)
						tmp = save;
					count++;
					m_size--;
				}
			}
			else if (n > m_size)
			{
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
			iterator it_first(m_first);
			int first_indicator = 0;
			int x_first_indicator = 0;

			if (i == x_ite)
				return;
			if (position == it_first)
				first_indicator = 1;
			if (i.node() == x_it.node())
				x_first_indicator = 1;
			i.node()->deconnect();
			i.node()->connect(position.node()->previous(), position.node());
			m_size++;
			if (first_indicator)
				m_first = i.node();
			x.reduce_size();
			if (x_first_indicator)
				x.init_first();
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
			iterator itnext;
			iterator ite(m_end);

			while (it != m_end)
			{
				itnext = it;
				itnext++;
				while (itnext != ite)
				{
					if (*it == *itnext)
						itnext = erase(itnext);
					else
						itnext++;
				}
				it++;
			}
		}

		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			iterator it(m_first);
			iterator itnext;
			iterator ite(m_end);

			while (it != m_end)
			{
				itnext = it;
				itnext++;
				while (itnext != ite)
				{
					if (binary_pred(*it, *itnext))
						itnext = erase(itnext);
					else
						itnext++;
				}
				it++;
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

			int sorted = 1;
			if (x.empty())
				return;
			while (it != ite)
			{
				if (it != it_first)
				{
					if (it.node()->previous()->value() > it.node()->value())
					{
						sorted = 0;
						break;
					}
				}
				it++;
			}
			if (sorted)
			{
				while (itx != itex)
				{
					if (itx != itx_first)
					{
						if (itx.node()->previous()->value() > itx.node()->value())
							sorted = 0;
						break;
					}
					itx++;
				}
			}
			if (!sorted)
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
			x.m_size = 0;
		}

		template <class Compare>
		void merge(list &x, Compare comp)
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

			int sorted = 1;
			if (x.empty())
				return;
			while (it != ite)
			{
				if (it != it_first)
				{
					if (it.node()->previous()->value() > it.node()->value())
					{
						sorted = 0;
						break;
					}
				}
				it++;
			}
			if (sorted)
			{
				while (itx != itex)
				{
					if (itx != itx_first)
					{
						if (itx.node()->previous()->value() > itx.node()->value())
							sorted = 0;
						break;
					}
					itx++;
				}
			}
			if (!sorted)
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
				if (!comp(*it, *itx))
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
			x.m_size = 0;
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

			to_compare = it;
			to_compare++;
			while (it != before_end)
			{
				while (to_compare != ite)
				{
					if (*it > *to_compare)
					{
						new_it = to_compare.node();
						new_next = it.node();
						if (it.node()->next() == to_compare.node())
						{
							next_it = it.node();
							prev_compare = to_compare.node();
						}
						else
						{
							next_it = it.node()->next();
							prev_compare = to_compare.node()->previous();
						}
						prev_it = it.node()->previous();
						next_compare = to_compare.node()->next();
						if (it.node() == m_first)
							m_first = new_it;
						new_it->connect(prev_it, next_it);
						new_next->connect(prev_compare, next_compare);
						it = new_it;
						to_compare = new_next;
					}
					if (to_compare != ite)
						to_compare++;
				}

				if (it != ite)
					it++;
				else
					break;
				if (it != ite && it != before_end)
				{
					to_compare = it;
					to_compare++;
				}
			}
		}

		template <class Compare>
		void sort(Compare comp)
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

			to_compare = it;
			to_compare++;
			while (it != before_end)
			{
				while (to_compare != ite)
				{
					if (!comp(*it, *to_compare))
					{
						new_it = to_compare.node();
						new_next = it.node();
						if (it.node()->next() == to_compare.node())
						{
							next_it = it.node();
							prev_compare = to_compare.node();
						}
						else
						{
							next_it = it.node()->next();
							prev_compare = to_compare.node()->previous();
						}
						prev_it = it.node()->previous();
						next_compare = to_compare.node()->next();
						if (it.node() == m_first)
							m_first = new_it;
						new_it->connect(prev_it, next_it);
						new_next->connect(prev_compare, next_compare);
						it = new_it;
						to_compare = new_next;
					}
					if (to_compare != ite)
						to_compare++;
				}

				if (it != ite)
					it++;
				else
					break;
				if (it != ite && it != before_end)
				{
					to_compare = it;
					to_compare++;
				}
			}
		}

		void reverse()
		{
			Node *end_copy = m_end;
			Node *begin_copy = m_begin;
			Node *prev_copy;

			m_begin = end_copy;
			m_begin->next(m_begin->previous());
			m_begin->previous(NULL);
			m_end = begin_copy;
			m_end->previous(m_end->next());
			m_end->next(NULL);

			m_first = m_begin->next();

			iterator it(m_first);
			iterator ite(m_end);

			while (it != ite)
			{
				prev_copy = it.node()->previous();
				it.node()->previous(it.node()->next());
				it.node()->next(prev_copy);
				it++;
			}
		}
	};

	template <class T, class Alloc>
	void swap(list<T, Alloc> &x, list<T, Alloc> &y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::list<T>::const_iterator it_lhs = lhs.begin();
		typename ft::list<T>::const_iterator ite_lhs = lhs.end();
		typename ft::list<T>::const_iterator it_rhs = rhs.begin();
		typename ft::list<T>::const_iterator ite_rhs = rhs.end();
		while (it_lhs != ite_lhs && it_rhs != ite_rhs)
		{
			if (*it_lhs != *it_rhs)
				return (false);
			it_lhs++;
			it_rhs++;
		}
		if (it_lhs == ite_lhs && it_rhs == ite_rhs)
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		typename ft::list<T>::const_iterator it_lhs = lhs.begin();
		typename ft::list<T>::const_iterator ite_lhs = lhs.end();
		typename ft::list<T>::const_iterator it_rhs = rhs.begin();
		typename ft::list<T>::const_iterator ite_rhs = rhs.end();

		while (it_lhs != ite_lhs)
		{
			if (it_rhs == ite_rhs || *it_rhs < *it_lhs)
				return false;
			else if (*it_lhs < *it_rhs)
				return true;
			++it_lhs;
			++it_rhs;
		}
		return (it_rhs != ite_rhs);
	}

	template <class T, class Alloc>
	bool operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

}; 
#endif