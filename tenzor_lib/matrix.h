#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

template<typename T>
class matrix
{
public:
	int rows;
	int collums;
	T* data_p;

	matrix();
	~matrix();
	matrix(int rows, int collums);
	T& operator[](const int pos);
	matrix<T> operator+(matrix<T>& other);
	matrix<T> operator-(matrix<T>& other);
	matrix<T> operator*(matrix<T>& other);
	matrix<T> operator*(int number);
	matrix<T> operator*(float number);
	matrix(const matrix& A);
	T& get(const int row, const int collum);
	T* row(const int row);
	T* collum(const int collum);
	void print();
	void print_to_file(std::string mame);

	void swap_row(int from, int to);

};

template<typename T>
matrix<T> operator*(const int number, matrix<T>& rhs)
{
	return rhs * number;
}

template<typename T>
matrix<T> diag(matrix<T>& other)
{
	matrix<T> output(other.collums,1);

	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.collums; j++)
		{
			if (i == j)
			{
				output.get(i, 0) = other.get(i, j);
			}
		}
	}

	return output;
}

template<typename T>
matrix<T> diagm(matrix<T>& other)
{
	matrix<T> output(other.collums, other.collums);

	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.collums; j++)
		{
			if (i == j)
			{
				output.get(i, j) = other.get(i, j);
			}
		}
	}

	return output;
}

template<typename T>
matrix<T> upper(matrix<T>& other)
{
	int m_size = std::min(other.collums, other.rows);

	matrix<T> output(m_size, m_size);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (i != j && i > j)
			{
				output.get(i, j) = other.get(i, j);
			}
		}
	}

	return output;
}

template<typename T>
matrix<T> lower(matrix<T>& other)
{
	int m_size = std::min(other.collums, other.rows);

	matrix<T> output(m_size, m_size);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (i != j && i < j)
			{
				output.get(i, j) = other.get(i, j);
			}
		}
	}

	return output;
} 

template<typename T>
matrix<T> LU_upper(matrix<T>& other)
{
	matrix<T> output = other;

	for (int i = 0; i < output.collums-1; i++)
	{
		for (int j = i+1; j < output.rows; j++)
		{
			if (output.get(i, i) == 0 && i != output.rows-1)
			{
				output.swap_row(i, i + 1);
			}

			double k = -output.get(j,i)/output.get(i,i);


			for (int ii = 0; ii < output.collums; ii++)
			{
				output.get(j, ii) += k * output.get(i, ii);
			}
			
		}
	}

	return output;
}

template<typename T>
matrix<T> LU_lower(matrix<T>& other)
{
	matrix<T> output = other;

	for (int i = output.collums-1; i >= 0; i--)
	{
		for (int j = i-1; j >= 0;j--)
		{
			if (output.get(i, i) == 0 && i != 0)
			{
				output.swap_row(i, i - 1);
			}

			double k = -output.get(j, i) / output.get(i, i);

			for (int ii = 0; ii < output.collums; ii++)
			{
				output.get(j, ii) += k * output.get(i, ii);
			}

		}
	}

	return output;
}




