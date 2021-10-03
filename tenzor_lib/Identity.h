#pragma once
#include "tenzor.h"

template<typename T>
class Identity : public tenzor<T>
{
public:
	Identity();
	~Identity();
	Identity(int rows,int collums);
	void print();
};

