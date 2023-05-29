/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:54:55 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/22 14:13:50 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

template <typename T>
class MyVector
{
private:
	T* _array;
	size_t _capacity;
	size_t _current;

	void double_capacity(void);
public:
	MyVector(void);
	MyVector(const MyVector& other);
	~MyVector(void);

	MyVector& operator=(const MyVector& other);

	void push_back(const T& data);
	void pop_back(void);

	T& operator[](size_t pos) const;

	size_t size(void) const;

	size_t getcapacity(void) const;

	class Iterator;
	Iterator begin();
	Iterator end();
};

template <typename T>
class MyVector<T>::Iterator
{
public:
	Iterator(T* ptr);
	Iterator(const Iterator& other);
	~Iterator();

	Iterator& operator=(const Iterator& other);
	T& operator*() const;
	T* operator->();
	Iterator& operator++();
	Iterator operator++(int);
	bool operator==(const Iterator& other) const;
	bool operator!=(const Iterator& other) const;

private:
	T* m_ptr;

	Iterator();
};

#include "MyVector.tpp"
#include "MyVectorIterator.tpp"

#endif