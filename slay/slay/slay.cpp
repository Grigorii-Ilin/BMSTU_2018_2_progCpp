// slay.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "Matrixt.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Matrixt <double>a ("dat1.txt");
	
	a.transp();

	system("pause");
	return 0;

}

