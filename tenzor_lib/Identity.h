#pragma once
#include "tenzor.h"

template<typename T>
class Identity : public tenzor<T>
{
public:
	Identity();
	~Identity();
	Identity(int x_size,int y_size);
	void print();
};

