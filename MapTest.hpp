/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:32 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/09 16:12:19 by atetu            ###   ########.fr       */
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
					std::cout <<itftmap->second << "-" << itMap->second << std::endl;
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
            if (m_ftmap.begin()->first != m_map.begin()->first || m_ftmap.begin()->second != m_map.begin()->second)
                print("BEGIN", "WRONG");
            else
                print("BEGIN", "OK");
        }
       
       void end()
        {
            typename ft::MapIterator<Key, T> itFT = m_ftmap.end();
            typename std::map<Key, T>::iterator itMap = m_map.end();
			itFT--;
			itMap--;
			
            if (itFT->first != itMap->first || itFT->second != itMap->second)
                print("END", "WRONG");
            else
                print("END", "OK");
        }
       
	   	#define CHECK_VALUES_MAP(apply, name)						\
            if (m_ftmap.apply() != m_map.apply())					\
                print(name, "WRONG");								\
            else													\
                print(name, "OK");      
				
		void size()
        {
            CHECK_VALUES_MAP(size, "SIZE");
        }
		
		void empty()
        {
            CHECK_VALUES_MAP(empty, "EMPTY");
        }

		void max_size()
		{
			 CHECK_VALUES_MAP(max_size, "EMPTY");
		}
	   
		void operator_access()
		{
			if (m_ftmap[3] == m_map[3] && m_ftmap[0] == m_map[0] && m_ftmap[555] == m_map[555])
				print("OPERATOR ACCESS", "OK");
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
			
			typename ft::MapIterator<Key, T> itFt = ft_second.begin();
			typename std::map<Key, T>::iterator itMap = second.begin();
			
			for(int i = 0; i < 4; i++)
			{
				itFt++;
				itMap++;
			}
			m_ftmap.insert(itFt, ft_second.end());
			m_map.insert(itMap, second.end());
		
			if (checkIdenticalMaps("INSERT2"))
				print("INSERT2", "OK");	
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
			
		#define ERASE2(key, nameTest, lastTest)		\
			m_ftmap.erase(key);							\
			m_map.erase(key);							\
			if (!lastTest)									\
				checkIdenticalMaps("ERASE2", 1);				\
			else											\
			{												\
				if (checkIdenticalMaps("ERASE2", 1))		\
					print("ERASE2", "OK");					\
			}
			
		void erase()
		{
			typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			typename std::map<Key, T>::iterator itMap = m_map.begin();
			typename ft::MapIterator<Key, T> iteFt = m_ftmap.end();
			typename std::map<Key, T>::iterator iteMap = m_map.end();
			
			ERASE(itFt, itMap, "ERASE", 0);
		//	ERASE(iteFt, iteMap, "ERASE", 1); //normal segfault;
		
			itFt = m_ftmap.begin();
			itMap = m_map.begin();
			itFt++;
			itMap++;
			ERASE(itFt, itMap, "ERASE", 1);
		}

		void erase2()
		{
			typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			typename std::map<Key, T>::iterator itMap = m_map.begin();
			typename ft::MapIterator<Key, T> iteFt = m_ftmap.end();
			typename std::map<Key, T>::iterator iteMap = m_map.end();
			
			// while(itFt != iteFt)
			// 	{
			// 		std::cout << itFt->first << itFt->second << " ";
			// 		itFt++;
			// 	}
			// std::cout << "\nMAP\n";
			// while(itMap != iteMap)
			// 	{
			// 		std::cout<< "Map /n" << std::endl;
			// 		std::cout << itMap->first << itMap->second << " ";
			// 		itMap++;
			// 	}
			ERASE2(10, "ERASE2", 1);

			// itFt = m_ftmap.begin();
			// iteFt = m_ftmap.end();
			
			// while(itFt != iteFt)
			// 	{
			// 		std::cout << itFt->first << itFt->second << " ";
			// 		itFt++;
			// 	}
			
			// itMap = m_map.begin();
			// iteMap = m_map.end();
			// m_map.erase(73);
			// while(itMap != iteMap)
			// 	{
			// 		std::cout << itMap->first << itMap->second << " ";
			// 		itMap++;
			// 	}
			ERASE2(20, "ERASE2", 1);
		//	ERASE(iteFt, iteMap, "ERASE", 1); //normal segfault;
		
			
			//ERASE(73, itMap, "ERASE2", 1);
		}
		
		void erase3()
		{
			typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			typename std::map<Key, T>::iterator itMap = m_map.begin();
			typename ft::MapIterator<Key, T> iteFt = m_ftmap.end();
			typename std::map<Key, T>::iterator iteMap = m_map.end();	
			itFt++;
			itMap++;
			m_ftmap.erase(itFt, iteFt);
			m_map.erase(itMap, iteMap);
			if (checkIdenticalMaps("ERASE3"))
				print("ERASE3", "OK");
		}

		void clear()
		{
			m_ftmap.clear();
			m_map.clear();
			if (checkIdenticalMaps("CLEAR") && m_ftmap.size() == m_map.size())
				print("CLEAR", "OK");
		}
      
		void swap()
		{
			ft::map<int, int> ft_second;
			ft_second.insert(ft::pair<int, int>(90, 90));
			ft_second.insert(ft::pair<int, int>(990, 990));
			ft_second.insert(ft::pair<int, int>(9990, 9990));
			ft_second.insert(ft::pair<int, int>(99990, 99990));
			

			std::map<int, int> second;
			second.insert(std::pair<int, int>(90, 90));
			second.insert(std::pair<int, int>(990, 990));
			second.insert(std::pair<int, int>(9990, 9990));
			second.insert(std::pair<int, int>(99990, 99990));
			
			m_ftmap.swap(ft_second);
			m_map.swap(second);
			if (checkIdenticalMaps("SWAP"))
				print("SWAP", "OK");
		}

		void key_compare()
		{
			ft::map<int, int>::iterator ft = m_ftmap.begin();
			ft::map<int, int>::iterator ft2 = ft;
			ft2++;
			ft::map<int, int>::key_compare ft_comp= m_ftmap.key_comp();
			
			std::map<int, int>::iterator m = m_map.begin();
			std::map<int, int>::iterator m2 = m;
			m2++;
			std::map<int,int>::key_compare mcomp = m_map.key_comp();
			
			if ((ft_comp(ft->first, ft2->first)) == (mcomp(m->first, m2->first)))
				print("KEY_COMPARE", "OK");
		}

		void value_compare()
		{
			ft::map<int, int>::iterator ft = m_ftmap.begin();
			ft::map<int, int>::iterator ft2 = ft;
			ft2++;
			//ft::map<int, int>::value_comp ft_comp= m_ftmap.key_comp();

			std::map<int, int>::iterator m = m_map.begin();
			std::map<int, int>::iterator m2 = m;
			m2++;
		//	std::map<int,int>::key_compare mcomp = m_map.key_comp();
			
			if ((m_ftmap.value_comp()(*ft, *ft2)) == (m_map.value_comp()(*m, *m2)))
				print("VALUE_COMPARE", "OK");
		}
	  
	  void find()
	  {
		  if ((m_ftmap.find(10))->first == (m_map.find(10))->first
		  && (m_ftmap.find(20))->second == (m_ftmap.find(20))->second
		  && (m_ftmap.find(6))->first == (m_map.find(6))->first)
		  {
			  print("FIND", "OK");
		  }
	  }

	  void count()
	  {
		if (m_ftmap.count(10) == m_map.count(10)
		&& m_ftmap.count(20) == m_ftmap.count(20)
		&& m_ftmap.count(6) == m_map.count(6)
		&& m_ftmap.count(6) == m_map.count(6))
		 {
			  print("COUNT", "OK");
		  }
	  }
};

#endif
