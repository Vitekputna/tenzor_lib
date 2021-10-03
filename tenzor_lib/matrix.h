#pragma once
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
	matrix<T> operator+(matrix<T> &other);
	matrix<T> operator-(matrix<T> &other);
	matrix<T> operator*(matrix<T>& other);
	matrix<T> operator*(int number);
	matrix<T> operator*(float number);
 	matrix(const matrix& A);
	T& get(const int row, const int collum);
	T* row(const int row);
	T* collum(const int collum);
	void print();
	void print_to_file(std::string mame);
};

template<typename T>
matrix<T> operator*(const int number, matrix<T>& rhs)
{
	return rhs * number;
}

