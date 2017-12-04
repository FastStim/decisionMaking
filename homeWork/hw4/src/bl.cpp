using namespace std;

class bl
{
public:


	bl(int, int, int, int, int*, float*, float*);
	~bl();

	float getE();
	int getP();
	void printE();
	void printS(int year);
	void printMat(int);

private:
	int** pMat;
	int** pMat2;

	float* pS1;
	float* pS2;
	float* el;

	int p;
	float e;

	int** build(int, int, int*, int);
	float* sRow(int**, float*);
	float* findSolution(float*, float*, float*);
	void getMax(float* el);

};

bl::bl (int sell_1, int sell_2, int sell_3, int seb, int* count, float* p1, float* p2)
{
	pMat  = this->build(sell_1, seb, count, 0);
	pMat2 = this->build(sell_2, 0, count, sell_3);
	pS1 = this->sRow(pMat, p1);
	pS2 = this->sRow(pMat2, p2);
	cout << "pS: " << endl;
	for (int i = 0; i < 7; i++)
		cout << "- " << pS2[i] << endl;
	el = this->findSolution(pS1, pS2, p1);
	getMax(el);
}

bl::~bl()
{

}

int**bl::build(int sell, int seb, int* count, int rem)
{
	int** mat = new int*[7];
	for (int i = 0; i < 7; i++)
		mat[i] = new int[7];

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			int tempC = 0;
			if (count[i]<=count[j])
				tempC = count[i];
			else
				tempC = count[j];

			mat[i][j] = tempC * sell;
			mat[i][j] -= seb * count[i];
			mat[i][j] += (count[i] - tempC) * rem;
		}	
	}

	return mat;

}

float*bl::sRow(int** mat, float* p) 
{
	float* s = new float[7];

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			s[i] += mat[i][j] * p[j];

	return s;
}

float* bl::findSolution(float* pS1, float* pS2, float* p)
{
	float* el = new float[7];
	
	for(int i = 0; i < 7; i++)
	{
		el[i] = pS1[i];

		for(int j = 0; j <= i; j++)
		{
			el[i] += pS2[i-j] * p[j];
		}
	}

	return el;
}

void bl::getMax(float* el)
{
	float max = numeric_limits<float>::min();

	for (int i = 0; i < 7; i++)
	{
		if (max < el[i])
		{
			max = el[i];
			p = i + 1;
		}
	}

	e = max;
}

void bl::printE()
{
	cout << "el: " << endl;
	for (int i = 0; i < 7; i++)
		cout << "- " << el[i] << endl;
}

void bl::printS(int year)
{
	float* s;
	if (year == 1)
		s = pS1;
	else if(year == 2)
		s = pS2;
	cout << "pS: " << endl;
	for (int i = 0; i < 7; i++)
		cout << "- " << s[i] << endl;
}

void bl::printMat(int year)
{
	int** mat;
	if (year == 1)
		mat = pMat;
	else if(year == 2)
		mat = pMat2;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

float bl::getE()
{
	return e;
}

int bl::getP()
{
	return p;
}