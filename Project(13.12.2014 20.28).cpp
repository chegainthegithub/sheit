#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<vector<int>> matrix_creator(int *true_arr, int num, int size)
{
	vector<vector<int>> matrix; // check for size < num needed
	vector <int> local_arr;
	int *arr = new int[num];
	int *full_arr = new int[size];
	for (int i = 0; i < num; i++)
		arr[i] = i + 1;
	for (int i = 0; i < size; i++)
		full_arr[i] = i + 1;	       //int full_arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };     
	int n, m;                          //int true_arr[8] = { 0, 1, 3, 5, 7, 9, 11, 13 };
	n = size - 1;
	int k = num - 1;
	int l = 0;
	for (int i = 0; i < num; i++)
		local_arr.push_back(true_arr[i]);
	matrix.push_back(local_arr);
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
				vector<int> local_arr1;
				for (int s = 0; s <= k; s++)
					local_arr1.push_back(true_arr[arr[s] - 1]);
				matrix.push_back(local_arr1);
				for (int f = k; f >= i + 1; f--)
				{
					while (arr[f] < full_arr[f + n - k])
					{
						++arr[f];
						vector<int> local_arr1;
						for (int s = 0; s <= k; s++)
							local_arr1.push_back(true_arr[arr[s] - 1]);
						matrix.push_back(local_arr1);
					}
				}
			}
			++l;
		}
		if (i == -1)
			break;
	}
	return(matrix);
}
vector<int> the_arr(int All_Goods, int num, int Number_Trades)
{
	int *True_arr1 = new int[All_Goods];
	for (int i = 0; i < All_Goods; i++) // массив всех товаров
		True_arr1[i] = i + 1;
	vector<vector<int>> Matrix_full = matrix_creator(True_arr1, num, All_Goods); // матрица всех комбинаций тру-массива по num
	int Great_limit = Matrix_full.size(); // количество комбинций
	int *Full_Arr = new int[Great_limit]; // массив - счетчик для каждой комбинации
	for (int i = 0; i < Great_limit; i++)
		Full_Arr[i] = 0;
	int buffer;// необходимо поставить указатель в файле на позицию сразу после 2 числа
	ifstream file("1.txt", ios::in);
	file >> buffer; //
	file >> buffer; // сдвиг на2 числа от начала файла (на позицию первой строки)
	for (int i = 1; i <= Number_Trades; i++) //это происходит количество-сделок-раз(перебор всех сделок)
	{
		int Trade_Goods = 0; // количество товаров в строке
		file >> Trade_Goods;
		if (num > Trade_Goods)//считывание
		{
			for (int local4 = 0; local4 < Trade_Goods; local4++)
				file >> buffer;
			continue;
		}
		int *True_arr2 = new int[Trade_Goods];  //считывание массива True_arr2 для матрицы покупок для данной строки - заполнение массива номерами товаров из сделки (они упорядочены по возрастанию)
		int new_arr_size = 0;
		for (int local1 = 0; local1 < Trade_Goods; local1++) //цикл от 0 до Trade_Goods считывать в True_arr2 числа
		{
			bool check = 0;
			file >> buffer;
			for (int local2 = 0; local2 < local1; local2++)
				if (True_arr2[local2] == buffer)
				{
				check++;
				break;
				}
			if (check == 0)
			{
				True_arr2[local1] = buffer;
				new_arr_size++;
			}
		}
			int *True_arr3 = new int[new_arr_size];
			for (int local3 = 0; local3 < new_arr_size; local3++)
				True_arr3[local3] = True_arr2[local3];
			delete[]True_arr2;
			// сортировка массива по возрастанию
		vector<vector<int>> Matrix_local = matrix_creator(True_arr3, num, Trade_Goods); // матрица сочетаний данной строки по num
		int limit = Matrix_local.size(); // количество комбинаций
		int count = 0;
		for (int j = 0; j < limit; j++)   //сравнение сочетаний из общей матрицы покупок и матрицы локальных покупок,инкование соответствующих ячеек массива числа встречающихся комбинаций
		{
			for (int count = 0; count < Great_limit; count++)
				if (Matrix_full[count] == Matrix_local[j])
			{
				Full_Arr[count]++;
				break;
			}
		}
		delete[]True_arr3;
	}
	int max = 0;
	vector <int> Max_number = Matrix_full[0];
	bool check = 0;
	for (int i = 0; i < Great_limit; i++)  //поиск среди всех элементов массива максимального,возвращаем вектор из матрицы всех возможных комбинаций с данным номером - результат
	{
		if (Full_Arr[i]>max)
		{
			check = 1;
			max = Full_Arr[i];
			Max_number = Matrix_full[i];
		}
	}
	delete []Full_Arr;
	delete[]True_arr1;
	if (check == 0)
	{
		vector <int> Max_number_fail;
		Max_number_fail.push_back(0);
		return(Max_number_fail);
	}
	return (Max_number);
}
int main()
{
	int All_Goods;
	int All_Trades;
	ifstream file;
	file.open("1.txt", ios::in);
	char chr = '1';
	if (!file.is_open())
	{
		cout << "file isnt found";
		return 0;
	}
	while (!file.eof())
	{
		file >> chr;
		if (chr <'0' || chr>'9')
		{
			cout << "there are wrong symbols in the file.the information cannot be read properly" << endl; //проверка на только цифры
			return 0;
		}
	}
	cout << "all symbols fit" << endl;
	file.close();
	file.open("1.txt", ios::in);
	file >> All_Goods;
	file >> All_Trades; //ввод количество товаров,количество сделок
	cout << All_Goods << endl;
	cout << All_Trades << endl;
	file.close();
	file.open("1.txt", ios::in);
	int num = 1;
	for (int i = 1; i <= All_Goods; i++)
	{
	int size = i;
	vector <int> thearr = the_arr(All_Goods, size, All_Trades);
	cout << "for " << i << " goods the most popular combination is ";
	for (int j = 0; j < size; j++)    //цикл вывода всех векторов,соответствующих самой часто встречающейся комбинации чисел из сочетания по i
	    {
		if (thearr[j] == 0)
		{
			cout << "not found" << endl;
			break;
		}
		cout << thearr[j] << " ";
	    }
	cout << endl;
	}
	return 0;
}