/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:47:13 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/22 23:13:14 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename ELEMENT>
Array<ELEMENT>::Array(void) : _array(NULL), _size(0)
{
	return;
}

template <typename ELEMENT>
Array<ELEMENT>::Array(unsigned int n) : _array(new ELEMENT[n]), _size(n)
{
	for (unsigned int i = 0; i < this->size(); i++)
		_array[i] = ELEMENT();
	return;
}

template <typename ELEMENT>
Array<ELEMENT>::Array(const Array<ELEMENT>& other) : _array(new ELEMENT[other.size()]), _size(other.size())
{
	for (unsigned int i = 0; i < this->size(); i++)
		_array[i] = other._array[i];
	return;
}

template <typename ELEMENT>
Array<ELEMENT>::~Array(void)
{
	delete [] _array;
	return;
}

template <typename ELEMENT>
ELEMENT&	Array<ELEMENT>::operator[](unsigned int pos) const
{
	if (pos >= this->size())
		throw std::out_of_range("array index out of range");
	return (this->_array[pos]);
}

template <typename ELEMENT>
unsigned int	Array<ELEMENT>::size(void) const
{
	return (this->_size);
}

template <typename ELEMENT>
std::ostream&	operator<<(std::ostream& os, const Array<ELEMENT>& array)
{
	const unsigned int arraySize = array.size();

	os << "[";
	for (unsigned int i = 0; i < arraySize; i++)
	{
		os << array[i];
		if (i < (arraySize - 1))
			os << ", ";
	}
	os << "]";
	return (os);
}
