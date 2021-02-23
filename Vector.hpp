/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <alicetetu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:17:43 by alicetetu         #+#    #+#             */
/*   Updated: 2021/02/08 12:17:50 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define LIST_HPP

#include <memory>
#include <iostream>
#include "Iterator.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> > 