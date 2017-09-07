#include "main.h"

/*
Матрица

15 10  0 -6 12
 3 14  8  9  2
 1  5 14 20 -3
 7 19 10  2  0

 с = 0.87
*/

int main()
{

	// int mat[4][5] = {
	// 	{15, 10,  0, -6, 12},
	// 	{ 3, 14,  8,  9,  2},
	// 	{ 1,  5, 14, 20, -3},
	// 	{ 7, 19, 10,  2,  0}
	// };

	int** mat = new int*[4];
	
	mat[0] = new int[5] {15, 10,  0, -6, 12};
	mat[1] = new int[5] { 3, 14,  8,  9,  2};
	mat[2] = new int[5] { 1,  5, 14, 20, -3};
	mat[3] = new int[5] { 7, 19, 10,  2,  0};

	mm* kritFirst = new mm(mat);
	cout << "Минимаксный критерий:" << endl;
	cout << "e = " << kritFirst->getE() << endl;

	return 0;
}


