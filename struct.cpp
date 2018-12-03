// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <stdio.h>


struct Point
{
	double x, y;
	//double r;
};

struct Line
{
	Point t1, t2;
	double k, b; // y=kx+b
	double r;
};

struct Okr
{
	Point center;
	double rad;
};

double rasst(Point &t1, Point &t2)
{
	double distanceX = t1.x - t2.x;
	double distanceY = t1.y - t2.y;
	double res = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
	return res;
}

Line &lin_fun(Point &t1, Point &t2)
{
	Line line;
	line.t1 = t1;
	line.t2 = t2;

	double distanceX = t1.x - t2.x;
	double distanceY = t1.y - t2.y;

	distanceX != 0 ? line.k = distanceY / distanceX : line.k = 0;

	line.r = rasst(line.t1, line.t2);
	return line;
}

void swap(double &left, double &right)
{
	double tmp = left;
	left = right;
	right = tmp;
}

void sort_pob(double *mas, int n)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	Point t[] = { { 7, 10 }, { 17, 5 }, { 15, 16 }, { 8, 14 }, { 19, 14 } };
	const unsigned int n = 5;

	Point *masp = new Point[n];
	printf_s("\n points:");
	for (size_t i = 0; i < n; i++)
	{
		masp[i].x = t[i].x;
		masp[i].y = t[i].y;

		printf_s("\n %f %f", masp[i].x, masp[i].y);
	}
	
	double q[n][n];
	//for (size_t i = 0; i < n - 1; i++)
	//{
	//	for (size_t j = i + 1; j < n; j++)
	//	{
	//		q[i][j] = 0;
	//	}
	//}

	printf_s("\n vychislyaem rasstoyanie:");
	for (size_t i = 0; i < n-1; i++)
	{
		printf_s("\n tochka1 index: %i, x: %f, y: %f", i, masp[i].x, masp[i].y);
		for (size_t j = i+1; j < n; j++)
		{
			printf_s("\n tochka2 index: %i, x: %f, y: %f", j, masp[j].x, masp[j].y);
			q[i][j] = rasst(masp[i], masp[j]);
			printf_s("\n rasstoyanie %f", q[i][j]);
		}
	}



	int a;
	scanf_s("%d", &a);

	return 0;
}

