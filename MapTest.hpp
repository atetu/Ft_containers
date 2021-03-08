/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:32 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/08 17:14:35 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPTEST_HPP
#define MAPTEST_HPP

#include <memory>
#include <iostream>
#include "Map.hpp" 
#include<map>
using namespace std;

template <typename Key, typename T> class MapTest
{
    private:
        ft::map<Key, T> m_ftmap;
		std::map<Key, T> m_map;
	
    public:
        MapTest() : m_ftmap(), m_map()
        {
        }

		static void
        print(const std::string& test, const std::string & result)
        {
            std::cout << "Test " << test << " : " << result << std::endl;
        }
        
		int checkIdenticalMaps(std::string testName, int writeOption = 0)
        {
            typename ft::MapIterator<Key, T> itftmap = m_ftmap.begin();
            typename ft::MapIterator<Key, T> iteftmap = m_ftmap.end();
            typename std::map<Key, T>::iterator itMap = m_map.begin();
            typename std::map<Key, T>::iterator iteMap = m_map.end();

			
            while (itftmap != iteftmap) //&& itMap != iteMap)
            {
				if (writeOption)
				{
					std::cout <<itftmap->first << "-" << itMap->first << std::endl;
					std::cout <<itMap->second << "-" << itMap->second << std::endl;
				}
				if (itftmap->first != itMap->first || itMap->second != itMap->second)
                {
					print(testName, "WRONG1");
                    return(0);
                }
                itftmap++;
                itMap++;
            }
            if (itftmap != iteftmap || itMap != iteMap)
            {
                print(testName, "WRONG2");
                return(0);
            }
       		return(1);
        }

		template <typename KeyX, typename X, typename KeyY, typename Y>
		static int checkIdenticalMaps(std::map<KeyX, X> &x, ft::map<KeyY, Y> &y, std::string testName, int writeOption = 0)
        {
            typename std::map<KeyX, X>::iterator itMap = x.begin();
            typename std::map<KeyX, X>::iterator iteMap = x.end();
			typename ft::MapIterator<KeyY, Y> itftmap = y.begin();
            typename ft::MapIterator<KeyY, Y> iteftmap = y.end();
           

            while (itftmap != iteftmap) //&& itMap != iteMap)
            {
				if (writeOption)
					std::cout <<*itftmap << "-" << *itMap << std::endl;
				if (*itftmap != *itMap)
                {
					print(testName, "WRONG1");
                    return(0);
                }
                itftmap++;
                itMap++;
            }
            if (itftmap != iteftmap || itMap != iteMap)
            {
                print(testName, "WRONG2");
                return(0);
            }
       		return(1);
        }

        #define CHECK_VALUES(apply, name)                     \
            if (m_ftmap.apply() != m_map.apply())             \
                print(name, "WRONG");                       \
            else                                                \
                print(name, "OK");        
                
        void begin()
        {
            // if (m_ftmap.begin().node()->key() != m_map.begin().node()->key() || m_ftmap.begin().node()->value() != m_map.begin().node()->value())
            //     print("BEGIN", "WRONG");
            // else
            //     print("BEGIN", "OK");
        }
       
       void end()
        {
            typename ft::MapIterator<Key, T> itFT = m_ftmap.end();
            typename std::map<Key, T>::iterator itMap = m_map.end();
			itFT--;
			itMap--;
			
            if (itFT->first != itMap->first)
                print("END", "WRONG");
            else
                print("END", "OK");
        }
       
	   #define INSERT(itFt, itMap, val)			\
			m_ftmap.insert(itFt, val);				\
			m_map.insert(itMap, val);				\
			if (!(checkIdenticalMaps("INSERT")))	\
				return;
				
		void insert()
		{
			m_ftmap.insert(ft::pair<int, int>(5, 5));
			m_ftmap.insert(ft::pair<int, int>(3, 3));
			m_ftmap.insert(ft::pair<int, int>(2, 2));
			m_ftmap.insert(ft::pair<int, int>(4, 4));
			m_ftmap.insert(ft::pair<int, int>(10, 10));
			m_ftmap.insert(ft::pair<int, int>(8, 8));
			m_ftmap.insert(ft::pair<int, int>(6, 6));
			m_ftmap.insert(ft::pair<int, int>(9, 9));
			m_ftmap.insert(ft::pair<int, int>(20, 20));
		
			m_map.insert(pair<int, int>(5, 5) );
			m_map.insert(std::pair<int, int>(3, 3));
			m_map.insert(std::pair<int, int>(2, 2));
			m_map.insert(std::pair<int, int>(4, 4));
			m_map.insert(std::pair<int, int>(10, 10));
			m_map.insert(std::pair<int, int>(8, 8));
			m_map.insert(std::pair<int, int>(6, 6));
			m_map.insert(std::pair<int, int>(9, 9));
			m_map.insert(std::pair<int, int>(20, 20));
		
			print("INSERT", "OK");
		}

		void insert2()
		{
			ft::map<int, int> ft_second;
			ft_second.insert(ft::pair<int, int>(200, 200));
			ft_second.insert(ft::pair<int, int>(300, 300));
			ft_second.insert(ft::pair<int, int>(150, 150));
			ft_second.insert(ft::pair<int, int>(175, 175));
			

			std::map<int, int> second;
			second.insert(std::pair<int, int>(200, 200));
			second.insert(std::pair<int, int>(300, 300));
			second.insert(std::pair<int, int>(150, 150));
			second.insert(std::pair<int, int>(175, 175));

			
			m_ftmap.insert(ft_second.begin(), ft_second.end());
			m_map.insert(second.begin(), second.end());
			
			// typename ft::MapIterator<Key, T> itFt = ft_second.begin();
			// typename std::map<Key, T>::iterator itMap = second.begin();
			
			// for(int i = 0; i < 4; i++)
			// {
			// 	itFt++;
			// 	itMap++;
			// }
			// m_ftmap.insert(itFt, ft_second.end());
			// m_map.insert(itMap, second.end());
		
			// if (checkIdenticalMaps("INSERT2"))
			// 	print("INSERT2", "OK");	
		}

		void insert3()
		{
			typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			typename std::map<Key, T>::iterator itMap = m_map.begin();
			
			
			for(int i = 0; i < 4; i++)
			{
				itFt++;
				itMap++;
			}

			m_ftmap.insert(itFt, ft::pair<int, int>(435, 435));
			m_map.insert(itMap, std::pair<int, int>(435, 435));
			
			if (checkIdenticalMaps("INSERT3"))
				print("INSERT3", "OK");	
		}
		
		#define ERASE(itFt, itMap, nameTest, lastTest)		\
			m_ftmap.erase(itFt);							\
			m_map.erase(itMap);							\
			if (!lastTest)									\
				checkIdenticalMaps("ERASE");				\
			else											\
			{												\
				if (checkIdenticalMaps("ERASE"))		\
					print("ERASE", "OK");					\
			}
			
		void erase()
		{
			typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			typename std::map<Key, T>::iterator itMap = m_map.begin();
			typename ft::MapIterator<Key, T> iteFt = m_ftmap.end();
			typename std::map<Key, T>::iterator iteMap = m_map.end();
			
			ERASE(itFt, itMap, "ERASE", 1);
		//	ERASE(iteFt, iteMap, "ERASE", 1); //normal segfault;
		
			itFt = m_ftmap.begin();// with std::map, when doing itMap++ just after works
			itMap = m_map.begin();
			++itFt;
			itMap++;
			ERASE(itFt, itMap, "ERASE", 1);
			
		}

		void erase2()
		{
			typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			typename std::map<Key, T>::iterator itMap = m_map.begin();
			typename ft::MapIterator<Key, T> iteFt = m_ftmap.end();
			typename std::map<Key, T>::iterator iteMap = m_map.end();	
			itFt++;
			itMap++;
			m_ftmap.erase(itFt, iteFt);
			m_map.erase(itMap, iteMap);
			if (checkIdenticalMaps("ERASE2"))
				print("ERASE2", "OK");
		}

		void clear()
		{
			m_ftmap.clear();
			m_map.clear();
			checkIdenticalMaps("CLEAR");
			
			
			checkIdenticalMaps("CLEAR");
			m_ftmap.clear();
			m_map.clear();
			if (checkIdenticalMaps("CLEAR"))
				print("CLEAR", "OK");
		}
        
};

#endif
