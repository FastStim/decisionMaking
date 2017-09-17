using namespace std;

class bl
{
public:
	float e = 0;
	int pp = 0;
	int** pMat;

	bl(int, int, int, int*, float*);
	~bl();

	float getE();
	int getP();
	void printMat();

private:
	int** build(int, int, int, int*);
	float findSolution(int**, float*);

};

bl::bl (int sell_max, int sell_min, int seb, int* sum, float* p)
{
	pMat = this->build(sell_max, sell_min, seb, sum);
	e = this->findSolution(pMat, p);
}

bl::~bl()
{

}

int** bl::build (int sell_max, int sell_min, int seb, int* sum)
{
	int** mat = new int*[5];
	for (int i = 0; i < 5; i++)
		mat[i] = new int[5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (sum[i] > sum[j])
			{
				mat[i][j] = sell_max * sum[j];
				mat[i][j] += sell_min * (sum[i] - sum[j]);
			} else {
				mat[i][j] = sell_max * sum[i];
			}

			mat[i][j] -= seb * sum[i];
		}
	}
	return mat;
}

float bl::findSolution(int **mat, float* p)
{
	float max = numeric_limits<float>::min();

	for (int i = 0; i < 5; i++)
	{
		float min = 0;

		for (int j = 0; j < 5; j++)
		{
			min += mat[i][j] * p[j];
		}

		if (max < min)
		{
			max = min;
			pp = i+1;
		}
	}

	return max;
}

float bl::getE()
{
	return e;
}

int bl::getP()
{
	return pp;
}

void bl::printMat()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << pMat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}