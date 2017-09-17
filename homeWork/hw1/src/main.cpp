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
	float c = 0.87;
	int** mat = new int*[4];
	
	mat[0] = new int[5] {15, 10,  0, -6, 12};
	mat[1] = new int[5] { 3, 14,  8,  9,  2};
	mat[2] = new int[5] { 1,  5, 14, 20, -3};
	mat[3] = new int[5] { 7, 19, 10,  2,  0};

	mm* kritFirst = new mm(mat);
	cout << "Минимаксный критерий:" << endl;
	cout << "Проект № " << kritFirst->getP() << endl;
	cout << "e = " << kritFirst->getE() << endl << endl;

	sg* kritSecond = new sg(mat);
	cout << "Критерий Сэвиджа:" << endl;
	cout << "Проект № " << kritSecond->getP() << endl;
	cout << "e = " << kritSecond->getE() << endl << endl;

	gu* kritThird = new gu(mat, c);
	cout << "Критерий Гурвица:" << endl;
	cout << "Проект № " << kritThird->getP() << endl;
	cout << "e = " << kritThird->getE() << endl << endl;
	return 0;
}


