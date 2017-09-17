using namespace std;

class gu
{
public:
	float e = 0;
	int p = 0;

	gu(int **, float);
	~gu();

	int getE();
	int getP();

private:
	float* build(int**, float);
	float findSolution(float*);

};

gu::gu (int **mat, float c)
{
	float* s = this->build(mat, c);
	e = this->findSolution(s);
}

gu::~gu()
{

}

float* gu::build (int** mat, float c)
{
	int** maxMin = new int*[2];
	maxMin[0] = new int[4];
	maxMin[1] = new int[4];

	for (int i = 0; i < 4; i++)
	{
		int max = numeric_limits<int>::min();
		int min = numeric_limits<int>::max();

		for (int j = 0; j < 5; j++)
		{
			if (max < mat[i][j])
				max = mat[i][j];

			if (min > mat[i][j])
				min = mat[i][j];
		}

		maxMin[0][i] = max;
		maxMin[1][i] = min;
	}


	float* s = new float[4];

	for (int i = 0; i < 4; i++)
		s[i] = c * maxMin[1][i] + (1 - c) * maxMin[0][i];

	return s;
}

float gu::findSolution(float* s)
{
	int max = numeric_limits<float>::min();
	for (int i = 0; i < 4; i++)
	{
		if (max < s[i])
		{
			max = s[i];
			p = i + 1;
		}

	}

	return max;
}

int gu::getE()
{
	return e;
}

int gu::getP()
{
	return p;
}