// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
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
double f1(double x){
	return sin(x);
}

double f2(double x){
	return cos(x);
}

class Baza_Integ_Virt{
public:
	virtual double integral(double esp) { return 1; }
	Baza_Integ_Virt(){	}
	virtual double get_a() = 0;
	virtual double get_b() = 0;

};
// Объявляем потомков:
class  Int_Trap_Virt : public Baza_Integ_Virt{
protected:
	double a = 0, b = 0;
	long int n;
	Fun f;
public:
	Int_Trap_Virt(){
	}

	Int_Trap_Virt(double av, double bv, Fun fv) : Baza_Integ_Virt(){
		a = av, b = bv, f = fv;
	}
	double get_a(){ return a; }
	double get_b(){ return b; }

	double integral(double eps){
		n = 100; // ВАЖНО пока задаем вручную, epsilon не учитываем

		double s, sp = 0, h, y, x, d = 0;
		h = (b - a) / n; // шаг
		s = (f(a) + f(b))*(h / 2);//площадь
		x = a;

		for (long int i = 1; i < n - 1; i++)
		{
			x += h; 
			s += f(x)*h; 
		}

		return s;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	int m = 1;
	Baza_Integ_Virt *pf[3];
	pf[0] = new Int_Trap_Virt(-3, 3, f2);

	for (size_t i = 0; i < m; i++)
	{
		cout << "integral: " << pf[i]->integral(0.1e-5) << endl;

	}

	char temp;
	cin >> temp;

	return 0;
}

