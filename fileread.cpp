#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int main()
{
	int length;
	cin >> length;
	char *arr1 = new char[length];
	fstream fs1(arr1);
	cin >> length;
	char *arr2 = new char[length];
	fstream fs2(arr2, ios_base::out | ios_base::trunc);
	char a;
	while (1)
	{
		fs1 >> a;
		if (fs1.eof() == 1)
			break;
		fs2 << a;
	}
	fs2.close();
	fstream fs3("123.txt");
	while (1)
	{
		fs3 >> a;
		if (fs3.eof() == 1)
			break;
		cout << a;
	}

}
