/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyVector.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:03:51 by aguyon            #+#    #+#             */
/*   Updated: 2023/05/22 15:04:43 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MyVector<T>::MyVector(void)
	: _array(new T[1]), _capacity(1), _current(0)
{}

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
{
	*this = other;
}

template<typename T>
MyVector<T>::~MyVector(void)
{
	delete [] _array;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	_array = new T[other._capacity];
	_capacity = other._capacity;
	_current = other._current;
	for (size_t i = 0; i < other.size(); i++)
		_array[i] = other._array[i];
	return (*this);
}

template<typename T>
void MyVector<T>::double_capacity(void)
{
	T* temp = new T[2 * _capacity];

	for (size_t i = 0; i < _capacity; i++)
		temp[i] = _array[i];
	delete [] _array;
	_capacity *= 2;
	_array = temp;
}

template<typename T>
void MyVector<T>::push_back(const T& data)
{
	if (_current == _capacity)
		double_capacity();
	_array[_current++] = data;
}

template<typename T>
void MyVector<T>::pop_back(void)
{
	_current--;
}

template<typename T>
size_t MyVector<T>::size(void) const
{
	return (_current);
}

template<typename T>
size_t MyVector<T>::getcapacity(void) const
{
	return (_capacity);
}

template<typename T>
T& MyVector<T>::operator[](size_t pos) const
{
	if (pos >= size())
		throw std::out_of_range("vector index out of range");
	return (_array[pos]);
}

template<typename T>
typename MyVector<T>::Iterator MyVector<T>::begin()
{
	return (MyVector<T>::Iterator(&_array[0]));
}

template<typename T>
typename MyVector<T>::Iterator MyVector<T>::end()
{
	return (MyVector<T>::Iterator(&_array[_current]));
}
