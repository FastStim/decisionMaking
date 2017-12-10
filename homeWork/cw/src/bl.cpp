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
	bl(string, string, string, string, string, string);

	void mPrintTable();
	void bPrintTable(string);
	void editBO(string);
	void saveBO(string);

private:
	vector<flash> allFlash;

	vector<vector<int>> bType;
	vector<vector<int>> bSize;
	vector<vector<int>> bRSpeed;
	vector<vector<int>> bWSpeed;
	vector<vector<int>> bPrice;

	vector<flash> mParser(string);
	vector<vector<int>> bParser(string);

	string retCurRow(int, flash);

	void mPrintHeader(vector<int>);
	void bPrintHeader(string);
	void mPrintLine(vector<int>);
	void printSpace(int, int);

};

bl::bl (string model, string mBType = "", string mBSize = "", string mBRSpeed = "", string mBWSpeed = "", string mBPrice = "")
{
	allFlash = mParser(model);

	if (mBType != "")
		bType = bParser(mBType);
	if (mBSize != "")
		bSize = bParser(mBSize);
	if (mBRSpeed != "")
		bRSpeed = bParser(mBRSpeed);
	if (mBWSpeed != "")
		bWSpeed = bParser(mBWSpeed);
	if (mBPrice != "")
		bPrice = bParser(mBPrice);
}

// Разбор основной таблицы
vector<flash> bl::mParser(string csv)
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

	file.close();
	return curFlash;
}

// Разбор биномиальных отношений
vector<vector<int>> bl::bParser(string csv)
{
	ifstream file(csv);
	string str;
	
	vector<vector<int>> curBio;

	while(getline(file,str))
	{
		vector<int> cur;

		string delim(";");
		size_t prev = 0;
		size_t next;
		size_t delta = delim.length();

		while((next = str.find(delim, prev)) != string::npos)
		{
			string tmp = str.substr(prev, next-prev);

			cur.push_back(stoi(tmp));

			prev = next + delta;
		}

		curBio.push_back(cur);
	}

	file.close();
	return curBio;
}

// Печать таблицы с значениями
void bl::mPrintTable()
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

	mPrintLine(cur);
	mPrintHeader(cur);
	mPrintLine(cur);

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

		mPrintLine(cur);
		i++;
	}
}

// Печать БО
void bl::bPrintTable(string curBio)
{
	int cur = 0;
	
	int i = 0;
	while (i < allFlash.size()) 
	{
		if(allFlash[i].name.length() > cur)
			cur = allFlash[i].name.length();
		i++;
	}

	vector<vector<int>> bio;
	string title = "";

	if (curBio == "bType")
	{
		bio = bType;
		title = "Версия USB";
	}
	else if (curBio == "bSize")
	{
		bio = bSize;
		title = "Размер памяти";
	}
	else if (curBio == "rSpeed")
	{
		bio = bRSpeed;
		title = "Скорость чтения";
	}
	else if (curBio == "wSpeed")
	{
		bio = bWSpeed;
		title = "Скорость записи";
	}
	else if (curBio == "price")
	{
		bio = bPrice;
		title = "Цена";
	}
	else 
		return;

	bPrintHeader(title);

	i = 0;
	while (i < allFlash.size()) 
	{
		cout << allFlash[i].name;
		printSpace(cur, allFlash[i].name.length());

		int j = 0;
		while (j < bio[i].size())
		{
			if (bio[i][j] == 1)
				cout << "\033[32m";
			else
				cout << "\033[31m";
			
			cout << " " << bio[i][j] << "\033[0m";

			j++;
		}

		cout << endl;

		i++;
	}
}

// Печать шапки таблицы
void bl::mPrintHeader(vector<int> cur)
{
	string str;
	str = "Name";
	cout << "| " << "\033[33m" << str << "\033[0m";
	printSpace(cur[0], str.length());

	str = "Type";
	cout << " | " << "\033[33m" << str << "\033[0m";
	printSpace(cur[1], str.length());

	str = "sz.";
	cout << " | " << "\033[33m" << str << "\033[0m";
	printSpace(cur[2], str.length());
	
	str = "rS.";
	cout << " | " << "\033[33m" << str << "\033[0m";
	printSpace(cur[3], str.length());
	
	str = "wS.";
	cout << " | " << "\033[33m" << str << "\033[0m";
	printSpace(cur[4], str.length());
	
	str = "prc.";
	cout << " | " << "\033[33m" << str << "\033[0m";
	printSpace(cur[5], str.length());

	cout << " |" << endl;
}

// Печать заголовка таблицы
void bl::bPrintHeader(string title)
{
	cout << "\033[33m" << title << ":" << "\033[0m" << endl;
}

// Печать линии между строками
void bl::mPrintLine(vector<int> cur)
{
	for (int i = 0; i < (cur[0] + cur[1] + cur[2] + cur[3] + cur[4] + cur[5] + 12 + 7); i++)
		cout << "-";
	cout << endl;
}

// Заполнение пробелами для выравнивания таблицы
void bl::printSpace(int max, int cur)
{
	for (cur; cur < max; cur++)
		cout << " ";
}

// Редактируем БО
void bl::editBO(string curBO)
{
	vector<vector<int>> BO;

	int pos = 0;
	string cur = "";
	if (curBO == "bType")
	{
		BO = bType;
		pos = 1;
		cur = "тип";
	}
	else if (curBO == "bSize")
	{
		BO = bSize;
		pos = 2;
		cur = "размер";
	}
	else if (curBO == "rSpeed")
	{
		BO = bRSpeed;
		pos = 3;
		cur = "скорость чтения";
	}
	else if (curBO == "wSpeed")
	{
		BO = bWSpeed;
		pos = 4;
		cur = "скорость записи";
	}
	else if (curBO == "price")
	{
		BO = bPrice;
		pos = 5;
		cur = "цена";
	}
	else
		return;

	for (int i = 0; i < BO.size(); i++)
	{
		for (int j = i; j < BO[i].size(); j++)
		{
			if (i == j){
				BO[i][j] = 0;
				continue;
			}

			cout << "\033[32m" << "Какой(ая) " << cur << " лучше? (0(никая) или 1 или 2)" << "\033[0m" << endl;
			cout << allFlash[i].name;
			cout << " (" << "\033[33m" << retCurRow(pos, allFlash[i]) << "\033[0m" << ")";
			cout << " или ";
			cout << allFlash[j].name;
			cout << " (" << "\033[33m" << retCurRow(pos, allFlash[j]) << "\033[0m" << ")";
			cout << endl;

			int ans = -1;
			while (ans != 0 && ans != 1 && ans != 2)
			{
				int x = 0;
				while(!(cin >> x))
				{
        			cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			cout << "Ввести требуется только 0, 1 или 2, пробуйте еще: ";
    			}

    			if (x == 0 || x == 1 || x == 2)
    				ans = x;
    			else 
    				cout << "Ввести требуется только 0, 1 или 2, пробуйте еще: ";
			}

			switch (ans)
			{
				case 0:
					BO[i][j] = 0;
					BO[j][i] = 0;
					break;
				case 1:
					BO[i][j] = 1;
					BO[j][i] = 0;
					break;
				case 2:
					BO[i][j] = 0;
					BO[j][i] = 1;
					break;
			}
		}
	}

	if (curBO == "bType")
		bType = BO;
	else if (curBO == "bSize")
		bSize = BO;
	else if (curBO == "rSpeed")
		bRSpeed = BO;
	else if (curBO == "wSpeed")
		bWSpeed = BO;
	else if (curBO == "price")
		bPrice = BO;

}

void bl::saveBO(string curBO)
{
	string csv = "";
	vector<vector<int>> BO;
	if (curBO == "bType")
	{
		BO = bType;
		csv = "type.csv";
	}
	else if (curBO == "bSize")
	{
		BO = bSize;
		csv = "size.csv";
	}
	else if (curBO == "rSpeed")
	{
		BO = bRSpeed;
		csv = "rSpeed.csv";
	}
	else if (curBO == "wSpeed")
	{
		BO = bWSpeed;
		csv = "wSpeed.csv";
	}
	else if (curBO == "price")
	{
		BO = bPrice;
		csv = "price.csv";
	}


	ofstream file;
	file.open(csv, ios::out);
	if (file)
	{
		for (int i = 0; i < BO.size(); i++)
		{
			string line = "";
			for (int j = 0; j < BO[i].size(); j++)
			{
				line += to_string(BO[i][j]) + ";";
			}

			file << line << endl;
		}

		file.close();
	}
}


// Возращает число из текущей строки
string bl::retCurRow(int pos, flash cur)
{
	switch (pos)
	{
		case 1:
			return cur.standart;
			break;
		case 2:
			return to_string(cur.size);
			break;
		case 3:
			return to_string(cur.rSpeed);
			break;
		case 4:
			return to_string(cur.wSpeed);
			break;
		case 5:
			return to_string(cur.	price);
			break;
		default:
			return "";
	}
}