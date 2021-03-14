/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueueTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:52:45 by atetu             #+#    #+#             */
/*   Updated: 2021/03/14 16:59:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define QueueTest_HPP

#include <memory>
#include <iostream>

#include "Queue.hpp"
#include <queue>

bool mycomparison(int first, double second);

template <typename T>
class QueueTest
{
private:
	ft::queue<T> m_ftqueue;
	std::queue<T> m_queue;
	// ft::queue<const T> m_ftconstqueue;
	// std::queue<const T> m_constqueue;

public:
	QueueTest<T>()
	{
		ft::queue<T> ftv;
		std::queue<T> v;
		m_ftqueue = ftv;
		m_queue = v;

		if (checkIdenticalqueues("INIT_EMPTY"))
			print("INIT_EMPTY", "OK");
		// m_ftconstqueue(42, 4);
		// m_constqueue(42, 4);
	}

	static void
	print(const std::string &test, const std::string &result)
	{
		std::cout << "Test " << test << " : " << result << std::endl;
	}

	int checkIdenticalqueues(std::string testName, int writeOption = 0)
	{
		// typename ft::queue<T>::iterator itFtqueue = m_ftqueue.begin();
		// typename ft::queue<T>::iterator iteFtqueue = m_ftqueue.end();
		// typename std::queue<T>::iterator itqueue = m_queue.begin();
		// typename std::queue<T>::iterator itequeue = m_queue.end();

		// while(itqueue != itequeue)
		// {
		// 	std::cout << "queue: "<< *itqueue << std::endl;
		// 	itqueue++;
		// }
		// while(itFtqueue != iteFtqueue)
		// {
		// 	std::cout << "FT: "<< *itFtqueue << std::endl;
		// 	itFtqueue++;
		// }
		if (m_ftqueue.size() && m_queue.size())
		{
		//	std::cout << "SIZE: " << m_ftqueue.size() << "-" << m_queue.size() << std::endl;
			while (m_ftqueue.size()) //&& itqueue != itequeue)
			//  for (int i = 0; i < 3; i++)
			{
				if (writeOption)
					std::cout << m_ftqueue.back() << "-" << m_queue.back() << std::endl;
				if (m_ftqueue.back() != m_queue.back())
				{
					print(testName, "WRONG1");
					return (0);
				}
				m_ftqueue.pop();
				m_queue.pop();
			}

			if (m_ftqueue.size() != m_queue.size())
			{
				print(testName, "WRONG2");
				return (0);
			}
		}
		else if (m_ftqueue.size() != m_queue.size())
		{
			// std::cout << "FT queue size : " << m_ftqueue.size() << std::endl;
			// std::cout << "queue size : " << m_queue.size() << std::endl;
			print(testName, "WRONG3");
			return (0);
		}
		return (1);
	}

	template <typename Y>
	static int checkIdenticalqueues(std::queue<Y> &x, ft::queue<Y> &y, std::string testName, int writeOption = 0)
	{

		if (x.size() && y.size())
		{
			// std::cout << "SIZE: " << y.size() << "-" << x.size() << std::endl;
			while (y.size()) //&& itqueue != itequeue)
			//  for (int i = 0; i < 3; i++)
			{
				if (writeOption)
					std::cout << y.back() << "-" << x.back() << std::endl;
				if (y.back() != x.back())
				{
					print(testName, "WRONG1");
					return (0);
				}
				y.pop();
				x.pop();
			}

			if (y.size() != x.size())
			{
				print(testName, "WRONG2");
				return (0);
			}
		}
		else if (y.size() != x.size())
		{
			std::cout << "FT queue size : " << y.size() << std::endl;
			std::cout << "queue size : " << x.size() << std::endl;
			print(testName, "WRONG3");
			return (0);
		}
		return (1);
	}

	void back()
	{
		if (m_ftqueue.back() == m_queue.back())
			print("BACK", "OK");
		else
			print("BACK", "WRONG");
	}

	// void push()
	// {
	//     m_ftqueue.push(6);

	//     m_queue.push(6);
	// 	if(checkIdenticalqueues("PUSH", 1))
	// 		print("PUSH", "OK");
	// }

	void push_back_notest()
	{
		m_ftqueue.push(6);
		m_queue.push(6);
		m_ftqueue.push(10);
		m_queue.push(10);
	}

	void empty()
	{
		if (m_ftqueue.empty() == m_queue.empty())
			print("EMPTY", "OK");
		else
			print("EMPTY", "WRONG");
	}

	void size()
	{
		// std::cout << "FT size: " << m_ftqueue.size() << std::endl;
		// std::cout << "Q size: " << m_queue.size() << std::endl;
		if (m_ftqueue.size() == m_queue.size())
			print("SIZE", "OK");
		else
			print("SIZE", "WRONG");
	}

	void pop()
	{
		m_ftqueue.pop();
		m_queue.pop();
		if (checkIdenticalqueues("POP", 1))
			print("POP", "OK");
		size_t s = m_ftqueue.size();
		// std::cout << "size: " << s << "\n"
		// 		  << std::flush;
		while (s)
		{
			m_ftqueue.pop();
			m_queue.pop();
			if (checkIdenticalqueues("POP", 1))
				print("POP", "OK");
			s = m_ftqueue.size();
		}
	}

	void push()
	{
		m_ftqueue.push(6);
		m_queue.push(6);
		if (checkIdenticalqueues("PUSH", 1))
			print("PUSH", "OK");
		m_ftqueue.push(6);
		m_queue.push(6);

		if (checkIdenticalqueues("PUSH", 1))
			print("PUSH", "OK");
	}

	ft::queue<T> set_ft_second(int option)
	{
		ft::queue<int> ft_second;
		ft_second.push(6);
		ft_second.push(10);
		if (option == 1)
			return (ft_second);
		ft_second.push(10);
		ft_second.push(8);
		ft_second.push(6);
		if (option == 2)
			ft_second.push(0);
		if (option == 3)
			ft_second.push(50);
		ft_second.push(9);
		ft_second.push(20);
		if (option >= 2 && option <= 4)
			return (ft_second);
		ft_second.push(30);
		return (ft_second);
	}

	std::queue<int> set_second(int option)
	{
		std::queue<int> ft_second;
		ft_second.push(6);
		ft_second.push(10);
		if (option == 1)
			return (ft_second);
		ft_second.push(10);
		ft_second.push(8);
		ft_second.push(6);
		if (option == 2)
			ft_second.push(0);
		if (option == 3)
			ft_second.push(50);
		ft_second.push(9);
		ft_second.push(20);
		if (option >= 2 && option <= 4)
			return (ft_second);
		ft_second.push(30);
		return (ft_second);
	}

	void equal()
	{
		// std::cout << "\nSECOND\n\n";
		ft::queue<int> ft_second;
		std::queue<int> second;

		for (int i = 0; i < 5; i++)
		{
		// int i = 0;
			// std::cout << "\nSTART\n\n";
		
			if ((m_ftqueue == set_ft_second(i)) != (m_queue == set_second(i)))
			{
				// std::cout << "I: " << i << std::endl;
				// std::cout << "my result: " << (m_ftqueue < ft_second) << std::endl;
				// std::cout << "expected result: " << (m_queue < second) << std::endl;
				print("EQUAL", "WRONG");
				return;
			}
		}
		print("EQUAL", "OK");
	}

	void not_equal()
	{
		ft::queue<int> ft_second;
		std::queue<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftqueue != set_ft_second(i)) != (m_queue != set_second(i)))
			{
				print("NOT EQUAL", "WRONG");
				return;
			}
		}
		print("NOT EQUAL", "OK");
	}

	void less()
	{
		ft::queue<int> ft_second;
		std::queue<int> second;

		for (int i = 0; i < 5; i++)
		{
		
			// std::cout << "START\n";
			// ft::deque<int>::const_iterator it = ft_second.begin();
			// std::cout << "second: " << *it << std::endl;
			// ft_second.pop();
			// std::cout << "second: " << ft_second.back() << std::endl;
			if ((m_ftqueue < set_ft_second(i)) != (m_queue < set_second(i)))
			{
				// std::cout << "I: " << i << std::endl;
				// std::cout << "my result: " << (m_ftqueue < ft_second) << std::endl;
				// std::cout << "expected result: " << (m_queue < second) << std::endl;
				// print("LESS", "WRONG");
				return;
			}
		}
		print("LESS", "OK");
	}

	void less_or_equal()
	{
		ft::queue<int> ft_second;
		std::queue<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftqueue <= set_ft_second(i)) != (m_queue <= set_second(i)))
			{
				print("LESS OR EQUAL", "WRONG");
				return;
			}
		}
		print("LESS_OR_EQUAL", "OK");
	}

	void greater()
	{
		ft::queue<int> ft_second;
		std::queue<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftqueue > set_ft_second(i)) != (m_queue > set_second(i)))
			{
				print("GREATER", "WRONG");
				return;
			}
		}
		print("GREATER", "OK");
	}

	void greater_or_equal()
	{
		ft::queue<int> ft_second;
		std::queue<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftqueue >= set_ft_second(i)) != (m_queue >= set_second(i)))
			{
				print("GREATER OR EQUAL", "WRONG");
				return;
			}
		}
		print("GREATER OR EQUAL", "OK");
	}
};