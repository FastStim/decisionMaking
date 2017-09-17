using namespace std;

class mm
{
public:
	int e = 0;
	int p = 0;
	
	mm(int **mat)
	{
		e = findSolution(mat);
	}

	~mm(){}

	int getE() {
		return e;
	}

	int getP() {
		return p;
	}

private:
	int findSolution(int **mat) 
	{
		int max = numeric_limits<int>::min();
		int min;
		for (int i = 0; i < 4; i++)
		{
			min = numeric_limits<int>::max();

			for (int j = 0; j < 5; j++)
			{
				int temp = mat[i][j];
				if (temp < min)
					min = temp;
			}

			if (max < min)
			{
				max = min;
				p = i+1;
			}
		}

		return max;
	}
};