/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:32 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/12 15:55:00 by atetu            ###   ########.fr       */
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
		
		void
		constructor2()
		{
			typename ft::MapIterator<Key, T> itftmap = m_ftmap.begin();
            typename ft::MapIterator<Key, T> iteftmap = m_ftmap.end();
            typename std::map<Key, T>::iterator itMap = m_map.begin();
            typename std::map<Key, T>::iterator iteMap = m_map.end();
			
			ft::map<Key, T> ft_copy(itftmap, iteftmap);
			std::map<Key, T> copy(itMap, iteMap);
			
			typename ft::MapIterator<Key, T> it = ft_copy.begin();
            typename ft::MapIterator<Key, T> ite = ft_copy.end();
			m_ftmap.clear();
			m_map.clear();
			m_ftmap = ft_copy;
			m_map = copy;
			std::cout << "constructor 2\n";
			// while(it != ite)
			// {
			// 	std::cout << it->first << std::endl;
			// 	it++;
			// }
		
			if (checkIdenticalMaps("CONSTRUCTOR2", 1))
					print("	CONSTRUCTOR2", "OK");	
			// itftmap = m_ftmap.begin();
          	// iteftmap = m_ftmap.end();
			// while(itftmap != iteftmap)
			// {
			// 		std::cout << itftmap->first << std::endl;
			// 	itftmap++;
			// }
		}

		void constructor3()
		{
			std::cout << "constructor 3\n" << std::flush;
			ft::map<Key, T> ft_copy(m_ftmap);
			std::map<Key, T> copy(m_map);
			
			typename ft::MapIterator<Key, T> it = ft_copy.begin();
            typename ft::MapIterator<Key, T> ite = ft_copy.end();
			// m_ftmap.clear();
			// m_map.clear();
			// m_ftmap = ft_copy;
			// m_map = copy;
			// std::cout << "constructor 2\n";
			std::cout << "COPY\n" << std::flush;
			while(it != ite)
			{
				std::cout << it->first << "\n" << std::flush;
				it++;
			}
		
			if (checkIdenticalMaps("CONSTRUCTOR3", 1))
					print("	CONSTRUCTOR3", "OK");	
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
					std::cout <<itftmap->first << "-" << itMap->first << "\n" << std::flush;
					std::cout <<itftmap->second << "-" << itMap->second << "\n" << std::flush;
				}
				// if (itMap != iteMap)
				// {
				if (itftmap->first != itMap->first || itMap->second != itMap->second)
                {
					print(testName, "WRONG1");
                    return(0);
                }
                itftmap++;
               	itMap++;
				// }
				// else
				// {
				// 		break;
				// }
				
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
			// typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			// typename std::map<Key, T>::iterator itMap = m_map.begin();
			// typename ft::MapIterator<Key, T> iteFt = m_ftmap.end();
			// typename std::map<Key, T>::iterator iteMap = m_map.end();
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
	   
	   #define INSERT_MAP(itFt, itMap, val)			\
			m_ftmap.insert(itFt, val);				\
			m_map.insert(itMap, val);				\
			if (!(checkIdenticalMaps("INSERT_MAP")))	\
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
		
			if (checkIdenticalMaps("INSERT_MAP"))
				print("INSERT_MAP", "OK");	
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
		
			if (checkIdenticalMaps("INSERT_MAP2"))
				print("INSERT_MAP2", "OK");	
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
			
			if (checkIdenticalMaps("INSERT_MAP3"))
				print("INSERT_MAP3", "OK");	
		}
		
		#define ERASE_MAP(itFt, itMap, nameTest, lastTest)		\
			m_ftmap.erase(itFt);							\
			m_map.erase(itMap);							\
			if (!lastTest)									\
				checkIdenticalMaps("ERASE_MAP");				\
			else											\
			{												\
				if (checkIdenticalMaps("ERASE_MAP"))		\
					print("ERASE_MAP", "OK");					\
			}
			
		#define ERASE_MAP2(key, nameTest, lastTest)		\
			m_ftmap.erase(key);							\
			m_map.erase(key);							\
			if (!lastTest)									\
				checkIdenticalMaps("ERASE_MAP2", 1);				\
			else											\
			{												\
				if (checkIdenticalMaps("ERASE_MAP2", 1))		\
					print("ERASE_MAP2", "OK");					\
			}
			
		void erase()
		{
			typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			typename std::map<Key, T>::iterator itMap = m_map.begin();
			typename ft::MapIterator<Key, T> iteFt = m_ftmap.end();
			// typename std::map<Key, T>::iterator iteMap = m_map.end();
			
			ERASE_MAP(itFt, itMap, "ERASE_MAP", 0);
			
			itFt = m_ftmap.begin();
			itMap = m_map.begin();
			itFt++;
			itMap++;
			ERASE_MAP(itFt, itMap, "ERASE_MAP", 1);
		}

		void erase2()
		{
			typename ft::MapIterator<Key, T> itFt = m_ftmap.begin();
			// typename std::map<Key, T>::iterator itMap = m_map.begin();
			typename ft::MapIterator<Key, T> iteFt = m_ftmap.end();
			// typename std::map<Key, T>::iterator iteMap = m_map.end();
			
			
			ERASE_MAP2(10, "ERASE_MAP2", 1);

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
			ERASE_MAP2(20, "ERASE_MAP2", 1);
		//	ERASE_MAP(iteFt, iteMap, "ERASE_MAP", 1); //normal segfault;
		
			
			//ERASE_MAP(73, itMap, "ERASE_MAP2", 1);
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
			if (checkIdenticalMaps("ERASE_MAP3"))
				print("ERASE_MAP3", "OK");
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
			if (checkIdenticalMaps("SWAP", 1))
				print("SWAP", "OK");
			// ft::map<int, int>::iterator ft = ft_second.begin();
			// ft::map<int, int>::iterator ft2 = ft_second.end();
			// 	while(ft != ft2)
			// 		{
			// 			std::cout << "it  : " << ft->first << "\n" << std::flush;
			// 			ft++;
			// 		}
			// ft::map<int, int>::MapNode* root = 	m_ftmap.root();
			// std::cout <<  "root: " << root->value() << std::endl;
			// 		// std::cout << "it  : " << ft->first << "\n" << std::flush;
			// 		// 	ft++;
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
			
			// ft::map<int, int>::iterator fte;
			// ft = m_ftmap.begin();
			// fte = m_ftmap.end();
			
			// while(ft != fte)
			// 	{
			// 		std::cout << ft->first << "\n";
			// 		ft++;
			// 	}		
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
			
			// ft::map<int, int>::iterator fte = m_ftmap.begin();
			// ft = m_ftmap.begin();
			// ft = m_ftmap.end();
			
			// while(ft != fte)
			// 	{
			// 		std::cout << ft->first << "\n";
			// 		ft++;
			// 	}
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
		&& m_ftmap.count(436) == m_map.count(4036))
		 {
			  print("COUNT", "OK");
		  }
	  }

	  #define LOWER(itFt, itMap, nameTest, lastTest)		\
			m_ftmap.erase(itFt);							\
			m_map.erase(itMap);							\
			if (!lastTest)									\
				checkIdenticalMaps("ERASE_MAP");				\
			else											\
			{												\
				if (checkIdenticalMaps("ERASE_MAP"))		\
					print("ERASE_MAP", "OK");					\
			}
	  void lower_bound()
	  {
		int error = 0;
		for (int i = 0 ; i < 30 ; i++)
		{
			if (!((m_ftmap.lower_bound(i))->first == (m_map.lower_bound(i))->first
				&& (m_ftmap.lower_bound(i))->second == (m_map.lower_bound(i))->second))
			{
				error = 1;
				print("LOWER BOUND", "WRONG");
				break;
			}
		}
		if (!error)
			print("LOWER BOUND", "OK");
	  }

	  void upper_bound()
	  {
		int error = 0;
		for (int i = 0 ; i < 30 ; i++)
		{
			if (!((m_ftmap.upper_bound(i))->first == (m_map.upper_bound(i))->first
				&& (m_ftmap.upper_bound(i))->second == (m_map.upper_bound(i))->second))
			{
				error = 1;
				print("UPPER BOUND", "WRONG");
				break;
			}
		}
		if (!error)
			print("UPPER BOUND", "OK");
	  }

	  void equal_range()
	  {
		int error = 0;
		ft::map<int, int>::iterator ft;
		ft::map<int, int>::iterator ft2;
				
		std::map<int, int>::iterator m;
		std::map<int, int>::iterator m2;
		for (int i = 0 ; i < 30 ; i++)
		{
			ft = m_ftmap.equal_range(i).first;
			ft2 = m_ftmap.equal_range(i).second;
			m = m_map.equal_range(i).first;
			m2 = m_map.equal_range(i).second;

			if (!(ft->first == m->first && ft->first == m->second &&
				ft2->first == m2->first && ft2->first == m2->second))
			{
				error = 1;
				print("EQUAL RANGE", "WRONG");
				break;
			}
		}
		if (!error)
			print("EQUAL RANGE", "OK");
	  }

	ft::map<int, int> set_ft_second(int option)
	{
		ft::map<int, int> ft_second;
		ft_second.insert(ft::pair<int, int>(5, 5));
		ft_second.insert(ft::pair<int, int>(3, 3));
		ft_second.insert(ft::pair<int, int>(2, 2));
		ft_second.insert(ft::pair<int, int>(4, 4));
		if(option == 1)
			return (ft_second);
		ft_second.insert(ft::pair<int, int>(10, 10));
		ft_second.insert(ft::pair<int, int>(8, 8));
		ft_second.insert(ft::pair<int, int>(6, 6));
		if (option == 2)
			ft_second.insert(ft::pair<int, int>(0, 0));
		if (option == 3)
			ft_second.insert(ft::pair<int, int>(50, 50));
		ft_second.insert(ft::pair<int, int>(9, 9));
		ft_second.insert(ft::pair<int, int>(20, 20));
		if (option >=2 && option <=4)
			return (ft_second);
		ft_second.insert(ft::pair<int, int>(30, 30));
		return(ft_second);
	}

	std::map<int, int> set_second(int option)
	{
		std::map<int, int> second;
		second.insert(pair<int, int>(5, 5) );
		second.insert(std::pair<int, int>(3, 3));
		second.insert(std::pair<int, int>(2, 2));
		second.insert(std::pair<int, int>(4, 4));
		if(option == 1)
			return (second);
		second.insert(std::pair<int, int>(10, 10));
		second.insert(std::pair<int, int>(8, 8));
		second.insert(std::pair<int, int>(6, 6));
		if (option == 2)
			second.insert(std::pair<int, int>(0, 0));
		if (option == 3)
			second.insert(std::pair<int, int>(50, 50));
		second.insert(std::pair<int, int>(9, 9));
		second.insert(std::pair<int, int>(20, 20));
		if (option >=2 && option <=4)
			return (second);
		second.insert(std::pair<int, int>(30, 30));
		return(second);
	}

	  void equal()
	  {
		ft::map<int, int> ft_second;
		std::map<int, int> second;
	
		for (int i = 0; i < 5; i++)
		{
			ft_second = set_ft_second(i);
			second  = set_second(i);
			if ((m_map == second) != (m_ftmap == ft_second))
			{
				print("EQUAL", "WRONG");
				return;
			}
		}
		print("EQUAL", "OK");
	  }

	
	  void not_equal()
	  {
		ft::map<int, int> ft_second;
		std::map<int, int> second;
	
		for (int i = 0; i < 5; i++)
		{
			ft_second = set_ft_second(i);
			second  = set_second(i);
			if ((m_map != second) != (m_ftmap != ft_second))
			{
				print("NOT EQUAL", "WRONG");
				return;
			}
		}
		print("NOT EQUAL", "OK");
	  }

	   void less()
	  {
		ft::map<int, int> ft_second;
		std::map<int, int> second;
	
		for (int i = 0; i < 5; i++)
		{
			ft_second = set_ft_second(i);
			second  = set_second(i);
			if (((m_map < second) != (m_ftmap < ft_second))
			|| ((second < m_map) != (ft_second < m_ftmap)))
			{
				print("LESS", "WRONG");
				return;
			}
		}
		print("LESS", "OK");
	  }

	void less_or_equal()
	{
		ft::map<int, int> ft_second;
		std::map<int, int> second;
	
		for (int i = 0; i < 5; i++)
		{
			ft_second = set_ft_second(i);
			second  = set_second(i);
			if (((m_map <= second) != (m_ftmap <= ft_second))
			|| ((second <= m_map) != (ft_second <= m_ftmap)))
			{
				print("LESS_OR_EQUAL", "WRONG");
				return;
			}
		}
		print("LESS_OR_EQUAL", "OK");
	  }

	  void greater()
	  {
		ft::map<int, int> ft_second;
		std::map<int, int> second;
	
		for (int i = 0; i < 5; i++)
		{
			ft_second = set_ft_second(i);
			second  = set_second(i);
			if (((m_map > second) != (m_ftmap > ft_second))
			|| ((second > m_map) != (ft_second > m_ftmap)))
			{
				print("GREATER", "WRONG");
				return;
			}
		}
		print("GREATER", "OK");
	  }

	void greater_or_equal()
	{
		ft::map<int, int> ft_second;
		std::map<int, int> second;
	
		for (int i = 0; i < 5; i++)
		{
			ft_second = set_ft_second(i);
			second  = set_second(i);
			if (((m_map >= second) != (m_ftmap >= ft_second))
			|| ((second >= m_map) != (ft_second >= m_ftmap)))
			{
				print("GREATER_OR_EQUAL", "WRONG");
				return;
			}
		}
		print("GREATER_OR_EQUAL", "OK");
	  }

	  void reverse()
	  {
		typedef ft::map<int, int>::iterator iter_type;
		ft::ReverseIterator<iter_type> ftm = m_ftmap.rbegin();;
		ft::ReverseIterator<iter_type> fte = m_ftmap.rend();
				
		std::map<int, int>::reverse_iterator m = m_map.rbegin();
		std::map<int, int>::reverse_iterator m2 = m_map.rend();
		
		while(ftm != fte && m != m2)
		{
			// std::cout<< "ft first: " << ftm->first << "\n" << std::flush;
			// 	// std::cout<< "m first: " << m->first << "\n" << std::flush;
			// 	// std::cout<< "ft second: " << ft->second << "\n" << std::flush;
			// 	// std::cout<< "m second: " << m->second << "\n" << std::flush;
			if (ftm->first != m->first || ftm->second!= m->second)
			{
				
				print("REVERSE", "WRONG");
				return;
			}
			ftm++;
			m++;
		}

		print("REVERSE", "OK");
	  }

	  void reverse_relational()
	  {
		typedef ft::map<int, int>::iterator iter_type;
		ft::ReverseIterator<iter_type> ftm = m_ftmap.rbegin();
		ft::ReverseIterator<iter_type> ftbis = ftm;
		ft::ReverseIterator<iter_type> ft2 = ftm;
		ft2++;
				
		std::map<int, int>::reverse_iterator m = m_map.rbegin();
		std::map<int, int>::reverse_iterator mbis = m;
		std::map<int, int>::reverse_iterator m2 = m;
		m2++;
		
		if ((ftm == ftbis) == (m == mbis)
			&& (ftm == ft2) == (m == m2))
			print("REVERSE ==", "OK");

		if ((ftm != ftbis) == (m != mbis)
			&& (ftm != ft2) == (m != m2))
			print("REVERSE !=", "OK");
	  }
};

#endif
