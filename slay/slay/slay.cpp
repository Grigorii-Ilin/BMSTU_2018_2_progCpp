// slay.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "Matrixt.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Matrixt <double>m ("I:\\MY_DOK\\МГТУ им. Н.Э. Баумана\\обуч\\5сем\\прогр\\BMSTU_2018_2_progCpp\\slay\\Debug\\DatDouble1.txt");
	cout << m;

	Matrixt <double>mT(3, 3);
	mT =  m.transp();
	cout << mT;

	system("pause");
	return 0;

}

