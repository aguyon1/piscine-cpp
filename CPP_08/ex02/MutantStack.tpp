/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:05:01 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/26 09:39:04 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
	: std::stack<T>()
{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(typename std::stack<T>::size_type count)
	: std::stack<T>()
{
	for (typename std::stack<T>::size_type i = 0; i < count; i++)
		this->push(T());
}


template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
{
	*this = other;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other)
{
	std::stack<T>::operator=(other);
	return (*this);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cbegin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cend() const
{
	return (std::stack<T>::c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return (std::stack<T>::c.rend());
}


template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crend() const
{
	return (std::stack<T>::c.rend());
}
