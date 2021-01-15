/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:45:09 by atetu             #+#    #+#             */
/*   Updated: 2021/01/15 18:22:53 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTTEST_HPP
# define LISTTEST_HPP

#include <memory>
#include <iostream>
#include "Iterator.hpp"
#include "list.hpp"
#include<list>

template <typename T>
class ListTest
{
    private:
        ft::list<T> m_ftList;
        std::list<T> m_list;

    public:
        ListTest<T>()
        {
           
        };
        
        ListTest(T* array, int size)
        {
           init(array, size);
        }

		void init(T* array, int size)
		{
			int i = 0;
           
            while (i < size)
            {
                m_ftList.push_back(array[i]);
				m_list.push_back(array[i]);
                i++;
            }
		}
        void
        print(const std::string& test, const std::string & result)
        {
            std::cout << "Test " << test << " : " << result << std::endl;
        }
        
		int checkIdenticalLists(std::string testName, int writeOption = 0)
        {
            typename ft::listIterator<T> itFtList = m_ftList.begin();
            typename ft::listIterator<T> iteFtList = m_ftList.end();
            typename std::list<T>::iterator itList = m_list.begin();
            typename std::list<T>::iterator iteList = m_list.end();

            while (itFtList != iteFtList) //&& itList != iteList)
            {
				if (writeOption)
					std::cout <<*itFtList << "-" << *itList << std::endl;
				if (*itFtList != *itList)
                {
					print(testName, "WRONG1");
                    return(0);
                }
                itFtList++;
                itList++;
            }
            if (itFtList != iteFtList || itList != iteList)
            {
                print(testName, "WRONG2");
                return(0);
            }
       		return(1);
        }


        #define CHECK_VALUES(apply, name)                     \
            if (m_ftList.apply() != m_list.apply())             \
                print(name, "WRONG");                       \
            else                                                \
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
        {}

        void push_back()
        {
            m_ftList.push_back(6);
          
            m_list.push_back(6);
			if(checkIdenticalLists("PUSH_BACK"))
				print("PUSH_BACK", "OK");
			// m_ftList.push_back(0);
            // m_list.push_back(0);
            // checkIdenticalLists("PUSH_BACK");
        }

        void pop_back()
        {
			int max;
            if (!(max = m_ftList.size() == m_list.size()))
                print("POP_BACK", "WRONG");
            else
            {
                while (max--)
                {
                    m_ftList.pop_back();
                    m_list.pop_back();
					if (!(checkIdenticalLists("POP_BACK")))
						return;
                }
				m_ftList.pop_back();
				m_list.pop_back();
			}
			if(checkIdenticalLists("POP_BACK"))
				print("POP_BACK", "OK");
        }
        
		#define INSERT(itFt, itList, val)			\
			m_ftList.insert(itFt, val);				\
			m_list.insert(itList, val);				\
			if (!(checkIdenticalLists("INSERT")))	\
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
			if (checkIdenticalLists("INSERT2", 1))
				print("INSERT2", "OK");	
		}

		#define ERASE(itFt, itList, nameTest, lastTest)		\
			m_ftList.erase(itFt);							\
			m_list.erase(itList);							\
			if (!lastTest)									\
				checkIdenticalLists("ERASE");				\
			else											\
			{												\
				if (checkIdenticalLists("ERASE", 1))		\
					print("ERASE", "OK");					\
			}
			
		void erase()
		{
			typename ft::listIterator<T> itFt = m_ftList.begin();
			typename std::list<T>::iterator itList = m_list.begin();
			typename ft::listIterator<T> iteFt = m_ftList.end();
			typename std::list<T>::iterator iteList = m_list.end();
			std::cout << "Op\n";
			ERASE(itFt, itList, "ERASE", 1);
		//	ERASE(iteFt, iteList, "ERASE", 1); //normal segfult;
		
			itFt = m_ftList.begin();// with std::list, when doind itList++ just after works
			itList = m_list.begin();
			++itFt;
			itList++;
			std::cout << "IT:"<< *itFt << std::endl;
			std::cout << "IT2: "<< *itList << std::endl;
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
			if (checkIdenticalLists("ERASE2", 1))
				print("ERASE2", "OK");
		}
	
		void clear()
		{
			int array[3] = {6, 7, 8};
			
			m_ftList.clear();
			m_list.clear();
			checkIdenticalLists("CLEAR", 0);
			
			init(array, 3);
			checkIdenticalLists("CLEAR", 1);
			m_ftList.clear();
			m_list.clear();
			if (checkIdenticalLists("CLEAR", 1))
				print("CLEAR", "OK");
		}
	
};
#endif