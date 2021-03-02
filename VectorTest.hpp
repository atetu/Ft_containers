/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTest.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:45:09 by atetu             #+#    #+#             */
/*   Updated: 2021/03/01 16:52:45 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vectorTEST_HPP
# define vectorTEST_HPP

#include <memory>
#include <iostream>
#include "Iterator.hpp"
#include "Vector.hpp"
#include<vector>

bool mycomparison (int first, double second);

template <typename T>
class VectorTest
{
    private:
        ft::vector<T> m_ftvector;
        std::vector<T> m_vector;
		// ft::vector<const T> m_ftconstvector;
        // std::vector<const T> m_constvector;

    public:
        VectorTest<T>()
        {
			ft::vector<T> ftv;
			std::vector<T>v;
			m_ftvector = ftv;
			m_vector = v;
			if(checkIdenticalvectors("INIT_EMPTY"))
				print("INIT_EMPTY", "OK");
			// m_ftconstvector(42, 4);
			// m_constvector(42, 4);
        }
        
        VectorTest(T* array, int size)
        {
           init(array, size);
        }
		
		VectorTest(T val, int size)
		{
			ft::vector<T> ftl(size, val);
			m_ftvector = ftl;
			std::vector<T> l(size, val);
			m_vector = l;
			if(checkIdenticalvectors("INIT_SIZE_VAL"))
				print("INIT_SIZE_VAL", "OK");
		}
        
		VectorTest(T val, int size, int start, int end)
		{
			ft::vector<T> ft_copy(size, val);
			typename ft::vector<T>::iterator it = ft_copy.begin();
			typename ft::vector<T>::iterator ite = ft_copy.end();
			typename ft::vector<T>::iterator ft_first;
			typename ft::vector<T>::iterator ft_last;
			std::vector<T> copy(size, val);
			typename std::vector<T>::iterator itl = copy.begin();
			typename std::vector<T>::iterator itel = copy.end();
			typename std::vector<T>::iterator first;
			typename std::vector<T>::iterator last;
			for(int i = 0 ; i < start; i++)
			{
				it++;
				itl++;
			}
			ft_first = it;
			first = itl;
			for(; start < end; start++)
			{
				it++;
				itl++;
			}
			ft_last = it;
			last = itl;
			ft::vector<int> ftl(ft_first, ft_last);
			m_ftvector = ftl;
			
			std::vector<int> l(first, last);
			m_vector = l;
			if(checkIdenticalvectors("INIT_INPUT_ITERATOR_FIRST_INPUT_ITERATOR_LAST"))
				print("INIT_INPUT_ITERATOR_FIRST_INPUT_ITERATOR_LAST", "OK");
		}
		
		VectorTest(T val, int size, std::string c)
		{
			(void)c;
			ft::vector<T> ft_copy(size, val);
			typename ft::vector<T>::iterator it = ft_copy.begin();
			typename ft::vector<T>::iterator ite = ft_copy.end();
		
			std::vector<T> copy(size, val);
			typename std::vector<T>::iterator itl = copy.begin();
			typename std::vector<T>::iterator itel = copy.end();
			
			ft::vector<int> ftl(ft_copy);
			m_ftvector = ftl;
					
			std::vector<int> l(copy);
			m_vector = l;
			
			if(checkIdenticalvectors("INIT_COPY"))
				print("INIT_COPY", "OK");
		}
		
		void init(T* array, int size)
		{
			int i = 0;
           
            while (i < size)
            {
                m_ftvector.push_back(array[i]);
				m_vector.push_back(array[i]);
                i++;
            }
		}
		
		static void
        print(const std::string& test, const std::string & result)
        {
            std::cout << "Test " << test << " : " << result << std::endl;
        }
        
		int checkIdenticalvectors(std::string testName, int writeOption = 0)
        {
            typename ft::Iterator<T> itFtvector = m_ftvector.begin();
            typename ft::Iterator<T> iteFtvector = m_ftvector.end();
            typename std::vector<T>::iterator itvector = m_vector.begin();
            typename std::vector<T>::iterator itevector = m_vector.end();

			// while(itvector != itevector)
			// {
			// 	std::cout << "VECTOR: "<< *itvector << std::endl;
			// 	itvector++;
			// }
			// while(itFtvector != iteFtvector)
			// {
			// 	std::cout << "FT: "<< *itFtvector << std::endl;
			// 	itFtvector++;
			// }
			if (m_ftvector.size() && m_vector.size())
			{
				std::cout << "SIZE: " << m_ftvector.size() << "-" << m_vector.size() << std::endl;
				while (itFtvector != iteFtvector) //&& itvector != itevector)
				{
					if (writeOption)
						std::cout <<*itFtvector << "-" << *itvector << std::endl;
					if (*itFtvector != *itvector)
					{
						print(testName, "WRONG1");
						return(0);
					}
					itFtvector++;
					itvector++;
				}
				if (itFtvector != iteFtvector || itvector != itevector)
				{
					print(testName, "WRONG2");
					return(0);
				}
			}
			else if (m_ftvector.size() != m_vector.size())
			{
				std::cout << "FT Vector size : " << m_ftvector.size() << std::endl;
					std::cout << "Vector size : " << m_vector.size() << std::endl;
				print(testName, "WRONG3");
				return(0);
			}
       		return(1);
        }

		template <typename Y>
		static int checkIdenticalvectors(std::vector<Y> &x, ft::vector<Y> &y, std::string testName, int writeOption = 0)
        {
            typename std::vector<Y>::iterator itvector = x.begin();
            typename std::vector<Y>::iterator itevector = x.end();
			typename ft::Iterator<Y> itFtvector = y.begin();
            typename ft::Iterator<Y> iteFtvector = y.end();
           

            while (itFtvector != iteFtvector) //&& itvector != itevector)
            {
				if (writeOption)
					std::cout <<*itFtvector << "-" << *itvector << std::endl;
				if (*itFtvector != *itvector)
                {
					print(testName, "WRONG1");
                    return(0);
                }
                itFtvector++;
                itvector++;
            }
            if (itFtvector != iteFtvector || itvector != itevector)
            {
                print(testName, "WRONG2");
                return(0);
            }
       		return(1);
        }

        #define CHECK_VALUES_VEC(apply, name)                     \
            if (m_ftvector.apply() != m_vector.apply())             \
                print(name, "WRONG");                       \
            else                                                \
                print(name, "OK");        
                
        void begin()
        {
            if ((*m_ftvector.begin()) != (*m_vector.begin()))
                print("BEGIN", "WRONG");
            else
                print("BEGIN", "OK");
        }
       
       void end()
        {
            typename ft::Iterator<T> itFT = m_ftvector.end();
            typename std::vector<T>::iterator itvector = m_vector.end();
            if ((*(--itFT)) != (*(--itvector)))
                print("END", "WRONG");
            else
                print("END", "OK");
        }
		
		void beginconst()
		{
			beginconsttest(m_ftvector, m_vector);
		}
		
		void beginconsttest(const ft::vector<T> &ft_vec, const std::vector<T> &vec)
        {
            if ((*ft_vec.begin()) != (*vec.begin()))
                print("BEGIN CONST", "WRONG");
            else
                print("BEGIN CONST", "OK");
        }
            
	  	void endconst()
		{
			endconsttest(m_ftvector, m_vector);
		}
		
		void endconsttest(const ft::vector<T> &ft_vec, const std::vector<T> &vec)
        {
            typename ft::ConstIterator<T> itFT = ft_vec.end();
            typename std::vector<T>::const_iterator itvector = vec.end();
            if ((*(--itFT)) != (*(--itvector)))
                print("END CONST", "WRONG");
            else
                print("END CONST", "OK");
        }

        void size()
        {
            CHECK_VALUES_VEC(size, "SIZE");
        }

		void maxSize()
		{
			CHECK_VALUES_VEC(max_size, "MAX_SIZE");
		}

		void resize()
		{
			m_ftvector.resize(2);
			m_vector.resize(2);
			if(checkIdenticalvectors("RESIZE 1", 1))
				print("RESIZE 1", "OK");

			m_ftvector.resize(0);
			m_vector.resize(0);
			if(checkIdenticalvectors("RESIZE 2"))
				print("RESIZE 2", "OK");
				
			m_ftvector.resize(5, 24);
			m_vector.resize(5, 24);
			if(checkIdenticalvectors("RESIZE 3"))
				print("RESIZE 3", "OK");
		}
		
		void capacity()
        {
            CHECK_VALUES_VEC(capacity, "CAPACITY");
        }
		
		void empty()
        {
            CHECK_VALUES_VEC(empty, "EMPTY");
        }

    //     void assign()
    //     {}

	//  	void push_front()
    //     {
    //         m_ftvector.push_front(50);
          
    //         m_vector.push_front(50);
	// 		if(checkIdenticalvectors("PUSH_FRONT"))
	// 			print("PUSH_FRONT", "OK");
    //     }
		

		void operator_access()
		{
			for (size_t i = 0 ; i < m_ftvector.size(); i++)
			{
				if (!(m_ftvector[i] == m_vector[i]))
					print("[]", "WRONG");
			}
			print("[]", "OK");
		}
		
		void at()
		{
			try
			{
		
			
				size_t i = 0;
				for (; i < m_ftvector.size(); i++)
				{
					if (!(m_ftvector.at(i) == m_vector.at(i)))
						print("AT", "WRONG");
				}
				i = m_ftvector.size() + 1;
				// std::cout << "After end ft: " << m_ftvector.at(i) << std::endl;
				// std::cout << "After end vec: " << m_vector.at(i) << std::endl;
				
				print("AT", "OK");
			}
			catch(const std::exception& e)
			{
				std::cerr << "ERROR: " << e.what() << '\n';
				return;
			}
		}

		void front()
		{
			// std::cout <<  m_vector.front() << std::endl;
			// std::cout <<  m_ftvector.front() << std::endl;
			if (m_ftvector.front() == m_vector.front())
				print("FRONT", "OK");
			else
				print("FRONT", "WRONG");			
		}
		
		void back()
		{
			// std::cout <<  m_vector.back() << std::endl;
			// std::cout <<  m_ftvector.back() << std::endl;
			if (m_ftvector.back() == m_vector.back())
				print("BACK", "OK");
			else
				print("BACK", "WRONG");			
		}
		
        void push_back()
        {
            m_ftvector.push_back(6);
          
            m_vector.push_back(6);
			if(checkIdenticalvectors("PUSH_BACK"))
				print("PUSH_BACK", "OK");
        }

        void pop_back()
        {
			int max;
            if (!((max = m_ftvector.size()) == m_vector.size()))
                print("POP_BACK", "WRONG");
            else
            {
				for (int i = 0; i < 2; i++)
                {
				    m_ftvector.pop_back();
                    m_vector.pop_back();
					if (!(checkIdenticalvectors("POP_BACK", 1)))
						return;
					i++;
                }
			}
			if(checkIdenticalvectors("POP_BACK", 1))
				print("POP_BACK", "OK");
        }
		
	// 	void pop_front()
    //     {
	// 		int max;
    //         if (!((max = m_ftvector.size()) == m_vector.size()))
    //             print("POP_FRONT", "WRONG");
    //         else
    //         {
	// 			for (int i = 0; i < 2; i++)
	// 			{
	// 			    m_ftvector.pop_back();
    //                 m_vector.pop_back();
	// 				if (!(checkIdenticalvectors("POP_FRONT")))
	// 					return;
	// 				i++;
    //             }
	// 		}
	// 		if(checkIdenticalvectors("POP_FRONT"))
	// 			print("POP_FRONT", "OK");
    //     }
		
		#define INSERT_VEC(itFt, itvector, val)			\
			m_ftvector.insert(itFt, val);				\
			m_vector.insert(itvector, val);				\
			if (!(checkIdenticalvectors("INSERT", 1)))	\
				return;
				
		void insert()
		{
			typename ft::Iterator<T> itFt = m_ftvector.begin();
			typename ft::Iterator<T> iteFt = m_ftvector.end();
            typename std::vector<T>::iterator itvector = m_vector.begin();
            typename std::vector<T>::iterator itevector = m_vector.end();
		
			INSERT_VEC(itFt, itvector, 42);
			INSERT_VEC(iteFt, itevector, 38);
			
			++itFt;
			++itvector;
			INSERT_VEC(itFt, itvector, 38);
			print("INSERT", "OK");
		}

		#define INSERT_VEC1(itFt, itvector, val, size)	\
			m_ftvector.insert(itFt, size, val);				\
			m_vector.insert(itvector, size, val);				\
			if (!(checkIdenticalvectors("INSERT1", 1)))	\
				return;

		void insert1()
		{
			typename ft::Iterator<T> itFt = m_ftvector.begin();
			typename ft::Iterator<T> iteFt = m_ftvector.end();
            typename std::vector<T>::iterator itvector = m_vector.begin();
            typename std::vector<T>::iterator itevector = m_vector.end();
		
			INSERT_VEC1(itFt, itvector, 100, 4);
			// m_ftvector.insert(iteFt, 100);
			// m_vector.insert(itevector, 100);
			// if (checkIdenticalvectors("INSERT1"))
			// 	print("INSERT", "OK");
			
			itFt = m_ftvector.begin();
			iteFt = m_ftvector.end();
            itvector = m_vector.begin();
            itevector = m_vector.end();
			INSERT_VEC1(iteFt, itevector, 100, 4);
		
			// itFt = m_ftvector.begin();
			// iteFt = m_ftvector.end();
            // itvector = m_vector.begin();
            // itevector = m_vector.end();
			// m_vector.insert(itvector, -1, 33);
			// m_ftvector.insert(itFt, -1, 33);
			//INSERT_VEC1(itFt, itvector, 333, -1); //fonctionne pas
			print("INSERT1", "OK");
		}

		void insert2()
		{
			std::vector<T> vector;
			vector.push_back(10);
			vector.push_back(11);

			ft::vector<T> ft_vector;
			ft_vector.push_back(10);
			ft_vector.push_back(11);

			typename ft::Iterator<T> itFt = m_ftvector.begin();
			typename std::vector<T>::iterator itvector = m_vector.begin();
			m_ftvector.insert(itFt, ft_vector.begin(), ft_vector.end());
			m_vector.insert(itvector, vector.begin(), vector.end());
			itFt = m_ftvector.begin();
			itvector = m_vector.begin();
			
			// if (checkIdenticalvectors("INSERT2", 1))
			// 	print("INSERT2", "OK");	
		    itFt++;
			itvector++;
			    
			// typename ft::Iterator<T> i = ft_vector.begin();
			// typename ft::Iterator<T> ie = ft_vector.end();
			// while(i !=ie)
			// {
			// 	std::cout << "I:" << *i <<std::endl;
			// 	i++;
			// }
			
			// typename std::vector<T>::iterator v = vector.begin();
			// typename std::vector<T>::iterator ve = vector.end();
			// while (v != ve)
			// {
			// 	std::cout << "V: " << *v << std::endl;
			// 	v++;
			// }
			m_ftvector.insert(itFt, ft_vector.begin(), ft_vector.end());
			m_vector.insert(itvector, vector.begin(), vector.end());
			if (checkIdenticalvectors("INSERT2", 1))
				print("INSERT2", "OK");	
		}

		#define ERASE_VEC(itFt, itvector, nameTest, lastTest)		\
			m_ftvector.erase(itFt);							\
			m_vector.erase(itvector);							\
			if (!lastTest)									\
				checkIdenticalvectors("ERASE");				\
			else											\
			{												\
				if (checkIdenticalvectors("ERASE"))		\
					print("ERASE", "OK");					\
			}
			
		void erase()
		{
			typename ft::Iterator<T> itFt = m_ftvector.begin();
			typename std::vector<T>::iterator itvector = m_vector.begin();
			typename ft::Iterator<T> iteFt = m_ftvector.end();
			typename std::vector<T>::iterator itevector = m_vector.end();
			
			ERASE_VEC(itFt, itvector, "ERASE", 1);
		//	ERASE(iteFt, itevector, "ERASE", 1); //normal segfault;
		
			itFt = m_ftvector.begin();// with std::vector, when doing itvector++ just after works
			itvector = m_vector.begin();
			++itFt;
			itvector++;
			ERASE_VEC(itFt, itvector, "ERASE", 1);
			
		}

		void erase2()
		{
			typename ft::Iterator<T> itFt = m_ftvector.begin();
			typename std::vector<T>::iterator itvector = m_vector.begin();
			typename ft::Iterator<T> iteFt = m_ftvector.end();
			typename std::vector<T>::iterator itevector = m_vector.end();	
			itFt++;
			itvector++;
			m_ftvector.erase(itFt, iteFt);
			m_vector.erase(itvector, itevector);
			if (checkIdenticalvectors("ERASE2"))
				print("ERASE2", "OK");
		}
		
		void swap()
		{
			std::vector<int> second;
			ft::vector<int> ft_second;
			second.push_back(6);
			second.push_back(36);
			second.push_back(21);
			second.push_back(2);
			ft_second.push_back(6);
			ft_second.push_back(36);
			ft_second.push_back(21);
			ft_second.push_back(2);
			m_ftvector.swap(ft_second);
			m_vector.swap(second);
			if (checkIdenticalvectors("SWAP") && checkIdenticalvectors(second, ft_second, "SWAP"))
				print("SWAP", "OK");
		}

		
		
	// 	void resize()
	// 	{
	// 		m_ftvector.resize(2);
	// 		m_vector.resize(2);
	// 		if (checkIdenticalvectors("RESIZE"))
	// 			print("RESIZE", "OK");
	// 		m_ftvector.resize(6);
	// 		m_vector.resize(6);
	// 		if (checkIdenticalvectors("RESIZE 2"))
	// 			print("RESIZE 2", "OK");
	// 	}

		
	// 	void clear()
	// 	{
	// 		int array[3] = {6, 7, 8};
			
	// 		m_ftvector.clear();
	// 		m_vector.clear();
	// 		checkIdenticalvectors("CLEAR");
			
	// 		init(array, 3);
	// 		checkIdenticalvectors("CLEAR");
	// 		m_ftvector.clear();
	// 		m_vector.clear();
	// 		if (checkIdenticalvectors("CLEAR"))
	// 			print("CLEAR", "OK");
	// 	}
	// 	void splice()
	// 	{
	// 		int array[3] = {6, 7, 8};
	// 		init(array, 3);
			
	// 		ft::vector<int> m_other;
	// 		std::vector<int> other;
	// 		for (int i = 0 ; i < 3; i++)
	// 		{
	// 			m_other.push_back(9);
	// 			other.push_back(9);
	// 		}
			
	// 		ft::vectorIterator<T> it= m_ftvector.begin();
	// 		ft::vectorIterator<T> ite = m_ftvector.end();
	// 		while (it != ite)
	// 			it++;
		
	// 		ft::vectorIterator<T> itt = m_ftvector.begin();
	// 		typename std::vector<T>::iterator ipp = m_vector.begin();
	
	// 		m_ftvector.splice(itt, m_other);
	// 		m_vector.splice(ipp, other);
			
	// 		if (checkIdenticalvectors("SPLICE 1"))
	// 			print("SPLICE 1", "OK");
			
	// 		ft::vector<int> m_newOther;
	// 		std::vector<int> newOther;
	// 		for (int i = 0 ; i < 3; i++)
	// 		{
	// 			m_newOther.push_back(3);
	// 			newOther.push_back(3);
	// 		}
	// 		m_newOther.push_back(4);
	// 		newOther.push_back(4);
	// 		ft::vectorIterator<T> itOther = m_newOther.begin();
	// 		typename std::vector<T>::iterator ipOther = newOther.begin();
	// 		for (int i = 0; i < 2; i++)
	// 		{
	// 			itOther++;
	// 			ipOther++;
	// 		}
	// 		m_ftvector.splice(itt, m_newOther, itOther);
	// 		m_vector.splice(ipp, newOther, ipOther);
			
	// 		if (checkIdenticalvectors("SPLICE 2"))
	// 			print("SPLICE 2", "OK");

	// 		ft::vector<int> m_newOther2;
	// 		std::vector<int> newOther2;
	// 		for (int i = 0 ; i < 3; i++)
	// 		{
	// 			m_newOther2.push_back(5);
	// 			newOther2.push_back(5);
	// 		}
	// 		m_newOther2.push_back(7);
	// 		newOther2.push_back(7);
	// 		ft::vectorIterator<T> itOther2 = m_newOther2.begin();
	// 		typename std::vector<T>::iterator ipOther2 = newOther2.begin();
	// 		for (int i = 0; i < 2; i++)
	// 		{
	// 			itOther2++;
	// 			ipOther2++;
	// 		}
	// 		m_ftvector.splice(itt, m_newOther2, itOther2);
	// 		m_vector.splice(ipp, newOther2, ipOther2);

	// 		if (checkIdenticalvectors("SPLICE 3"))
	// 			print("SPLICE 3", "OK");
	// 	}

	// 	void sort()
	// 	{
	// 		m_vector.push_back (3);
	// 		m_vector.push_back (2);
	// 		m_vector.push_back (5);
	// 		m_vector.sort();

			
	// 		m_ftvector.push_back (3);
	// 		m_ftvector.push_back (2);
	// 		m_ftvector.push_back (5);
 	// 		m_ftvector.sort();

	// 		if (checkIdenticalvectors("SORT"))
	// 			print("SORT", "OK");

	// 		m_vector.push_back (54);
	// 		m_vector.push_back (4);
	// 		m_vector.push_back (10);
	// 		m_vector.sort(mycomparison);

			
	// 		m_ftvector.push_back (54);
	// 		m_ftvector.push_back (4);
	// 		m_ftvector.push_back (10);
 	// 		m_ftvector.sort(mycomparison);

	// 		if (checkIdenticalvectors("SORT2"))
	// 			print("SORT2", "OK");
	// 	}
		
		
	// 	void merge()
	// 	{
	// 		std::vector<int> second;
	// 		second.push_back (6);
	// 		second.push_back (1);
	// 		second.push_back (4);
	// 		second.sort();
	// 		m_vector.merge(second);

	// 		ft::vector<int> ft_second;
	// 		ft_second.push_back (6);
	// 		ft_second.push_back (1);
	// 		ft_second.push_back (4);
	// 		ft_second.sort();
		
	// 		m_ftvector.merge(ft_second);
		
	// 		if (checkIdenticalvectors("MERGE"))
	// 			print("MERGE", "OK");

	// 		std::vector<int> second2;
	// 		ft::vector<int> ft_second2;
	// 		second2.push_back(2);	
	// 		ft_second2.push_back(2);
	// 		m_vector.merge(second2, mycomparison);
	// 		m_ftvector.merge(ft_second2, mycomparison);

	// 		if (checkIdenticalvectors("MERGE2"))
	// 			print("MERGE2", "OK");
	// 	}

	// 	void reverse()
	// 	{
	// 		m_ftvector.reverse();
	// 		m_vector.reverse();
	// 		if (checkIdenticalvectors("REVERSE"))
	// 			print("REVERSE", "OK");
	// 	}

	// 	void rendIncrement()
	// 	{
	// 		typename ft::vector<T>::reverse_iterator ft_r = m_ftvector.rbegin();
	// 		typename ft::vector<T>::reverse_iterator ft_re = m_ftvector.rend();
	// 		typename std::vector<T>::reverse_iterator r = m_vector.rbegin();
	// 		typename std::vector<T>::reverse_iterator re = m_vector.rend();
	// 		while(ft_r != ft_re && r != re)
	// 		{
	// 			if (*ft_r != *r)
	// 			{
	// 				print("REND", "WRONG");
	// 				return;
	// 			}
	// 			ft_r++;
	// 			r++;
	// 		}
	// 		if (ft_r == ft_re && r == re)
	// 			print("REND", "OK");
	// 		else
	// 			print("REND", "WRONG");
	// 	}


};
#endif