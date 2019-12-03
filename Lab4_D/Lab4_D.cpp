#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

bool addressCheck(string adr);

int main()
{
	string dom;
	setlocale(LC_ALL, "RUS");
	cout << "Введите адрес\n";
	getline(cin,dom);
	bool flag = true;
	bool point = false;

	if (addressCheck(dom))
	{
		int i = dom.length();
		while(dom[i] != '@') 
		{
			if (dom[i] == '.')
			{
				point = true;
			}
			if(point && (dom[i] < 48 || dom[i] > 57) && (dom[i] < 64 || dom[i] > 90) && (dom[i] < 97 || dom[i] > 122) && dom[i] != 95 && dom[i]!= 45 && dom[i] != 46) 
			{
				flag = false;
			}
			i--;
		}
		if (flag)
			cout << "Введенный адрес соответствует требованиям задания\n";
		else
			cout << "Введенный адрес не соответствует требованиям задания\n";
	}
	else
		cout << "Не адрес\n";
}

bool addressCheck(string adr)
{
	int countBeforeSobaka = 0;
	int countAfterSobaka = 0;
	bool sobaka = false;
	for (int i = 0; i < adr.length(); i++)
	{
		if ((int)adr[i] != 64 && sobaka == false)
			countBeforeSobaka++;
		else if (sobaka == true)
			countAfterSobaka++;

		if ((int)adr[i] == 64)
			sobaka = true;
	}

	if (sobaka && countAfterSobaka && countBeforeSobaka)
		return true;
	return false;
}
