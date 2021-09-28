#include "tenzor.h"
#include <stdio.h>
#include <iostream>

template<typename T>
inline tenzor<T>::tenzor()
{
	x_size = 0;
	y_size = 0;
	data_p = NULL;
}

template<typename T>
tenzor<T>::~tenzor()
{
	free(data_p);
}

template<typename T>
tenzor<T>::tenzor(int x_size, int y_size)
{
	this->x_size = x_size;
	this->y_size = y_size;

	data_p = reinterpret_cast<T*>(calloc(x_size * y_size, sizeof(T)));
}

template<typename T>
T& tenzor<T>::operator[](const int pos)
{
	T* address = data_p;
	return address[pos];
}

template<typename T>
tenzor<T> tenzor<T>::operator+(tenzor<T> other) // Pass with reference!
{
	tenzor<T> output(other.x_size,other.y_size);

	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			output.get(i, j) = this->get(i, j) + other.get(i,j);
		}
	}
	return output;
}

//template<typename T>
//T& tenzor<T>::operator-(const T other)
//{
//	// TODO: insert return statement here
//}

template<typename T>
T& tenzor<T>::get(const int x, const int y)
{
	T* address = data_p;
	return address[y*x_size+x];
}

template<typename T>
void tenzor<T>::print()
{
	std::cout << "matrix:" << typeid(this).name() << std::endl;

	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			std::cout << this->get(i, j) << "\t";
		}
		std::cout << std::endl;
	}
}


template class tenzor<int>;
template class tenzor<char>;
template class tenzor<double>;