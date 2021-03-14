/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:52:45 by atetu             #+#    #+#             */
/*   Updated: 2021/03/12 21:58:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define DequeTest_HPP

#include <memory>
#include <iostream>

#include "Deque.hpp"
#include "Iterator.hpp"
#include<deque>

bool mycomparison (int first, double second);

template <typename T>
class DequeTest
{
    private:
     	ft::deque<T> m_ftdeque;
        std::deque<T> m_deque;
		// ft::deque<const T> m_ftconstdeque;
        // std::deque<const T> m_constdeque;

    public:
        DequeTest<T>()
        {
			ft::deque<T> ftv;
			std::deque<T>v;
			m_ftdeque = ftv;
			m_deque = v;
			if(checkIdenticaldeques("INIT_EMPTY"))
				print("INIT_EMPTY", "OK");
			// m_ftconstdeque(42, 4);
			// m_constdeque(42, 4);
        }
        
       		
		DequeTest(T val, int size)
		{
			ft::deque<T> ftl(size, val);
			// m_ftdeque = ftl;
			std::deque<T> l(size, val);
			// m_deque = l;
			// if(checkIdenticaldeques("INIT_SIZE_VAL", 1))
			// 	print("INIT_SIZE_VAL", "OK");
		}
        
		DequeTest(T val, int size, int start, int end)
		{
			// std::cout << "start\n" << std::flush;
			ft::deque<T> ft_copy(size, val);
			// std::cout << "start\n" << std::flush;
			typename ft::deque<T>::iterator it = ft_copy.begin();
			typename ft::deque<T>::iterator ite = ft_copy.end();
			typename ft::deque<T>::iterator ft_first;
			typename ft::deque<T>::iterator ft_last;
			std::deque<T> copy(size, val);
			// std::cout << "middle\n" << std::flush;
			typename std::deque<T>::iterator itl = copy.begin();
	//		typename std::deque<T>::iterator itel = copy.end();
			typename std::deque<T>::iterator first;
			typename std::deque<T>::iterator last;
			for(int i = 0 ; i < start; i++)
			{
				it++;
				itl++;
			}
			std::cout << "start\n" << std::flush;
			ft_first = it;
			first = itl;
			for(; start < end; start++)
			{
				it++;
				itl++;
			}
			ft_last = it;
			last = itl;
			// std::cout << "middle\n" << std::flush;
			ft::deque<int> ftl(ft_first, ft_last);
			m_ftdeque = ftl;
			
			std::deque<int> l(first, last);
			m_deque = l;
			// std::cout << "end\n" << std::flush;
			if(checkIdenticaldeques("INIT_INPUT_ITERATOR_FIRST_INPUT_ITERATOR_LAST", 1))
				print("INIT_INPUT_ITERATOR_FIRST_INPUT_ITERATOR_LAST", "OK");
		}
		
		DequeTest(T val, int size, std::string c)
		{
			(void)c;
			ft::deque<T> ft_copy(size, val);
			typename ft::deque<T>::iterator it = ft_copy.begin();
			typename ft::deque<T>::iterator ite = ft_copy.end();
		
			std::deque<T> copy(size, val);
		//	typename std::deque<T>::iterator itl = copy.begin();
		//	typename std::deque<T>::iterator itel = copy.end();
			
			ft::deque<int> ftl(ft_copy);
			m_ftdeque = ftl;
					
			std::deque<int> l(copy);
			m_deque = l;
			
			if(checkIdenticaldeques("INIT_COPY"))
				print("INIT_COPY", "OK");
		}
		
		~DequeTest()
		{
			
		}
        
		static void
        print(const std::string& test, const std::string & result)
        {
            std::cout << "Test " << test << " : " << result << std::endl;
        }
        
		int checkIdenticaldeques(std::string testName, int writeOption = 0)
        {
            typename ft::deque<T>::iterator itFtdeque = m_ftdeque.begin();
            typename ft::deque<T>::iterator iteFtdeque = m_ftdeque.end();
            typename std::deque<T>::iterator itdeque = m_deque.begin();
            typename std::deque<T>::iterator itedeque = m_deque.end();

			// while(itdeque != itedeque)
			// {
			// 	std::cout << "deque: "<< *itdeque << std::endl;
			// 	itdeque++;
			// }
			// while(itFtdeque != iteFtdeque)
			// {
			// 	std::cout << "FT: "<< *itFtdeque << std::endl;
			// 	itFtdeque++;
			// }
			if (m_ftdeque.size() && m_deque.size())
			{
				std::cout << "SIZE: " << m_ftdeque.size() << "-" << m_deque.size() << std::endl;
				while (itFtdeque != iteFtdeque) //&& itdeque != itedeque)
				//  for (int i = 0; i < 3; i++)
				{
					if (writeOption)
						std::cout <<*itFtdeque << "-" << *itdeque << std::endl;
					if (*itFtdeque != *itdeque)
					{
						print(testName, "WRONG1");
						return(0);
					}
					itFtdeque++;
					itdeque++;
				}
				
				if (itFtdeque != iteFtdeque || itdeque != itedeque)
				{
					print(testName, "WRONG2");
					return(0);
				}
			}
			else if (m_ftdeque.size() != m_deque.size())
			{
				std::cout << "FT deque size : " << m_ftdeque.size() << std::endl;
					std::cout << "deque size : " << m_deque.size() << std::endl;
				print(testName, "WRONG3");
				return(0);
			}
       		return(1);
        }

		template <typename Y>
		static int checkIdenticaldeques(std::deque<Y> &x, ft::deque<Y> &y, std::string testName, int writeOption = 0)
        {
            typename std::deque<Y>::iterator itdeque = x.begin();
            typename std::deque<Y>::iterator itedeque = x.end();
			typename ft::Iterator<Y> itFtdeque = y.begin();
            typename ft::Iterator<Y> iteFtdeque = y.end();
           
			std::cout << "SIZE: " << y.size() << "-" << x.size() << std::endl;
            while (itFtdeque != iteFtdeque) //&& itdeque != itedeque)
            {
				if (writeOption)
					std::cout <<*itFtdeque << "-" << *itdeque << std::endl;
				if (*itFtdeque != *itdeque)
                {
					print(testName, "WRONG1");
                    return(0);
                }
                itFtdeque++;
                itdeque++;
            }
            if (itFtdeque != iteFtdeque || itdeque != itedeque)
            {
                print(testName, "WRONG2");
                return(0);
            }
       		return(1);
        }

        void push_back()
        {
            m_ftdeque.push_back(6);
          
            m_deque.push_back(6);
			if(checkIdenticaldeques("PUSH_BACK", 1))
				print("PUSH_BACK", "OK");
        }

		void push_front()
        {
            m_ftdeque.push_front(6);
            m_deque.push_front(6);
			if(checkIdenticaldeques("PUSH_FRONT", 1))
				print("PUSH_FRONT", "OK");
			m_ftdeque.push_front(6);
            m_deque.push_front(6);
			
			if(checkIdenticaldeques("PUSH_FRONT", 1))
				print("PUSH_FRONT", "OK");
        }

        void pop_back()
        {
			int max;
            if (!((max = m_ftdeque.size()) == m_deque.size()))
                print("POP_BACK", "WRONG");
            else
            {
				for (int i = 0; i < max; i++)
                {
					std::cout << "I: " << i << std::endl;
				    m_ftdeque.pop_back();
                    m_deque.pop_back();
					if (!(checkIdenticaldeques("POP_BACK", 1)))
						return;
					
                }
			}
			if(checkIdenticaldeques("POP_BACK", 1))
				print("POP_BACK", "OK");
        }
		
		void pop_front()
        {
			int max;
            if (!((max = m_ftdeque.size()) == m_deque.size()))
                print("POP_FRONT", "WRONG");
            else
            {
				for (int i = 0; i < 2; i++)
				{
				    m_ftdeque.pop_front();
                    m_deque.pop_front();
					if (!(checkIdenticaldeques("POP_FRONT")))
						return;
                }
			}
			// m_ftdeque.pop_front();
            // m_deque.pop_front();
			// m_ftdeque.pop_front();
            // //m_deque.pop_front();
			if(checkIdenticaldeques("POP_FRONT"))
				print("POP_FRONT", "OK");
        }
		
};