#include <stdio.h>
#include <iostream>
#include "tenzor.h"
#include "Identity.h"

int main()
{
	Identity<int> A(3, 2);
	A.get(0, 1) = 2;
	A.get(1, 0) = 3;
	A.get(1, 1) = 4;
	A.get(2, 0) = 9;
	A.get(2, 1) = 5;

	tenzor<int> B(2, 1);
	B.get(0, 0) = 2;
	B.get(1, 0) = 3;

	A.print();
	B.print();

	tenzor<int> C = A * B;

	C.print();
}

