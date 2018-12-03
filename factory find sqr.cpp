// factory find sqr.cpp: определ€ет точку входа дл€ консольного приложени€.
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

typedef double(*Fun)(double);
double f1(double x) {
	return pow(x, 2) - x - 2; //sqr= -1, 2
}

double f2(double x) {
	return 2 * pow(x, 2) + 5 * x - 10;//-3.8, 1.3
}

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
	a = 0.0;
	b = 0.0;
	n = 0;
}

Baza_tab::Baza_tab(double av, double bv, int nv){
	a = av;
	b = bv;
	n = nv;
	Point* p = new Point[n];
}

void Baza_tab::destroy(){
	if (p && n>0){
		delete[]p;
		n = 0;
	}
}

void Baza_tab::tabul_v(Fun f){
	double x = a;
	double y = 0.0;
	double h = (b - a) / n;

	for (int i = 0; i < n; i++)
	{
		y = f(x);
		p[i] = Point(x, y);
		x += h;
	}
}

Point* Baza_tab::tabul(Fun f){
	double x = a;
	double y = 0.0;
	double h = (b - a) / n;

	for (int i = 0; i < n; i++)
	{
		y = f(x);
		p[i] = Point(x, y);
		x += h;
	}
	return p;
}

Baza_tab::~Baza_tab(){
	destroy();
}

class interval_nul: public Baza_tab{
private:
	int kol_in;
	Point *p_in;
public:
	interval_nul(double av, double bv, int nv) :Baza_tab(av, bv, nv){
		kol_in = 0;
		p_in = 0;
		cout << "const interval_nul" << endl;
	}

	void interval_nul_procedure(){
		Point *dt = new Point(n);
		int j = 0;
		for (size_t i = 0; i < n-1; i++)
		{

		}

	}
};


class Baza_poisk_virt{
public:
	Baza_poisk_virt(){
	}
	virtual double poisk(double eps) = 0;
	virtual double get_a() = 0;
	virtual int get_n() = 0;
	virtual ~Baza_poisk_virt(){
	};
};

class Met_xord_virt : public Baza_poisk_virt
{
public:
	Met_xord_virt(){
	};

	Met_xord_virt(double av, double bv, Fun fv) : Baza_poisk_virt(){
		a = av, b = bv, f = fv;
	}

	~Met_xord_virt(){
	};

	double poisk(double eps){
		double xt = 0;
		double fa = f(a);
		double fb = f(b);
		double xp = a - fa*((b - a) / (fb - fa));
		double d = 1;
		double fx = f(xp);
		n = 1;

		while (abs(fx) > eps && abs(d) > eps && n < 55360){
			if (fa*fx < 0)
			{
				b = xp;
				fb = fx;
			}
			else
			{
				a = xp;
				fa = fx;
			}
			xt = a - fa*((b - a) / (fb - fa));
			fx = f(xt);
			d = xt - xp;
			xp = xt;// текущее в предыдущее 
			n++;
		}
		return xp;
	}

	int get_n(){
		return n;
	}

	double get_a(){
		return a;
	}


protected:
	double a, b;
	int n;
	Fun f;
};





int _tmain(int argc, _TCHAR* argv[])
{
	Fun mas_f[] = { f1, f2 };

	Point *tv, *t0, *te;
	int i, j, n, m, k, j1;
	double s, xp;


	return 0;
}

