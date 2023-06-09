﻿#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"


void FillRand(int arr[], int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], int n);
void Print(int** arr, const int rows, const int cols);

int* Push_back(int* arr, int& n, int value);
int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);

int* Push_front(int* arr, int& n, int value);
int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, const int rows, int& cols);

int* Insert(int* arr, int& n, int value, int index);
int** insert_row(int** arr, int& rows, const int cols, const int index);
void insert_col(int** arr, const int rows, int& cols, const int index);

int* Pop_back(int* arr, int& n);
int** pop_row_back(int** arr, int& rows, const int cols);
void pop_cols_back(int** arr, const int rows, int& cols);

int* Pop_front(int* arr, int& n);
int** pop_row_front(int** arr, int& rows, const int cols);
void pop_cols_front(int** arr, const int rows, int& cols);

int* Erase(int* arr, int& n, int index);
int** erase_row(int** arr, int& rows, const int cols, const int index);
void erase_cols(int** arr, const int rows, int& cols, const int index);

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

//#define dynamic_memory_1
#define dynamic_memory_2


void main()
{
	setlocale(LC_ALL, "");

#ifdef dynamic_memory_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите дополнительное значение для добавления в конец массива: "; cin >> value;
	// Push_back - добавление элемента в конец массива:
	arr = Push_back(arr, n, value);
	Print(arr, n);
	// Push_front - добавление элемента в начало массива:
	cout << "Введите дополнительное значение для добавления в начало массива: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);
	// Insert - добавление элемента в массив по заданному индексу:
	int index;
	cout << "Введите значение индекса для добавления в массив: "; cin >> index;
	cout << "Введите дополнительное значение в массив: "; cin >> value;
	arr = Insert(arr, n, value, index);
	Print(arr, n);
	// Pop_back - удаление последнего элемента массива:
	arr = Pop_back(arr, n);
	Print(arr, n);
	// Pop_front - удаление первого элемента массива:
	arr = Pop_front(arr, n);
	Print(arr, n);
	// Erase - удаление выбранного элемента массива:
	cout << "Введите значение индекса для удаления из массива: "; cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);
#endif // dynamic_memory_1

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Вывод двумерного динамического массива на экран с помощью арифметики указателей и оператора разыменования: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	int index;
	cout << "Введите значение индекса для добавления строки в двумерный массив: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	cout << "Введите значение индекса для удаления строки из массива: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	cout << "Введите значение индекса для добавления столбца в двумерный массив: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	pop_cols_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	pop_cols_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	cout << "Введите значение индекса для удаления строки из двумерного массива: "; cin >> index;
	erase_cols(arr, rows, cols, index);
	Print(arr, rows, cols);
	Clear(arr, rows);
}
void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* Push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[n] = value;
	n++;
	return arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	// 1) создаем буфферный массив указателей:
	int** buffer = new int* [rows + 1];
	// 2) копируем адреса строк из исходного массива в буферный:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	// 3) удаляем исходный массив указателей:
	delete[] arr;
	// 4 Подменяем адрес массива указателей:
	arr = buffer;
	// 5) создаем новую сроку:
	arr[rows] = new int[cols] {};
	// 6) После добавления строки нужно увеличить количество строк массива
	rows++;
	// 7) возвращаем новый массив
	return arr;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	//1) создаем буферную строку:
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		//2) Копируем все содержимое из исходной строки в буферную
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) удаляем исходную строку
		delete[] arr[i];
		//4) Записываем адрес новой строки в массив указаетелей
		arr[i] = buffer;
	}
	cols++;
}
int* Push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
int* Insert(int* arr, int& n, int value, int index)
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
int** insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}
void insert_col(int** arr, const int rows, int& cols, const int index)
{

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
int* Pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	//arr = buffer;
	//rows--;
	return buffer;
}
void pop_cols_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
int* Pop_front(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
void pop_cols_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
int* Erase(int* arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int** erase_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows - 1; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
void erase_cols(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	// 1) Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	// 2) Удаляем массив указателей
	delete[] arr;
	arr = nullptr;
}