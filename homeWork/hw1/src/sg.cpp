using namespace std;

class sg
{
public:
	int e = 0;
	int p = 0;

	sg(int **);
	~sg();

	int getE();
	int getP();

private:
	int** build(int**);
	int findSolution(int**);

};

sg::sg (int **mat)
{
	mat = this->build(mat);
	e = this->findSolution(mat);
}

sg::~sg()
{

}

int** sg::build (int** mat)
{
	int* max = new int[4];

	for (int i = 0; i < 5; i++)
	{
		int maxN = numeric_limits<int>::min();

		for (int j = 0; j < 4; j++)
		{
			if (maxN < mat[j][i]) maxN = mat[j][i];
		}

		max[i] = maxN;
	}

	int** newMat = new int*[4];
	for (int i = 0; i < 4; i++)
		newMat[i] = new int[5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			newMat[j][i] = max[i] - mat[j][i];
		}
	}
	return newMat;
}

int sg::findSolution(int **mat)
{
	int max;
	int min = numeric_limits<int>::max();
	for (int i = 0; i < 4; i++)
	{
		max = numeric_limits<int>::min();
		for (int j = 0; j < 5; j++)
		{
			int temp = mat[i][j];
			if (temp > max)
				max = temp;
		}

		if (max < min)
		{
			min = max;
			p = i+1;
		}
	}

	return min;
}

int sg::getE()
{
	return e;
}

int sg::getP()
{
	return p;
}