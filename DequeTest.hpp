/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:52:45 by atetu             #+#    #+#             */
/*   Updated: 2021/03/12 15:51:12 by atetu            ###   ########.fr       */
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
			m_ftdeque = ftl;
			std::deque<T> l(size, val);
			m_deque = l;
			if(checkIdenticaldeques("INIT_SIZE_VAL", 1))
				print("INIT_SIZE_VAL", "OK");
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

    //     #define CHECK_VALUES_VEC(apply, name)                     \
    //         if (m_ftdeque.apply() != m_deque.apply())             \
    //             print(name, "WRONG");                       \
    //         else                                                \
    //             print(name, "OK");        
                
    //     void begin()
    //     {
    //         if ((*m_ftdeque.begin()) != (*m_deque.begin()))
    //             print("BEGIN", "WRONG");
    //         else
    //             print("BEGIN", "OK");
    //     }
       
    //    void end()
    //     {
    //         typename ft::Iterator<T> itFT = m_ftdeque.end();
    //         typename std::deque<T>::iterator itdeque = m_deque.end();
    //         if ((*(--itFT)) != (*(--itdeque)))
    //             print("END", "WRONG");
    //         else
    //             print("END", "OK");
    //     }
		
	// 	void beginconst()
	// 	{
	// 		beginconsttest(m_ftdeque, m_deque);
	// 	}
		
	// 	void beginconsttest(const ft::deque<T> &ft_vec, const std::deque<T> &vec)
    //     {
    //         if ((*ft_vec.begin()) != (*vec.begin()))
    //             print("BEGIN CONST", "WRONG");
    //         else
    //             print("BEGIN CONST", "OK");
    //     }
            
	//   	void endconst()
	// 	{
	// 		endconsttest(m_ftdeque, m_deque);
	// 	}
		
	// 	void endconsttest(const ft::deque<T> &ft_vec, const std::deque<T> &vec)
    //     {
    //         typename ft::ConstIterator<T> itFT = ft_vec.end();
    //         typename std::deque<T>::const_iterator itdeque = vec.end();
    //         if ((*(--itFT)) != (*(--itdeque)))
    //             print("END CONST", "WRONG");
    //         else
    //             print("END CONST", "OK");
    //     }

    //     void size()
    //     {
    //         CHECK_VALUES_VEC(size, "SIZE");
    //     }

	// 	void maxSize()
	// 	{
	// 		CHECK_VALUES_VEC(max_size, "MAX_SIZE");
	// 	}

	// 	void resize()
	// 	{
	// 		m_ftdeque.resize(2);
	// 		m_deque.resize(2);
	// 		if(checkIdenticaldeques("RESIZE 1", 1))
	// 			print("RESIZE 1", "OK");

	// 		m_ftdeque.resize(0);
	// 		m_deque.resize(0);
	// 		if(checkIdenticaldeques("RESIZE 2"))
	// 			print("RESIZE 2", "OK");
				
	// 		m_ftdeque.resize(5, 24);
	// 		m_deque.resize(5, 24);
	// 		if(checkIdenticaldeques("RESIZE 3"))
	// 			print("RESIZE 3", "OK");
	// 	}
		
	// 	void capacity()
    //     {
    //         CHECK_VALUES_VEC(capacity, "CAPACITY");
    //     }
		
	// 	void empty()
    //     {
    //         CHECK_VALUES_VEC(empty, "EMPTY");
    //     }

    // //     void assign()
    // //     {}

	// //  	void push_front()
    // //     {
    // //         m_ftdeque.push_front(50);
          
    // //         m_deque.push_front(50);
	// // 		if(checkIdenticaldeques("PUSH_FRONT"))
	// // 			print("PUSH_FRONT", "OK");
    // //     }
		

	// 	void operator_access()
	// 	{
	// 		for (size_t i = 0 ; i < m_ftdeque.size(); i++)
	// 		{
	// 			if (!(m_ftdeque[i] == m_deque[i]))
	// 				print("[]", "WRONG");
	// 		}
	// 		print("[]", "OK");
	// 	}
		
	// 	void at()
	// 	{
	// 		try
	// 		{
		
			
	// 			size_t i = 0;
	// 			for (; i < m_ftdeque.size(); i++)
	// 			{
	// 				if (!(m_ftdeque.at(i) == m_deque.at(i)))
	// 					print("AT", "WRONG");
	// 			}
	// 			i = m_ftdeque.size() + 1;
	// 			// std::cout << "After end ft: " << m_ftdeque.at(i) << std::endl;
	// 			// std::cout << "After end vec: " << m_deque.at(i) << std::endl;
				
	// 			print("AT", "OK");
	// 		}
	// 		catch(const std::exception& e)
	// 		{
	// 			std::cerr << "ERROR: " << e.what() << '\n';
	// 			return;
	// 		}
	// 	}

	// 	void front()
	// 	{
	// 		// std::cout <<  m_deque.front() << std::endl;
	// 		// std::cout <<  m_ftdeque.front() << std::endl;
	// 		if (m_ftdeque.front() == m_deque.front())
	// 			print("FRONT", "OK");
	// 		else
	// 			print("FRONT", "WRONG");			
	// 	}
		
	// 	void back()
	// 	{
	// 		// std::cout <<  m_deque.back() << std::endl;
	// 		// std::cout <<  m_ftdeque.back() << std::endl;
	// 		if (m_ftdeque.back() == m_deque.back())
	// 			print("BACK", "OK");
	// 		else
	// 			print("BACK", "WRONG");			
	// 	}
		
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
		//	m_deque.pop_back();
			// m_ftdeque.pop_back();
			// 	m_ftdeque.pop_back();
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
		
	// 	#define INSERT_VEC(itFt, itdeque, val)			\
	// 		m_ftdeque.insert(itFt, val);				\
	// 		m_deque.insert(itdeque, val);				\
	// 		if (!(checkIdenticaldeques("INSERT", 1)))	\
	// 			return;
				
	// 	void insert()
	// 	{
	// 		typename ft::Iterator<T> itFt = m_ftdeque.begin();
	// 		typename ft::Iterator<T> iteFt = m_ftdeque.end();
    //         typename std::deque<T>::iterator itdeque = m_deque.begin();
    //         typename std::deque<T>::iterator itedeque = m_deque.end();
		
	// 		INSERT_VEC(itFt, itdeque, 42);
	// 		INSERT_VEC(iteFt, itedeque, 38);
			
	// 		++itFt;
	// 		++itdeque;
	// 		INSERT_VEC(itFt, itdeque, 38);
	// 		print("INSERT", "OK");
	// 	}

	// 	#define INSERT_VEC1(itFt, itdeque, val, size)	\
	// 		m_ftdeque.insert(itFt, size, val);				\
	// 		m_deque.insert(itdeque, size, val);				\
	// 		if (!(checkIdenticaldeques("INSERT1", 1)))	\
	// 			return;

	// 	void insert1()
	// 	{
	// 		typename ft::Iterator<T> itFt = m_ftdeque.begin();
	// 		typename ft::Iterator<T> iteFt = m_ftdeque.end();
    //         typename std::deque<T>::iterator itdeque = m_deque.begin();
    //         typename std::deque<T>::iterator itedeque = m_deque.end();
		
	// 		INSERT_VEC1(itFt, itdeque, 100, 4);
	// 		// m_ftdeque.insert(iteFt, 100);
	// 		// m_deque.insert(itedeque, 100);
	// 		// if (checkIdenticaldeques("INSERT1"))
	// 		// 	print("INSERT", "OK");
			
	// 		itFt = m_ftdeque.begin();
	// 		iteFt = m_ftdeque.end();
    //         itdeque = m_deque.begin();
    //         itedeque = m_deque.end();
	// 		INSERT_VEC1(iteFt, itedeque, 100, 4);
		
	// 		// itFt = m_ftdeque.begin();
	// 		// iteFt = m_ftdeque.end();
    //         // itdeque = m_deque.begin();
    //         // itedeque = m_deque.end();
	// 		// m_deque.insert(itdeque, -1, 33);
	// 		// m_ftdeque.insert(itFt, -1, 33);
	// 		//INSERT_VEC1(itFt, itdeque, 333, -1); //fonctionne pas
	// 		print("INSERT1", "OK");
	// 	}

	// 	void insert2()
	// 	{
	// 		std::deque<T> deque;
	// 		deque.push_back(10);
	// 		deque.push_back(11);

	// 		ft::deque<T> ft_deque;
	// 		ft_deque.push_back(10);
	// 		ft_deque.push_back(11);

	// 		typename ft::Iterator<T> itFt = m_ftdeque.begin();
	// 		typename std::deque<T>::iterator itdeque = m_deque.begin();
	// 		m_ftdeque.insert(itFt, ft_deque.begin(), ft_deque.end());
	// 		m_deque.insert(itdeque, deque.begin(), deque.end());
	// 		itFt = m_ftdeque.begin();
	// 		itdeque = m_deque.begin();
			
	// 		// if (checkIdenticaldeques("INSERT2", 1))
	// 		// 	print("INSERT2", "OK");	
	// 	    itFt++;
	// 		itdeque++;
			    
	// 		// typename ft::Iterator<T> i = ft_deque.begin();
	// 		// typename ft::Iterator<T> ie = ft_deque.end();
	// 		// while(i !=ie)
	// 		// {
	// 		// 	std::cout << "I:" << *i <<std::endl;
	// 		// 	i++;
	// 		// }
			
	// 		// typename std::deque<T>::iterator v = deque.begin();
	// 		// typename std::deque<T>::iterator ve = deque.end();
	// 		// while (v != ve)
	// 		// {
	// 		// 	std::cout << "V: " << *v << std::endl;
	// 		// 	v++;
	// 		// }
	// 		m_ftdeque.insert(itFt, ft_deque.begin(), ft_deque.end());
	// 		m_deque.insert(itdeque, deque.begin(), deque.end());
	// 		if (checkIdenticaldeques("INSERT2", 1))
	// 			print("INSERT2", "OK");	
	// 	}

	// 	#define ERASE_VEC(itFt, itdeque, nameTest, lastTest)		\
	// 		m_ftdeque.erase(itFt);							\
	// 		m_deque.erase(itdeque);							\
	// 		if (!lastTest)									\
	// 			checkIdenticaldeques("ERASE");				\
	// 		else											\
	// 		{												\
	// 			if (checkIdenticaldeques("ERASE"))		\
	// 				print("ERASE", "OK");					\
	// 		}
			
	// 	void erase()
	// 	{
	// 		typename ft::Iterator<T> itFt = m_ftdeque.begin();
	// 		typename std::deque<T>::iterator itdeque = m_deque.begin();
	// 		typename ft::Iterator<T> iteFt = m_ftdeque.end();
	// 		typename std::deque<T>::iterator itedeque = m_deque.end();
			
	// 		ERASE_VEC(itFt, itdeque, "ERASE", 1);
	// 	//	ERASE(iteFt, itedeque, "ERASE", 1); //normal segfault;
		
	// 		itFt = m_ftdeque.begin();// with std::deque, when doing itdeque++ just after works
	// 		itdeque = m_deque.begin();
	// 		++itFt;
	// 		itdeque++;
	// 		ERASE_VEC(itFt, itdeque, "ERASE", 1);
			
	// 	}

	// 	void erase2()
	// 	{
	// 		typename ft::Iterator<T> itFt = m_ftdeque.begin();
	// 		typename std::deque<T>::iterator itdeque = m_deque.begin();
	// 		typename ft::Iterator<T> iteFt = m_ftdeque.end();
	// 		typename std::deque<T>::iterator itedeque = m_deque.end();	
	// 		itFt++;
	// 		itdeque++;
	// 		m_ftdeque.erase(itFt, iteFt);
	// 		m_deque.erase(itdeque, itedeque);
	// 		if (checkIdenticaldeques("ERASE2"))
	// 			print("ERASE2", "OK");
	// 	}
		
	// 	void swap()
	// 	{
	// 		std::deque<int> second;
	// 		ft::deque<int> ft_second;
	// 		second.push_back(6);
	// 		second.push_back(36);
	// 		second.push_back(21);
	// 		second.push_back(2);
	// 		ft_second.push_back(6);
	// 		ft_second.push_back(36);
	// 		ft_second.push_back(21);
	// 		ft_second.push_back(2);
	// 		m_ftdeque.swap(ft_second);
	// 		m_deque.swap(second);
	// 		if (checkIdenticaldeques("SWAP") && checkIdenticaldeques(second, ft_second, "SWAP"))
	// 			print("SWAP", "OK");
	// 	}
};