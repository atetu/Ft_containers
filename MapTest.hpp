/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:32 by alicetetu         #+#    #+#             */
/*   Updated: 2021/03/04 16:40:37 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPTEST_HPP
# define MAPTEST_HPP

#include <memory>
#include <iostream>

#include "Map.hpp"
#include<map>


template <typename Key, typename T>
class MapTest
{
    private:
        ft::map<Key, T> m_ftmap;
        std::deque<Key, T> m_map;
		// ft::deque<const T> m_ftconstdeque;
        // std::deque<const T> m_constdeque;

    public:
        MapTest<Key, T>()
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
        
};
#endif
