#include <iostream>
#include <ctime>
using namespace std;
void Treeconstr(int *a, unsigned size)
{
	for (int i = 0; i < size; i++) 
	{
		int n = i;
		for (int j = i / 2; j >= 0; j--)
		if (a[n]>a[j])
		{
			swap(a[n], a[j]);
			n = j;
			for (int k = 0; k < size; k++)
				cout << a[k] << " ";
			cout << endl;
		}
	}
}
void HeapSort(int *a, unsigned size)
{
	unsigned size2 = size-1;
	for (int i = 0; i < size-2; i++)
	{
		swap(a[0], a[size2]);
		size2 = size2 - 1;
		Treeconstr(a, size2);
	}
}
void input(int *a, unsigned size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << ".........." << endl;
}
void output(int *a, unsigned size)
{
	for (int i = 0; i < size; i++)
		cout << a[i]<<" ";
	cout << endl;
}
int main()
{
	int size;
	cin >> size; //input number of elements
	int *array = new int[size];
	input(array, size);
	Treeconstr(array, size);
	HeapSort(array, size);
	output(array, size);
}