#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);

int* insert(int* arr, int& n, int value,int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << " Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* push_back(int* arr, int& n, int value)
{
	//1)Создаем буферный массив нужного размера(на 1 элемент больше)
	int* buffer = new int[n + 1];
	//2)Копируем все значения из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив
	delete[] arr;
	//4)Подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	buffer = nullptr; //NULL-pointer(указатель на 0)
	//cout << typeid(nullptr).name() << endl;
	//5)И только после этого в массив 'arr' можно добавить значение
	arr[n] = value;
	//for (int i = n; i < n + number; i++)arr[i] = value;
	//6)После добавления элемента в массив количество его элементов увеличивается на 1
	n++;
	//7)Элемент добавлен
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}