/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:08:50 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 15:16:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
	//https://en.cppreference.com/w/cpp/types/enable_if
	template<bool B, class T = void> struct allow_if
	{
	};
	
	template<class T> struct allow_if<true, T>
	{
		typedef T type;
	};
};
#endif
