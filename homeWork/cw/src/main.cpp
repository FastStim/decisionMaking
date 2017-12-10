#include "main.h"

struct menu
{
	string menu;
	string BO;
	int min;
	int max;
	bool close;

};

menu mMenu;
// Первое какое меню 

void viewAllTable(bl* main){
	main->mPrintTable();

	cout << endl;
	main->bPrintTable("bType");

	cout << endl;
	main->bPrintTable("bSize");

	cout << endl;
	main->bPrintTable("rSpeed");

	cout << endl;
	main->bPrintTable("wSpeed");

	cout << endl;
	main->bPrintTable("price");


}

void viewBO(bl* main)
{
	main->bPrintTable(mMenu.BO);
}

int read()
{
	int ans = -1;
	while (ans < mMenu.min || ans > mMenu.max)
	{
		int x = 0;
		cout << "Выберите пункт: ";
		while(!(cin >> x))
		{
    		cin.clear();
    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		cout << "Не правильно, попробуйте еще. ";
    	}

    	if (x >= mMenu.min && x <= mMenu.max)
    		ans = x;
    	else 
    		cout << "Не правильно, попробуйте еще. ";
	}

	return ans;
}

void menu(bl* main)
{
	cout << endl;

	if (mMenu.menu == "main")
	{
		cout << "\033[33m" << "Главное меню:" << "\033[0m"<<endl;
		cout << "1. Печать таблицы" << endl; 
		cout << "2. Печать БО" << endl;
		cout << "3. Редактровать БО" << endl;
		cout << "4. Сохранить БО" << endl;
		cout << "5. Печать всего" << endl;
		cout << "0. Выход" << endl;
	}

	if (mMenu.menu == "vBO" || mMenu.menu == "eBO" || mMenu.menu == "wBO")
	{
		if (mMenu.menu == "eBO")
			cout << "\033[33m" << "Редактировать БО:" << "\033[0m"<<endl;
		else if (mMenu.menu == "wBO")
			cout << "\033[33m" << "Сохранить БО:" << "\033[0m"<<endl;
		else
			cout << "\033[33m" << "Печать БО:" << "\033[0m"<<endl;
		cout << "1. Версия USB" << endl; 
		cout << "2. Размер памяти" << endl;
		cout << "3. Скорость чтения" << endl;
		cout << "4. Скорость записи" << endl;
		cout << "5. Цена" << endl;
		cout << "0. Выход" << endl;
	}

	int ans = read();

	cout << endl;

	if (mMenu.menu == "vBO")
	{
		if (ans == 1)
			mMenu.BO = "bType";
		if (ans == 2)
			mMenu.BO = "bSize";
		if (ans == 3)
			mMenu.BO = "rSpeed";
		if (ans == 4)
			mMenu.BO = "wSpeed";
		if (ans == 5)
			mMenu.BO = "price";

		if (ans != 0)
			viewBO(main);

		mMenu.menu = "main";
		mMenu.min = 0;
		mMenu.max = 5;
	} 
	else if (mMenu.menu == "main")
	{
		if (ans == 1) 
			main->mPrintTable();
		if (ans == 2) 
		{
			mMenu.menu = "vBO";
			mMenu.min = 0;
			mMenu.max = 5;
		}
		if (ans == 5)
			viewAllTable(main);

		if (ans == 0)
			mMenu.close = true;
	}
	

	
}


int main()
{
	bl* main = new bl("model.csv", "type.csv", "size.csv", "rSpeed.csv", "wSpeed.csv", "price.csv");
	
	mMenu.menu = "main";
	mMenu.min = 0;
	mMenu.max = 5;
	mMenu.close = false;
	while (!mMenu.close)
		menu(main);

	// cout << endl;
	// main->editBO("bType");

	// cout << endl;
	// main->bPrintTable("bType");

	return 0;
}




