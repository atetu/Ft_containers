/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:45:09 by atetu             #+#    #+#             */
/*   Updated: 2021/03/16 14:57:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTTEST_HPP
#define LISTTEST_HPP

#include <memory>
#include <iostream>
#include "../List.hpp"
#include <list>

bool mycomparison(int first, double second);

template <typename T>
class ListTest
{
private:
	ft::list<T> m_ftList;
	std::list<T> m_list;

public:
	ListTest<T>()
	{
	}

	ListTest(T *array, int size)
	{
		init(array, size);
	}

	ListTest(T val, int size)
	{
		ft::list<T> ftl(size, val);
		m_ftList = ftl;
		std::list<T> l(size, val);
		m_list = l;
	}

	ListTest(T val, int size, int start, int end)
	{
		ft::list<T> ft_copy(size, val);
		typename ft::list<T>::iterator it = ft_copy.begin();
		typename ft::list<T>::iterator ite = ft_copy.end();
		typename ft::list<T>::iterator ft_first;
		typename ft::list<T>::iterator ft_last;
		std::list<T> copy(size, val);
		typename std::list<T>::iterator itl = copy.begin();
		typename std::list<T>::iterator first;
		typename std::list<T>::iterator last;
		for (int i = 0; i < start; i++)
		{
			it++;
			itl++;
		}
		ft_first = it;
		first = itl;
		for (; start < end; start++)
		{
			it++;
			itl++;
		}
		ft_last = it;
		last = itl;
		ft::list<int> ftl(ft_first, ft_last);
		m_ftList = ftl;

		std::list<int> l(first, last);
		m_list = l;
	}

	ListTest(T val, int size, std::string c)
	{
		(void)c;
		ft::list<T> ft_copy(size, val);
		typename ft::list<T>::iterator it = ft_copy.begin();
		typename ft::list<T>::iterator ite = ft_copy.end();

		std::list<T> copy(size, val);
		ft::list<int> ftl(ft_copy);
		m_ftList = ftl;

		std::list<int> l(copy);
		m_list = l;
	}
	
	~ListTest()
	{
	}

	void init(T *array, int size)
	{
		int i = 0;

		while (i < size)
		{
			m_ftList.push_back(array[i]);
			m_list.push_back(array[i]);
			i++;
		}
	}

	static void
	print(const std::string &test, const std::string &result)
	{
		std::cout << "Test " << test << " : " << result << std::endl;
	}

	int checkIdenticalLists(std::string testName, int writeOption = 0)
	{
		typename ft::listIterator<T> itFtList = m_ftList.begin();
		typename ft::listIterator<T> iteFtList = m_ftList.end();
		typename std::list<T>::iterator itList = m_list.begin();
		typename std::list<T>::iterator iteList = m_list.end();

		while (itFtList != iteFtList && itList != iteList)
		{
			if (writeOption)
				std::cout << *itFtList << "-" << *itList << std::endl;
			if (*itFtList != *itList)
			{
				print(testName, "WRONG1");
				return (0);
			}
			itFtList++;
			itList++;
		}
		if (itFtList != iteFtList || itList != iteList)
		{
			print(testName, "WRONG2");
			return (0);
		}
		return (1);
	}

	template <typename Y>
	static int checkIdenticalLists(std::list<Y> &x, ft::list<Y> &y, std::string testName, int writeOption = 0)
	{
		typename std::list<Y>::iterator itList = x.begin();
		typename std::list<Y>::iterator iteList = x.end();
		typename ft::listIterator<Y> itFtList = y.begin();
		typename ft::listIterator<Y> iteFtList = y.end();

		while (itFtList != iteFtList && itList != iteList)
		{
			if (writeOption)
				std::cout << *itFtList << "-" << *itList << std::endl;
			if (*itFtList != *itList)
			{
				print(testName, "WRONG1");
				return (0);
			}
			itFtList++;
			itList++;
		}
		if (itFtList != iteFtList || itList != iteList)
		{
			print(testName, "WRONG2");
			return (0);
		}
		return (1);
	}

#define CHECK_VALUES(apply, name)           \
	if (m_ftList.apply() != m_list.apply()) \
		print(name, "WRONG");               \
	else                                    \
		print(name, "OK");

	void begin()
	{
		if ((*m_ftList.begin()) != (*m_list.begin()))
			print("BEGIN", "WRONG");
		else
			print("BEGIN", "OK");
	}

	void end()
	{
		typename ft::listIterator<T> itFT = m_ftList.end();
		typename std::list<T>::iterator itList = m_list.end();
		if ((*(--itFT)) != (*(--itList)))
			print("END", "WRONG");
		else
			print("END", "OK");
	}

	void front()
	{
		CHECK_VALUES(front, "FRONT");
	}

	void back()
	{
		CHECK_VALUES(back, "BACK");
	}

	void empty()
	{
		CHECK_VALUES(empty, "EMPTY");
	}

	void size()
	{
		CHECK_VALUES(size, "SIZE");
	}

	void assign()
	{
	}

	void push_front()
	{
		m_ftList.push_front(50);
		m_list.push_front(50);
		if (checkIdenticalLists("PUSH_FRONT"))
			print("PUSH_FRONT", "OK");
	}

	void push_back()
	{
		m_ftList.push_back(6);

		m_list.push_back(6);
		if (checkIdenticalLists("PUSH_BACK"))
			print("PUSH_BACK", "OK");
	}

	void pop_back()
	{
		size_t max;
		if (!((max = m_ftList.size()) == m_list.size()))
			print("POP_BACK", "WRONG");
		else
		{
			for (int i = 0; i < 2; i++)
			{
				m_ftList.pop_back();
				m_list.pop_back();
				if (!(checkIdenticalLists("POP_BACK")))
					return;
			}
		}
		if (checkIdenticalLists("POP_BACK"))
			print("POP_BACK", "OK");
	}

	void pop_front()
	{
		size_t max;
		if (!((max = m_ftList.size()) == m_list.size()))
			print("POP_FRONT", "WRONG");
		else
		{
			for (int i = 0; i < 2; i++)
			{
				m_ftList.pop_back();
				m_list.pop_back();
				if (!(checkIdenticalLists("POP_FRONT")))
					return;
			}
		}
		if (checkIdenticalLists("POP_FRONT"))
			print("POP_FRONT", "OK");
	}

#define INSERT(itFt, itList, val)         \
	m_ftList.insert(itFt, val);           \
	m_list.insert(itList, val);           \
	if (!(checkIdenticalLists("INSERT"))) \
		return;

	void insert()
	{
		typename ft::listIterator<T> itFt = m_ftList.begin();
		typename ft::listIterator<T> iteFt = m_ftList.end();
		typename std::list<T>::iterator itList = m_list.begin();
		typename std::list<T>::iterator iteList = m_list.end();

		INSERT(itFt, itList, 42);
		INSERT(iteFt, iteList, 38);

		++itFt;
		++itList;
		INSERT(itFt, itList, 38);
		print("INSERT", "OK");
	}

	void insert2()
	{
		std::list<T> list;
		list.push_back(10);
		list.push_back(11);

		ft::list<T> ft_list;
		ft_list.push_back(10);
		ft_list.push_back(11);

		typename ft::listIterator<T> itFt = m_ftList.begin();
		typename std::list<T>::iterator itList = m_list.begin();
		m_ftList.insert(itFt, ft_list.begin(), ft_list.end());
		m_list.insert(itList, list.begin(), list.end());
		itFt++;
		itList++;
		m_ftList.insert(itFt, ft_list.begin(), ft_list.end());
		m_list.insert(itList, list.begin(), list.end());
		if (checkIdenticalLists("INSERT2"))
			print("INSERT2", "OK");
	}

#define ERASE(itFt, itList, nameTest, lastTest) \
	m_ftList.erase(itFt);                       \
	m_list.erase(itList);                       \
	if (!lastTest)                              \
		checkIdenticalLists("ERASE");           \
	else                                        \
	{                                           \
		if (checkIdenticalLists("ERASE"))       \
			print("ERASE", "OK");               \
	}

	void erase()
	{
		typename ft::listIterator<T> itFt = m_ftList.begin();
		typename std::list<T>::iterator itList = m_list.begin();

		ERASE(itFt, itList, "ERASE", 1);

		itFt = m_ftList.begin();
		itList = m_list.begin();
		++itFt;
		itList++;
		ERASE(itFt, itList, "ERASE", 1);
	}

	void erase2()
	{
		typename ft::listIterator<T> itFt = m_ftList.begin();
		typename std::list<T>::iterator itList = m_list.begin();
		typename ft::listIterator<T> iteFt = m_ftList.end();
		typename std::list<T>::iterator iteList = m_list.end();
		itFt++;
		itList++;
		m_ftList.erase(itFt, iteFt);
		m_list.erase(itList, iteList);
		if (checkIdenticalLists("ERASE2"))
			print("ERASE2", "OK");
	}

	void resize()
	{
		m_ftList.resize(2);
		m_list.resize(2);
	}

	void clear()
	{
		int array[3] = {6, 7, 8};

		m_ftList.clear();
		m_list.clear();
		checkIdenticalLists("CLEAR");

		init(array, 3);
		checkIdenticalLists("CLEAR");
		m_ftList.clear();
		m_list.clear();
		if (checkIdenticalLists("CLEAR"))
			print("CLEAR", "OK");
	}
	void splice()
	{
		int array[3] = {6, 7, 8};
		init(array, 3);

		ft::list<int> m_other;
		std::list<int> other;
		for (int i = 0; i < 3; i++)
		{
			m_other.push_back(9);
			other.push_back(9);
		}

		ft::listIterator<T> it = m_ftList.begin();
		ft::listIterator<T> ite = m_ftList.end();
		while (it != ite)
			it++;

		ft::listIterator<T> itt = m_ftList.begin();
		typename std::list<T>::iterator ipp = m_list.begin();

		m_ftList.splice(itt, m_other);
		m_list.splice(ipp, other);

		if (checkIdenticalLists("SPLICE 1"))
			print("SPLICE 1", "OK");

		ft::list<int> m_newOther;
		std::list<int> newOther;
		for (int i = 0; i < 3; i++)
		{
			m_newOther.push_back(3);
			newOther.push_back(3);
		}
		m_newOther.push_back(4);
		newOther.push_back(4);
		ft::listIterator<T> itOther = m_newOther.begin();
		typename std::list<T>::iterator ipOther = newOther.begin();
		for (int i = 0; i < 2; i++)
		{
			itOther++;
			ipOther++;
		}
		m_ftList.splice(itt, m_newOther, itOther);
		m_list.splice(ipp, newOther, ipOther);

		if (checkIdenticalLists("SPLICE 2"))
			print("SPLICE 2", "OK");

		ft::list<int> m_newOther2;
		std::list<int> newOther2;
		for (int i = 0; i < 3; i++)
		{
			m_newOther2.push_back(5);
			newOther2.push_back(5);
		}
		m_newOther2.push_back(7);
		newOther2.push_back(7);
		ft::listIterator<T> itOther2 = m_newOther2.begin();
		typename std::list<T>::iterator ipOther2 = newOther2.begin();
		for (int i = 0; i < 2; i++)
		{
			itOther2++;
			ipOther2++;
		}
		m_ftList.splice(itt, m_newOther2, itOther2);
		m_list.splice(ipp, newOther2, ipOther2);

		if (checkIdenticalLists("SPLICE 3"))
			print("SPLICE 3", "OK");
	}

	void sort()
	{
		m_list.push_back(3);
		m_list.push_back(2);
		m_list.push_back(5);
		m_list.sort();

		m_ftList.push_back(3);
		m_ftList.push_back(2);
		m_ftList.push_back(5);
		m_ftList.sort();

		if (checkIdenticalLists("SORT"))
			print("SORT", "OK");

		m_list.push_back(54);
		m_list.push_back(4);
		m_list.push_back(10);
		m_list.sort(mycomparison);

		m_ftList.push_back(54);
		m_ftList.push_back(4);
		m_ftList.push_back(10);
		m_ftList.sort(mycomparison);

		if (checkIdenticalLists("SORT2"))
			print("SORT2", "OK");
	}

	void merge()
	{
		std::list<int> second;
		second.push_back(6);
		second.push_back(1);
		second.push_back(4);
		second.sort();
		m_list.merge(second);

		ft::list<int> ft_second;
		ft_second.push_back(6);
		ft_second.push_back(1);
		ft_second.push_back(4);
		ft_second.sort();

		m_ftList.merge(ft_second);

		if (checkIdenticalLists("MERGE"))
			print("MERGE", "OK");

		std::list<int> second2;
		ft::list<int> ft_second2;
		second2.push_back(2);
		ft_second2.push_back(2);
		m_list.merge(second2, mycomparison);
		m_ftList.merge(ft_second2, mycomparison);

		if (checkIdenticalLists("MERGE2"))
			print("MERGE2", "OK");
	}

	void reverse()
	{
		m_ftList.reverse();
		m_list.reverse();
		if (checkIdenticalLists("REVERSE"))
			print("REVERSE", "OK");
	}

	void rendIncrement()
	{
		typename ft::list<T>::reverse_iterator ft_r = m_ftList.rbegin();
		typename ft::list<T>::reverse_iterator ft_re = m_ftList.rend();
		typename std::list<T>::reverse_iterator r = m_list.rbegin();
		typename std::list<T>::reverse_iterator re = m_list.rend();

		while (ft_r != ft_re && r != re)
		{
			if (*ft_r != *r)
			{
				print("REND", "WRONG");
				return;
			}
			ft_r++;
			r++;
		}
		if (ft_r == ft_re && r == re)
			print("REND", "OK");
		else
			print("REND", "WRONG");
	}

	void maxSize()
	{
		if (m_ftList.max_size() == m_list.max_size())
			print("MAX SIZE", "OK");
		else
			print("MAX SIZE", "WRONG");
	}

	void reverse_relational()
	{
		typedef ft::list<int>::iterator iter_type;
		ft::ReverseIterator<iter_type> ftm = m_ftList.rbegin();
		ft::ReverseIterator<iter_type> ftbis = ftm;
		ft::ReverseIterator<iter_type> ft2 = ftm;
		ft2++;

		std::list<int>::reverse_iterator m = m_list.rbegin();
		std::list<int>::reverse_iterator mbis = m;
		std::list<int>::reverse_iterator m2 = m;
		m2++;

		if ((ftm == ftbis) == (m == mbis) && (ftm == ft2) == (m == m2))
			print("REVERSE ==", "OK");

		if ((ftm != ftbis) == (m != mbis) && (ftm != ft2) == (m != m2))
			print("REVERSE !=", "OK");
	}
};
#endif