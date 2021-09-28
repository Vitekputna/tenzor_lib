#include "Identity.h"
#include "tenzor.h"
#include <stdio.h>
#include <iostream>

template<typename T>
Identity<T>::Identity(){}

template<typename T>
Identity<T>::~Identity(){}

template<typename T>
Identity<T>::Identity(int x_size, int y_size)
{
	this->x_size = x_size;
	this->y_size = y_size;

	this->data_p = reinterpret_cast<T*>(calloc(x_size * y_size, sizeof(T)));

	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			if(i == j)
			{
				this->data_p[j * x_size + i] = 1;
			}
		}
	}
}

template<typename T>
void Identity<T>::print()
{
	std::cout << "identity:" << typeid(this).name() << std::endl;

	for (int i = 0; i < this->x_size; i++)
	{
		for (int j = 0; j < this->y_size; j++)
		{
			std::cout << this->get(i, j) << "\t";
		}
		std::cout << std::endl;
	}
}

template class Identity<int>;
template class Identity<char>;
template class Identity<double>;