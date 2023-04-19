#include<iostream>
using namespace std;

#define delimiter "\n----------------------------------------------\n"

void Exchange(int a, int b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2; int b = 3;
	cout << a << "\t" << b << endl;
	cout << &a << "\t" << &b << endl;
	cout << delimiter << endl;
	Exchange(a, b);
	cout << a << "\t" << b << endl;
	cout << &a << "\t" << &b << endl;
	cout << delimiter << endl;
}
void Exchange(int a,int b)
{
	cout << &a << "\t" << &b << endl;
	int buffer = a;
	a = b;
	b = buffer;
	cout << a << "\t" << b << endl;
}