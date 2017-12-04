#include "main.h"

int main()
{
	int sell_1 = 25;
	int sell_2 = 10;
	int sell_3 = 1;

	int seb    = 15;
	
	int* count = new int[7]   {0, 50, 100, 150, 200, 250, 300};
	float* p1  = new float[7] {0.2, 0.1, 0.2, 0.2, 0.15, 0.1, 0.05};
	float* p2  = new float[7] {0.05, 0.1, 0.15, 0.2, 0.2, 0.1, 0.2};

	bl* krit = new bl(sell_1, sell_2, sell_3, seb, count, p1, p2);
	
	krit->printMat(1);
	krit->printMat(2);

	krit->printS(1);
	krit->printS(2);

	krit->printE();
	cout << "Критерий Байеса-Лапласа:" << endl;
	cout << "Проект № " << krit->getP() << endl;
	cout << "e = " << krit->getE()*1000 << endl << endl;

	return 0;
}


