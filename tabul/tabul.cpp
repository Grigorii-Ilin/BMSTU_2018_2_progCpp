// tabul.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <locale.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning (disable : 4996)

using namespace std;

class Point
{
public:
	Point();
	Point(double xv, double yv);
	~Point();

	void set_p()
	{
		cout << "¬ведите координаты точки: "; 
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


	double rasst(Point t)
	{
		double distanceXP2 = pow(x - t.x, 2);
		double distanceYP2 = pow(y - t.y, 2);
		double res = sqrt(distanceXP2 + distanceYP2);
		return res;
	}


private:
	double x, y;
};

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double xv, double yv)
{
	x = xv;
	y = yv;
}

Point::~Point()
{
}

typedef double(*Fun)(double);

double f1(double x){
	return sin(x);
}

double f2(double x){
	return cos(x);
}


class Baza_tab{
	double a, b;
	int n;
	Point *p;
public:
	double get_a(){
		return a;
	}
	double get_b(){
		return b;
	}
	int get_n(){
		return n;
	}
	Point* get_p(){
		return p;
	}

	Baza_tab();
	Baza_tab(double av, double bv, int nv);

	~Baza_tab();
	void destroy();

	void tabul_v(Fun f); //void tabul_v(double(*f)(double));
	Point* tabul(Fun f);
};

Baza_tab::Baza_tab(){
	a=0.0;
	b=0.0;
	n=0;
}

Baza_tab::Baza_tab(double av, double bv, int nv){
	a=av;
	b=bv;
	n=nv;
	Point* p=new Point[n];
}

void Baza_tab::destroy(){
	if (p && n>0){
		delete []p;
		n=0;
	}
}

void Baza_tab::tabul_v(Fun f){
	double x=a;
	double y=0.0;
	double h=(b-a)/n;

	for (int i = 0;  i < n; i++)
	{
		y=f(x);
		p[i]=Point(x, y);
		x+=h;
	}
}

Point* Baza_tab::tabul(Fun f){
	double x=a;
	double y=0.0; 
	double h=(b-a)/n;

	for (int i = 0;  i < n; i++)
	{
		y=f(x);
	//	p[i].set_p
		p[i]=Point(x, y);
		x+=h;
	}
	return p;
}

Baza_tab::~Baza_tab(){
	destroy();
}


int _tmain(int argc, _TCHAR* argv[])
{
	Baza_tab fp, *fv;
	Point *tv, ta;

	Fun mas_f[]={f1, f2};
	fv=new Baza_tab(-9.0,9.0,10);
	fv->tabul_v(f1);
//	fv->get_p();

	/*tv=fv->tabul(f1);

	for (int i = 0; i < fv->get_n(); i++)
	{
		cout<<tv[i].get_x()<<"  "<<tv[i].get_y();
	}

	fv->~Baza_tab();
	*/
	int temp;
	cin>>temp;
	//getch(temp);
	return 0;
}

