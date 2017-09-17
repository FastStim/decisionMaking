#include "main.h"

int main()
{
	int sell_max = 49;
	int sell_min = 15;
	int seb      = 25;

	
	int* sum = new int[5] {100, 150, 200, 250, 300};
	float* p = new float[5] {0.25, 0.2, 0.2, 0.2, 0.15};

	bl* krit = new bl(sell_max, sell_min, seb, sum, p);
	
	krit->printMat();
	cout << "Критерий Байеса-Лапласа:" << endl;
	cout << "Проект № " << krit->getP() << endl;
	cout << "e = " << krit->getE() << endl << endl;

	return 0;
}


