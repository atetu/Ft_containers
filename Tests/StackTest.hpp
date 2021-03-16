/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:52:45 by atetu             #+#    #+#             */
/*   Updated: 2021/03/16 14:57:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define StackTest_HPP

#include <memory>
#include <iostream>

#include "../Stack.hpp"
#include <stack>

bool mycomparison(int first, double second);

template <typename T>
class StackTest
{
private:
	ft::stack<T> m_ftstack;
	std::stack<T> m_stack;

public:
	StackTest<T>()
	{
		ft::stack<T> ftv;
		std::stack<T> v;
		m_ftstack = ftv;
		m_stack = v;

		if (checkIdenticalstacks("INIT_EMPTY"))
			print("INIT_EMPTY", "OK");
	}

	static void
	print(const std::string &test, const std::string &result)
	{
		std::cout << "Test " << test << " : " << result << std::endl;
	}

	int checkIdenticalstacks(std::string testName)
	{
		if (m_ftstack.size() && m_stack.size())
		{
			while (m_ftstack.size() && m_stack.size())
			{
				if (m_ftstack.top() != m_stack.top())
				{
					print(testName, "WRONG1");
					return (0);
				}
				m_ftstack.pop();
				m_stack.pop();
			}
			if (m_ftstack.size() != m_stack.size())
			{
				print(testName, "WRONG2");
				return (0);
			}
		}
		else if (m_ftstack.size() != m_stack.size())
		{
			print(testName, "WRONG3");
			return (0);
		}
		return (1);
	}

	template <typename Y>
	static int checkIdenticalstacks(std::stack<Y> &x, ft::stack<Y> &y, std::string testName, int writeOption = 0)
	{

		if (x.size() && y.size())
		{
			while (x.size() && y.size())
			{
				if (writeOption)
					std::cout << y.top() << "-" << x.top() << std::endl;
				if (y.top() != x.top())
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
			print(testName, "WRONG3");
			return (0);
		}
		return (1);
	}

	void top()
	{
		if (m_ftstack.top() == m_stack.top())
			print("TOP", "OK");
		else
			print("TOP", "WRONG");
	}

	void push_back_notest()
	{
		m_ftstack.push(6);
		m_stack.push(6);
		m_ftstack.push(10);
		m_stack.push(10);
	}

	void empty()
	{
		if (m_ftstack.empty() == m_stack.empty())
			print("EMPTY", "OK");
		else
			print("EMPTY", "WRONG");
	}

	void size()
	{
		if (m_ftstack.size() == m_stack.size())
			print("SIZE", "OK");
		else
			print("SIZE", "WRONG");
	}

	void pop()
	{
		m_ftstack.pop();
		m_stack.pop();
		if (checkIdenticalstacks("POP"))
			print("POP", "OK");
		size_t s = m_ftstack.size();

		while (s)
		{
			m_ftstack.pop();
			m_stack.pop();
			if (checkIdenticalstacks("POP"))
				print("POP", "OK");
			s = m_ftstack.size();
		}
	}

	void push()
	{
		m_ftstack.push(6);
		m_stack.push(6);
		if (checkIdenticalstacks("PUSH"))
			print("PUSH", "OK");
	}

	ft::stack<T> set_ft_second(int option)
	{
		(void)option;
		ft::stack<int> ft_second;
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

	std::stack<int> set_second(int option)
	{
		std::stack<int> second;
		second.push(6);
		second.push(10);
		if (option == 1)
			return (second);
		second.push(10);
		second.push(8);
		second.push(6);
		if (option == 2)
			second.push(0);
		if (option == 3)
			second.push(50);
		second.push(9);
		second.push(20);
		if (option >= 2 && option <= 4)
			return (second);
		second.push(30);
		return (second);
	}

	void equal()
	{
		ft::stack<int> ft_second;
		std::stack<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftstack == set_ft_second(i)) != (m_stack == set_second(i)))
			{
				print("EQUAL", "WRONG");
				return;
			}
		}
		print("EQUAL", "OK");
	}

	void not_equal()
	{
		ft::stack<int> ft_second;
		std::stack<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftstack != set_ft_second(i)) != (m_stack != set_second(i)))
			{
				print("NOT EQUAL", "WRONG");
				return;
			}
		}
		print("NOT EQUAL", "OK");
	}

	void less()
	{
		ft::stack<int> ft_second;
		std::stack<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftstack < set_ft_second(i)) != (m_stack < set_second(i)))
			{
				print("LESS", "WRONG");
				return;
			}
		}
		print("LESS", "OK");
	}

	void less_or_equal()
	{
		ft::stack<int> ft_second;
		std::stack<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftstack <= set_ft_second(i)) != (m_stack <= set_second(i)))
			{
				print("LESS OR EQUAL", "WRONG");
				return;
			}
		}
		print("LESS_OR_EQUAL", "OK");
	}

	void greater()
	{
		ft::stack<int> ft_second;
		std::stack<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftstack > set_ft_second(i)) != (m_stack > set_second(i)))
			{
				print("GREATER", "WRONG");
				return;
			}
		}
		print("GREATER", "OK");
	}

	void greater_or_equal()
	{
		ft::stack<int> ft_second;
		std::stack<int> second;

		for (int i = 0; i < 5; i++)
		{
			if ((m_ftstack >= set_ft_second(i)) != (m_stack >= set_second(i)))
			{
				print("GREATER OR EQUAL", "WRONG");
				return;
			}
		}
		print("GREATER OR EQUAL", "OK");
	}
};