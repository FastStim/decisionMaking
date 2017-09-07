using namespace std;

class mm
{
public:
	int e = 0;
	
	mm(int **mat)
	{
		e = findSolution(mat);
	}

	~mm(){}

	int getE() {
		return e;
	}

private:
	int findSolution(int **mat) 
	{
		int max;
		int min;
		for (int j = 0; j < 5; j++)
		{
			max = numeric_limits<int>::min();
			min = numeric_limits<int>::max();

			for (int i = 0; i < 4; i++)
			{

				int temp = mat[i][j];
				if (temp > max)
					max = temp;
			}

			if (min > max)
				min = max;
		}

		return min;
	}
};