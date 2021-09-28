#include <stdio.h>
#include <iostream>
#include "tenzor.h"
#include "Identity.h"

int main()
{
	tenzor<int> A(2,2);
	A.get(0, 0) = 5;
	A.get(0, 1) = 3;
	A.get(1, 0) = 4;
	A.print();

	Identity<int> B(2,2);
	B.print();

	tenzor<int> C(2, 2);

	C = A + B;
	C.print();	
}