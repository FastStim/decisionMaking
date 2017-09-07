class mm
{
public:
	int e = 0;
	
	mm(int mat[4][5])
	{
		e = findSolution(mat);
	}

	~mm(){}

	int getE() {
		return e
;	}

private:
	int findSolution(int mat[4][5]) 
	{
		int max = numeric_limits<int>::min();
		int min = numeric_limits<int>::max();

		for (int j = 0; j < 5; j++)
		{
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