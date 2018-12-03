// fstream.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <fstream>
#include <iostream>

using namespace std;


class Point
{
public:
	Point();
	~Point();
	double x, y;
};

Point::Point()
{
	x = 0;
	y = 0;
}


Point::~Point()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	int n = 5;
	
	Point *b1;
	int i1;

	float yc[] = { 7, 12, 14, 6, 78, 4, 7, 17, 9 };
	float xc[] = { 27, 2, 34, 24, 16, 7, 8, 4, 27, 7 };

	fstream out, f, in;
	b1 = new Point[n];
	for (size_t i = 0; i < n; i++)
	{
		b1[i].x = xc[i], b1[i].y = yc[i];
	}

	out.open("File1.DAT", ios::out | ios::binary);
	out.write((char*)&n, sizeof(n));
	for (size_t i = 0; i < n; i++)
	{
		out.write((char*)&b1[i], sizeof(b1[i]));
	}

	out.close();
	cout << endl << "File1.DAT" << endl;

	
	in.open("File1.DAT", ios::in | ios::binary);
	in.read((char*)&n, sizeof(n));
	for (size_t i = 0; i < n; i++)
	{
		in.read((char*)&b1[i], sizeof(b1[i]));
		cout << " x= " << b1[i].x << " y= " << b1[i].y << endl;

	}
	in.close();

	cin >> i1;


	/////////

	out.open("File2.DAT", ios::out | ios::binary);
	out.write((char*)&n, sizeof(n));
	for (size_t i = 0; i < n; i++)
	{
		out.write((char*)&b1[i], sizeof(b1[i]));
	}

	out.close();
	cout << endl << "File1.DAT" << endl;


	in.open("File1.DAT", ios::in | ios::binary);
	in.seekg(0, ios::beg);

	in.seekg(0, ios::end);
	int len = in.tellg();
	int m = len / sizeof(Point);
	in.seekg(0, ios::beg);
	cout << " m= " << m << endl;

	//Point* p= new Point;
	Point p;
	int i = 0;
	//while (!in.eof())
	in.read((char*)&n, sizeof(n));
	for (int  i = 0; i < m; i++)
	{
		//cout << " teilg= " << in.tellg() << endl;
		in.read( (char*) & p, sizeof(p));
		cout << " p.x= " <<p.x ;// << " p.y= " << p->y << " i " << i << " teilg= " << in.tellg() << endl;
	
	}

	in.close();
	cin >> i1;
	cout << endl << "File2.DAT" << endl;;


	system("pause");
	return 0;
}

