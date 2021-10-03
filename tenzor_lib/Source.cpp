#include <stdio.h>
#include <iostream>
#include "matrix.h"
#include "Identity.h"

int main()
{
	Identity<int> A(3, 2);
	A.get(0, 1) = 2;
	A.get(1, 0) = 3;
	A.get(1, 1) = 4;
	A.get(2, 0) = 9;
	A.get(2, 1) = 5;

	matrix<int> A_d = lower(A);
	A.print();
	A_d.print();

	/*matrix<int> B(2, 1);
	B.get(0, 0) = 2;
	B.get(1, 0) = 3;

	A.print();
	B.print();

	matrix<int> C = A * B;

	C.print();*/
}

