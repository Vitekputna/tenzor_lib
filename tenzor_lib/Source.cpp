#include <stdio.h>
#include <iostream>
#include "matrix.h"
#include "Identity.h"

int main()
{
	Identity<double> A(3, 3);
	A.get(0, 0) = 1;
	A.get(0, 1) = 2;
	A.get(0, 2) = 3;
	A.get(1, 0) = 4;
	A.get(1, 1) = 5;
	A.get(1, 2) = 6;
	A.get(2, 0) = 7;
	A.get(2, 1) = 8;
	A.get(2, 2) = 0;

	A.print();
	
	matrix<double> L = LU_lower(A);
	L.print();

	matrix<double>	U = LU_upper(A);
	U.print();

	matrix<double> B = L * U;
	B.print();
	
}

