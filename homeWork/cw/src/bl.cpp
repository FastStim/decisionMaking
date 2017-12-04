struct flash
{
	string name;
	string standart;
	int size;
	int rSpeed;
	int wSpeed;
	int price;
};

class bl
{
public:
	bl(string);
	~bl();

	void printTable();

private:
	vector<flash> allFlash;
	vector<vector<int>> bType;
	vector<vector<int>> bSize;
	vector<vector<int>> bRSpeed;
	vector<vector<int>> bWSpeed;
	vector<vector<int>> bPrice;

	vector<flash> parser(string);
	void printHeader(vector<int>);
	void printLine(vector<int>);
	void printSpace(int, int);
};

bl::bl (string model)
{
	cout << "Конструктор получил: " << model << endl;
	allFlash = parser(model);
}

bl::~bl()
{

}

vector<flash> bl::parser(string csv)
{
	ifstream file(csv);
	string str;
	
	vector<flash> curFlash;

	while(getline(file,str))
	{
		flash cur;

		string delim(";");
		size_t prev = 0;
		size_t next;
		size_t delta = delim.length();

		int i = 0;
		while((next = str.find(delim, prev)) != string::npos)
		{

			string tmp = str.substr(prev, next-prev);
			switch (i)
			{
				case 0:
					cur.name = tmp;
					break;
				case 1:
					cur.standart = tmp;
					break;
				case 2:
					cur.size = stoi(tmp);
					break;
				case 3:
					cur.rSpeed = stoi(tmp);
					break;
				case 4:
					cur.wSpeed = stoi(tmp);
					break;
				case 5:
					cur.price = stoi(tmp);
					break;
			}
			prev = next + delta;
			i++;
		}

		curFlash.push_back(cur);
	}

	return curFlash;
}

void bl::printTable()
{
	vector<int> cur;
	for (int i = 0; i < 6; i++)
		cur.push_back(0);

	int i = 0;
	while (i < allFlash.size()) 
	{
		if(allFlash[i].name.length() > cur[0])
			cur[0] = allFlash[i].name.length();
		if(allFlash[i].standart.length() > cur[1])
			cur[1] = allFlash[i].standart.length();
		if(to_string(allFlash[i].size).length() > cur[2])
			cur[2] = to_string(allFlash[i].size).length();
		if(to_string(allFlash[i].rSpeed).length() > cur[3])
			cur[3] = to_string(allFlash[i].rSpeed).length();
		if(to_string(allFlash[i].wSpeed).length() > cur[4])
			cur[4] = to_string(allFlash[i].wSpeed).length();
		if(to_string(allFlash[i].price).length() > cur[5])
			cur[5] = to_string(allFlash[i].price).length();

		i++;
	}

	printLine(cur);
	printHeader(cur);
	printLine(cur);

	i = 0;
	while (i < allFlash.size()) 
	{
		cout << "| " << allFlash[i].name;
		printSpace(cur[0], allFlash[i].name.length());
		cout << " | " << allFlash[i].standart;
		printSpace(cur[1], allFlash[i].standart.length());

		cout << " | ";
		printSpace(cur[2], to_string(allFlash[i].size).length());
		cout << allFlash[i].size;
		cout << " | ";
		printSpace(cur[3], to_string(allFlash[i].rSpeed).length());
		cout << allFlash[i].rSpeed;
		cout << " | ";
		printSpace(cur[4], to_string(allFlash[i].wSpeed).length());
		cout << allFlash[i].wSpeed;
		cout << " | ";
		printSpace(cur[5], to_string(allFlash[i].price).length());
		cout << allFlash[i].price;

		cout << " |" << endl;

		printLine(cur);
		i++;
	}
}

void bl::printHeader(vector<int> cur)
{
	string str;
	str = "Name";
	cout << "| " << str;
	printSpace(cur[0], str.length());

	str = "Type";
	cout << " | " << str;
	printSpace(cur[1], str.length());

	str = "sz.";
	cout << " | " << str;
	printSpace(cur[2], str.length());
	
	str = "rS.";
	cout << " | " << str;
	printSpace(cur[3], str.length());
	
	str = "wS.";
	cout << " | " << str;
	printSpace(cur[4], str.length());
	
	str = "prc.";
	cout << " | " << str;
	printSpace(cur[5], str.length());

	cout << " |" << endl;
}

void bl::printLine(vector<int> cur)
{
	for (int i = 0; i < (cur[0] + cur[1] + cur[2] + cur[3] + cur[4] + cur[5] + 12 + 7); i++)
		cout << "-";
	cout << endl;
}

void bl::printSpace(int max, int cur)
{
	for (cur; cur < max; cur++)
		cout << " ";
}
