#pragma once
#include "matrix.h"

template<typename T>
class Identity : public matrix<T>
{
public:
	Identity();
	~Identity();
	Identity(int rows,int collums);
	void print();
};

