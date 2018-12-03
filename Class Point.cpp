// Class Point.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <locale.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
//#include <cmath>
#include <stdlib.h>
//#include <ctype.h>
#pragma warning (disable : 4996)

using namespace std;

void rusLang()
{
	const UINT CodePageID = 1251;
	SetConsoleCP(CodePageID);
	SetConsoleOutputCP(CodePageID);
	setlocale (LC_ALL, "Russian");
}

template <class T>
void swap1 (T &left, T &right)
{
	T temp=left;
	left=right;
	right=temp;
}


class point
{
public:
	point();
	point(double xv, double yv);
	~point();

	void set_p()
	{
		cout << "������� ���������� �����: "; 
		cin >> x >> y;
		cout << endl;
	}

	double get_x()
	{
		return x;
	}

	double get_y()
	{
		return y;
	}



	double rasst(point t)
	{
	double distanceXP2 = pow(x - t.x, 2);
	double distanceYP2 = pow(y - t.y, 2);
	double res = sqrt(distanceXP2 + distanceYP2);
	return res;
	}


private:
	double x, y;
};

point::point()
{
	x = 0;
	y = 0;
}

point::point(double xv, double yv)
{
	x = xv;
	y = yv;
}

point::~point()
{
}


void insertionSort(int *arrayPtr, int length) // ���������� ���������
{
    //int temp, // ��������� ���������� ��� �������� �������� �������� ������������ �������
    //    item; // ������ ����������� ��������
    for (int counter = 1; counter < length; counter++)
    {
        int temp = arrayPtr[counter]; // �������������� ��������� ���������� ������� ��������� �������� �������
        int item = counter - 1; // ���������� ������ ����������� �������� �������
        while(item >= 0 && arrayPtr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
        {
            arrayPtr[item + 1] = arrayPtr[item]; // ������������ ��������� �������
            arrayPtr[item] = temp;
            item--;
        }
    }
}

void swapSort(int *arrayPtr, int length) // ���������� �������
{
	//int i, flag;
	
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < length - 1; i++)
		{
			if (arrayPtr[i] > arrayPtr[i + 1])
			{
				swap1(arrayPtr[i], arrayPtr[i + 1]);
				flag = true;
			}
		}
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	rusLang();

	int n;
 	cout << "������� ����� �����: ";
	cin >> n;
	cout << endl;

    point* pointMas = new point[n]; 

    for (int i = 0; i < n; i++)
	{
		pointMas[i].set_p();
	}

	cout << "����� ������� �����: " << endl;

	for (int i = 0; i < n; i++) 
	{
		cout << "X: " << pointMas[i].get_x() << "; Y: " << pointMas[i].get_y() << ";" << endl; 
	}

	double **wayMatrix;
	wayMatrix = new double*[n];
	for (int i = 0; i < n; i++) 
        wayMatrix[i] = new double[n];

	cout << "������� � ����� ������� ����������: " << endl;

    for (int i = 0; i < n; i++) {
		cout << i<< ' ';
        for (int j = 0; j < n; j++) 
        { 
			cout << j<< ' ';
			wayMatrix[i][j]=pointMas[i].rasst(pointMas[j]);
            cout << wayMatrix[i][j] << endl; 
        } 
        cout << endl;
	}



	cout << endl << "����� ���������������� ������� �����: " << endl;

    for (int i = 0; i < n; i++) 
	{
		cout << "X: " << pointMas[i].get_x() << "; Y: " << pointMas[i].get_y << endl; 
	}

	system("pause");
	return 0;
}
