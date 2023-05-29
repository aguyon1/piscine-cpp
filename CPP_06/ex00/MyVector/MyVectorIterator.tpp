/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyVectorIterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:20:34 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/22 14:17:13 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MyVector<T>::Iterator::Iterator(T* ptr)
	: m_ptr(ptr)
{}

template<typename T>
MyVector<T>::Iterator::Iterator(const Iterator& other)
{
	*this = other;
}

template<typename T>
MyVector<T>::Iterator::~Iterator(){}

template<typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator=(const Iterator& other)
{
	m_ptr = other.m_ptr;
	return (*this);
}

template<typename T>
T& MyVector<T>::Iterator::operator*() const
{
	return (*m_ptr);
}

template<typename T>
T* MyVector<T>::Iterator::operator->()
{
	return (m_ptr);
}

template<typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator++()
{
	m_ptr++;
	return (*this);
}

template<typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator++(int)
{
	Iterator tmp = *this;
	++(*this);
	return (tmp);
}

template<typename T>
bool MyVector<T>::Iterator::operator==(const Iterator& other) const
{
	return (m_ptr == other.m_ptr);
}

template<typename T>
bool MyVector<T>::Iterator::operator!=(const Iterator& other) const
{
	return (m_ptr != other.m_ptr);
}
