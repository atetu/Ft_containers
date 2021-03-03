/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <atetu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:52:45 by atetu             #+#    #+#             */
/*   Updated: 2021/03/03 15:16:20 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define StackTest_HPP

#include <memory>
#include <iostream>

#include "Stack.hpp"
#include<stack>

bool mycomparison (int first, double second);

template <typename T>
class StackTest
{
    private:
        ft::stack<T> m_ftstack;
        std::stack<T> m_stack;
		// ft::stack<const T> m_ftconststack;
        // std::stack<const T> m_conststack;

    public:
        StackTest<T>()
        {
			ft::stack<T> ftv;
			std::stack<T>v;
			m_ftstack = ftv;
			m_stack = v;
			
			if(checkIdenticalstacks("INIT_EMPTY"))
				print("INIT_EMPTY", "OK");
			// m_ftconststack(42, 4);
			// m_conststack(42, 4);
        }
        
       		
		
		
        static void
        print(const std::string& test, const std::string & result)
        {
            std::cout << "Test " << test << " : " << result << std::endl;
        }
        
		int checkIdenticalstacks(std::string testName, int writeOption = 0)
        {
            // typename ft::stack<T>::iterator itFtstack = m_ftstack.begin();
            // typename ft::stack<T>::iterator iteFtstack = m_ftstack.end();
            // typename std::stack<T>::iterator itstack = m_stack.begin();
            // typename std::stack<T>::iterator itestack = m_stack.end();

			// while(itstack != itestack)
			// {
			// 	std::cout << "stack: "<< *itstack << std::endl;
			// 	itstack++;
			// }
			// while(itFtstack != iteFtstack)
			// {
			// 	std::cout << "FT: "<< *itFtstack << std::endl;
			// 	itFtstack++;
			// }
			if (m_ftstack.size() && m_stack.size())
			{
				std::cout << "SIZE: " << m_ftstack.size() << "-" << m_stack.size() << std::endl;
				while (m_ftstack.size()) //&& itstack != itestack)
				//  for (int i = 0; i < 3; i++)
				{
					if (writeOption)
						std::cout <<m_ftstack.top() << "-" << m_stack.top() << std::endl;
					if (m_ftstack.top() != m_stack.top())
					{
						print(testName, "WRONG1");
						return(0);
					}
					m_ftstack.pop();
					m_stack.pop();
				}
				
				if (m_ftstack.size() != m_stack.size())
				{
					print(testName, "WRONG2");
					return(0);
				}
			}
			else if (m_ftstack.size() != m_stack.size())
			{
				std::cout << "FT stack size : " << m_ftstack.size() << std::endl;
					std::cout << "stack size : " << m_stack.size() << std::endl;
				print(testName, "WRONG3");
				return(0);
			}
       		return(1);
        }

		template <typename Y>
		static int checkIdenticalstacks(std::stack<Y> &x, ft::stack<Y> &y, std::string testName, int writeOption = 0)
        {
         
          if (x.size() && y.size())
			{
				std::cout << "SIZE: " << y.size() << "-" << x.size() << std::endl;
				while (y.size()) //&& itstack != itestack)
				//  for (int i = 0; i < 3; i++)
				{
					if (writeOption)
						std::cout <<y.top() << "-" << x.top() << std::endl;
					if (y.top() != x.top())
					{
						print(testName, "WRONG1");
						return(0);
					}
					y.pop();
					x.pop();
				}
				
				if (y.size() != x.size())
				{
					print(testName, "WRONG2");
					return(0);
				}
			}
			else if (y.size() != x.size())
			{
				std::cout << "FT stack size : " << y.size() << std::endl;
					std::cout << "stack size : " << x.size() << std::endl;
				print(testName, "WRONG3");
				return(0);
			}
       		return(1);
        }

    //     #define CHECK_VALUES_VEC(apply, name)                     \
    //         if (m_ftstack.apply() != m_stack.apply())             \
    //             print(name, "WRONG");                       \
    //         else                                                \
    //             print(name, "OK");        
                
    //     void begin()
    //     {
    //         if ((*m_ftstack.begin()) != (*m_stack.begin()))
    //             print("BEGIN", "WRONG");
    //         else
    //             print("BEGIN", "OK");
    //     }
       
    //    void end()
    //     {
    //         typename ft::Iterator<T> itFT = m_ftstack.end();
    //         typename std::stack<T>::iterator itstack = m_stack.end();
    //         if ((*(--itFT)) != (*(--itstack)))
    //             print("END", "WRONG");
    //         else
    //             print("END", "OK");
    //     }
		
	// 	void beginconst()
	// 	{
	// 		beginconsttest(m_ftstack, m_stack);
	// 	}
		
	// 	void beginconsttest(const ft::stack<T> &ft_vec, const std::stack<T> &vec)
    //     {
    //         if ((*ft_vec.begin()) != (*vec.begin()))
    //             print("BEGIN CONST", "WRONG");
    //         else
    //             print("BEGIN CONST", "OK");
    //     }
            
	//   	void endconst()
	// 	{
	// 		endconsttest(m_ftstack, m_stack);
	// 	}
		
	// 	void endconsttest(const ft::stack<T> &ft_vec, const std::stack<T> &vec)
    //     {
    //         typename ft::ConstIterator<T> itFT = ft_vec.end();
    //         typename std::stack<T>::const_iterator itstack = vec.end();
    //         if ((*(--itFT)) != (*(--itstack)))
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
	// 		m_ftstack.resize(2);
	// 		m_stack.resize(2);
	// 		if(checkIdenticalstacks("RESIZE 1", 1))
	// 			print("RESIZE 1", "OK");

	// 		m_ftstack.resize(0);
	// 		m_stack.resize(0);
	// 		if(checkIdenticalstacks("RESIZE 2"))
	// 			print("RESIZE 2", "OK");
				
	// 		m_ftstack.resize(5, 24);
	// 		m_stack.resize(5, 24);
	// 		if(checkIdenticalstacks("RESIZE 3"))
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
    // //         m_ftstack.push_front(50);
          
    // //         m_stack.push_front(50);
	// // 		if(checkIdenticalstacks("PUSH_FRONT"))
	// // 			print("PUSH_FRONT", "OK");
    // //     }
		

	// 	void operator_access()
	// 	{
	// 		for (size_t i = 0 ; i < m_ftstack.size(); i++)
	// 		{
	// 			if (!(m_ftstack[i] == m_stack[i]))
	// 				print("[]", "WRONG");
	// 		}
	// 		print("[]", "OK");
	// 	}
		
	// 	void at()
	// 	{
	// 		try
	// 		{
		
			
	// 			size_t i = 0;
	// 			for (; i < m_ftstack.size(); i++)
	// 			{
	// 				if (!(m_ftstack.at(i) == m_stack.at(i)))
	// 					print("AT", "WRONG");
	// 			}
	// 			i = m_ftstack.size() + 1;
	// 			// std::cout << "After end ft: " << m_ftstack.at(i) << std::endl;
	// 			// std::cout << "After end vec: " << m_stack.at(i) << std::endl;
				
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
	// 		// std::cout <<  m_stack.front() << std::endl;
	// 		// std::cout <<  m_ftstack.front() << std::endl;
	// 		if (m_ftstack.front() == m_stack.front())
	// 			print("FRONT", "OK");
	// 		else
	// 			print("FRONT", "WRONG");			
	// 	}
		
	// 	void back()
	// 	{
	// 		// std::cout <<  m_stack.back() << std::endl;
	// 		// std::cout <<  m_ftstack.back() << std::endl;
	// 		if (m_ftstack.back() == m_stack.back())
	// 			print("BACK", "OK");
	// 		else
	// 			print("BACK", "WRONG");			
	// 	}
		
        void push_back()
        {
            m_ftstack.push(6);
          
            m_stack.push(6);
			if(checkIdenticalstacks("PUSH_BACK", 1))
				print("PUSH_BACK", "OK");
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
			if ( m_ftstack.empty() == m_stack.empty())
				print("EMPTY", "OK");
			else
				print("EMPTY", "WRONG");
		}

		void size()
		{
			if ( m_ftstack.size() == m_stack.size())
				print("SIZE", "OK");
			else
				print("SIZE", "WRONG");
		}
		
		void top()
		{
			if ( m_ftstack.top() == m_stack.top())
				print("TOP", "OK");
			else
				print("TOP", "WRONG");
		}

		void pop()
		{
			m_ftstack.pop();
			m_stack.pop();
			if(checkIdenticalstacks("POP", 1))
				print("POP", "OK");
		}
		
		void push()
        {
            m_ftstack.push(6);
            m_stack.push(6);
			if(checkIdenticalstacks("PUSH", 1))
				print("PUSH", "OK");
			m_ftstack.push(6);
            m_stack.push(6);
			
			if(checkIdenticalstacks("PUSH", 1))
				print("PUSH", "OK");
        }

       
};