#include "Identity.h"
#include "matrix.h"
#include <stdio.h>
#include <iostream>

template<typename T>
Identity<T>::Identity(){}

template<typename T>
Identity<T>::~Identity(){}

template<typename T>
Identity<T>::Identity(int rows, int collums)
{
	this->rows = rows;
	this->collums = collums;

	this->data_p = reinterpret_cast<T*>(calloc(rows * collums, sizeof(T)));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
		{
			if(i == j)
			{
				this->data_p[j * rows + i] = 1;
			}
		}
	}
}

template<typename T>
Identity<T> Identity<T>::operator*(int number)
{
	Identity<T> output(this->rows, this->collums);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->collums; j++)
		{
			output.get(i, j) = number * this->get(i, j);
		}
	}

	return output;
}

template<typename T>
void Identity<T>::print()
{
	std::cout << "identity:" << typeid(this).name() << std::endl;

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->collums; j++)
		{
			std::cout << this->get(i, j) << "\t";
		}
		std::cout << std::endl;
	}
}

template class Identity<int>;
template class Identity<char>;
template class Identity<double>;