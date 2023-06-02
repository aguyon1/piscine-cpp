/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:09:19 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/31 13:33:58 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iterator>

#ifndef K
	#define K 100
#endif

template<typename InputIt>
InputIt next(InputIt it, typename std::iterator_traits<InputIt>::difference_type n = 1)
{
	std::advance(it, n);
	return (it);
}

template <typename InputIt>
void insertionSort(InputIt first, InputIt last)
{
	for (InputIt it = first; it != last; ++it)
		std::rotate(std::upper_bound(first, it, *it), it, next(it));
}

template <typename InputIt>
void mergeInsertSort(InputIt first, InputIt last)
{
	typename std::iterator_traits<InputIt>::difference_type const size = std::distance(first, last);
	if (size > K)
	{
		InputIt middleIt = next(first, size / 2);
		mergeInsertSort(first, middleIt);
		mergeInsertSort(middleIt, last);
		std::inplace_merge(first, middleIt, last);
	}
	else
	{
		insertionSort(first, last);
	}
}

#endif