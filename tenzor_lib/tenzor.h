#pragma once
#include <stdio.h>

template<typename T>
class tenzor
{
public:
	int x_size;
	int y_size;
	T* data_p;

	tenzor();
	~tenzor();
	tenzor(int x_size, int y_size);
	T& operator[](const int pos);
	tenzor<T> operator+(tenzor<T> other);
	//T& operator-(const T other);
	T& get(const int x, const int y);
	void print();

};


