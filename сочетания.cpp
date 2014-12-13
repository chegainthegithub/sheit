#include <iostream>
using namespace std;
int main()
{
	int arr[5] = { 1,2,3,4,5};
	int full_arr[5] = { 1, 2 , 3 ,4,5};
	int true_arr[5] = { 1, 2, 3, 4,5};
	int num = 2;
	int n, m;
	n = 4;
	int k = 4;
	int l = 0;
	for (int s = 0; s < k+1; s++)
		cout << true_arr[s];
	cout << endl;
	int i;
	while (true)
	{
		for (i = k; i >= 0; i--)
		{
			while (arr[i] < full_arr[n - l])
			{
				arr[i]++;
				for (int f = i + 1; f <= k; f++)
					arr[f] = arr[i] + f - i;
				for (int s = 0; s <= k; s++)
					cout << true_arr[arr[s] - 1];
				cout << endl;
				for (int f = k; f >= i + 1; f--) // ошибка т.к максимальным является элемент на 1 меньше максимума
				{
					while (arr[f] < full_arr[f + n - k])
					{
						++arr[f];
						for (int s = 0; s <= k; s++)
							cout << true_arr[arr[s] - 1];
						cout << endl;
					}
				}
			}
			++l;
		}
		if (i == -1)
			break;
	}
	return 0;
}