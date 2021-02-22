/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:45:09 by atetu             #+#    #+#             */
/*   Updated: 2021/02/22 14:59:00 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTTEST_HPP
# define LISTTEST_HPP

#include <memory>
#include <iostream>
#include "Iterator.hpp"
#include "list.hpp"
#include<list>

bool mycomparison (int first, double second);

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
        
		static void
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

		template <typename Y>
		static int checkIdenticalLists(std::list<Y> &x, ft::list<Y> &y, std::string testName, int writeOption = 0)
        {
            typename std::list<Y>::iterator itList = x.begin();
            typename std::list<Y>::iterator iteList = x.end();
			typename ft::listIterator<Y> itFtList = y.begin();
            typename ft::listIterator<Y> iteFtList = y.end();
           

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
		
		// void swap(ft::list & x)
		// {
				
		// }
		
		void resize()
		{
			m_ftList.resize(2);
			m_list.resize(2);
			if (checkIdenticalLists("RESIZE", 1))
				print("RESIZE", "OK");
			m_ftList.resize(6);
			m_list.resize(6);
			if (checkIdenticalLists("RESIZE 2", 1))
				print("RESIZE 2", "OK");
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
		void splice()
		{
			int array[3] = {6, 7, 8};
			init(array, 3);
			
			ft::list<int> m_other;
			std::list<int> other;
			for (int i = 0 ; i < 3; i++)
			{
				m_other.push_back(9);
				other.push_back(9);
			}
			
			ft::listIterator<T> it= m_ftList.begin();
			ft::listIterator<T> ite = m_ftList.end();
			while (it != ite)
				it++;
		
			ft::listIterator<T> itt = m_ftList.begin();
			typename std::list<T>::iterator ipp = m_list.begin();
		//	ipp++;
		//	itt++;
			m_ftList.splice(itt, m_other);
			m_list.splice(ipp, other);
			
			// typename std::list<T>::iterator lit= m_list.begin();
			// typename std::list<T>::iterator lite = m_list.end();
			// while (lit != lite)
			// {
			// 	printf("%d\n", *lit);
			// 	lit++;
			// }
			// ft::listIterator<T> litnew= m_ftList.begin();
			// ft::listIterator<T> litenew = m_ftList.end();
			// while (litnew != litenew)
			// {
			// 	printf("%d\n", *litnew);
			// 	litnew++;
			// }
			if (checkIdenticalLists("SPLICE 1", 1))
				print("SPLICE 1", "OK");
			
			ft::list<int> m_newOther;
			std::list<int> newOther;
			for (int i = 0 ; i < 3; i++)
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
			
			// typename std::list<T>::iterator lit= m_list.begin();
			// typename std::list<T>::iterator lite = m_list.end();
			// while (lit != lite)
			// {
			// 	printf("%d\n", *lit);
			// 	lit++;
			// }
			// typename std::list<T>::iterator o= newOther.begin();
			// typename std::list<T>::iterator oe = newOther.end();
			// while (o!= oe)
			// {
			// 	printf("%d\n", *o);
			// 	o++;
			// }
			// ft::listIterator<T> litnew= m_ftList.begin();
			// ft::listIterator<T> litenew = m_ftList.end();
			// while (litnew != litenew)
			// {
			// 	printf("%d\n", *litnew);
			// 	litnew++;
			// }
			
			if (checkIdenticalLists("SPLICE 2", 1))
				print("SPLICE 2", "OK");

			ft::list<int> m_newOther2;
			std::list<int> newOther2;
			for (int i = 0 ; i < 3; i++)
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

			if (checkIdenticalLists("SPLICE 3", 1))
				print("SPLICE 3", "OK");
		}

		void sort()
		{
			m_list.push_back (3);
			m_list.push_back (2);
			m_list.push_back (5);
			m_list.sort();

			
			m_ftList.push_back (3);
			m_ftList.push_back (2);
			m_ftList.push_back (5);
 			m_ftList.sort();

			if (checkIdenticalLists("SORT", 1))
				print("SORT", "OK");

			m_list.push_back (54);
			m_list.push_back (4);
			m_list.push_back (10);
			m_list.sort(mycomparison);

			
			m_ftList.push_back (54);
			m_ftList.push_back (4);
			m_ftList.push_back (10);
 			m_ftList.sort(mycomparison);

			if (checkIdenticalLists("SORT2", 1))
				print("SORT2", "OK");
		}
		
		
		void merge()
		{
			std::list<int> second;
			second.push_back (6);
			second.push_back (1);
			second.push_back (4);
			second.sort();
			m_list.merge(second);

			ft::list<int> ft_second;
			ft_second.push_back (6);
			ft_second.push_back (1);
			ft_second.push_back (4);
			ft_second.sort();
			// std::cout << " AFTER SECOND SORT\n"<< std::flush;
			// ft::listIterator<T> it= ft_second.begin();
			// ft::listIterator<T> ite = ft_second.end();
			// while (it != ite)
			// {
			// 	std::cout << *it<< std::endl;
			// 	it++;
			// }
			m_ftList.merge(ft_second);
			// std::cout << " AFTER MERGE\n"<< std::flush;
			// ft::listIterator<T> it= m_ftList.begin();
			// ft::listIterator<T> ite = m_ftList.end();
			// while (it != ite)
			// {
			// 	std::cout << *it<< std::endl;
			// 	it++;
			// }
			// m_ftList.merge(ft_second);
// std::cout << "\n"<< std::flush;
// typename std::list<T>::iterator lit= m_list.begin();
// 			typename std::list<T>::iterator lite = m_list.end();
// 			while (lit != lite)
// 			{
// 				std::cout << *lit<< std::endl;
			
// 				lit++;
// 			}
		

			if (checkIdenticalLists("MERGE", 1))
				print("MERGE", "OK");

			std::list<int> second2;
			ft::list<int> ft_second2;
			second2.push_back(2);	
			ft_second2.push_back(2);
			m_list.merge(second2, mycomparison);
			m_ftList.merge(ft_second2, mycomparison);

// ft::listIterator<T> it= m_ftList.begin();
// 			ft::listIterator<T> ite = m_ftList.end();
// 			while (it != ite)
// 			{
// 				std::cout << *it<< std::endl;
// 				it++;
// 			}

			// typename std::list<T>::iterator lit= m_list.begin();
			// typename std::list<T>::iterator lite = m_list.end();
			// while (lit != lite)
			// {
			// 	std::cout << *lit<< std::endl;
			
			// 	lit++;
			// }
			if (checkIdenticalLists("MERGE2", 1))
				print("MERGE2", "OK");
		}

		void reverse()
		{
			m_ftList.reverse();
			m_list.reverse();
			if (checkIdenticalLists("REVERSE", 1))
				print("REVERSE", "OK");
		}
	
};
#endif