#pragma once
#include "matrix.h"

template<typename T>
class Identity : public matrix<T>
{
public:
	Identity();
	~Identity();
	Identity(int rows,int collums);
	Identity<T> operator*(int number);
	void print();
};

template<typename T>
matrix<T> LU_lower(matrix<T>& other)
{
	matrix<T> output = other;
	Identity<T> real_output(other.rows, other.collums);

	for (int i = 0; i < output.collums - 1; i++)
	{
		for (int j = i + 1; j < output.rows; j++)
		{
			if (output.get(i, i) == 0 && i != output.rows - 1)
			{
				output.swap_row(i, i + 1);
			}

			double k = -output.get(j, i) / output.get(i, i);

			real_output.get(j, i) = -k;


			for (int ii = 0; ii < output.collums; ii++)
			{
				output.get(j, ii) += k * output.get(i, ii);
			}

		}
	}

	return real_output;
}

template<typename T>
Identity<T> operator*(const int number, Identity<T>& rhs)
{
	return rhs * number;
}