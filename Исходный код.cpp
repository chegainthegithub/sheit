#include <iostream>
using namespace std;
char abc[16] = { '0', '1', '2', '3', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
char *any_any()
{
	int sum = 0;
	int sys1;
	int sys2;
	char *num = new char[];
	cin >> num;
	cin >> sys1;
	cin >> sys2;
	int size;   //надо узнать количество введенных символов


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 16; j++)
			if (num[i] == abc[j])
			{
			cout << (num[i]) << endl;;
			sum = sum*sys1 + j;
			cout << sum << endl;
			}
	}
	int clone1 = sum;
	int clone2 = sum;
	if (num[0] == '-')
		sum = -sum;
	cout << sum << endl;
	int counter = 0;
	while (clone2 > 0)
	{
		clone2 = clone2 / sys2;
		counter++;
	}
	counter = counter + 2;
	int i = counter;
	char *total = new char[counter];
	while (clone1 / sys2 > 0)
	{
		for (int j = 0; j < 16; j++)
			if (clone1 % sys2 == j)
				total[i] = abc[j];
		i = i - 1;
		clone1 = clone1 / sys2;
	}
	if (sum < 0)
		total[0] = '-';
	cout << total;
	return(total);
}
int main()
{
	any_any();
	return(0);
}
