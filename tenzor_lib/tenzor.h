#pragma once
#include <stdio.h>
#include <string>

template<typename T>
class tenzor
{
public:
	int rows;
	int collums;
	T* data_p;

	tenzor();
	~tenzor();
	tenzor(int rows, int collums);
	T& operator[](const int pos);
	tenzor<T> operator+(tenzor<T> &other);
	tenzor<T> operator-(tenzor<T> &other);
	tenzor<T> operator*(tenzor<T>& other);
	tenzor<T> operator*(int number);
	tenzor<T> operator*(float number);
 	tenzor(const tenzor& A);
	T& get(const int row, const int collum);
	T* row(const int row);
	T* collum(const int collum);
	void print();
	void print_to_file(std::string mame);
};

template<typename T>
tenzor<T> operator*(const int number, tenzor<T>& rhs)
{
	return rhs * number;
}

