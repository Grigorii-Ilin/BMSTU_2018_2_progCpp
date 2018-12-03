// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

class Array{
	int *ptr;
	int size;
public:
	Array();
	Array(const int n);
	Array(const Array & ar);
	void set_file(char* name);
	Array& operator = (Array &rt);
};

Array::Array(){
	size = 0;
	ptr = 0;
};

Array::Array(const int n){
	size = n;
	ptr = new int[n];
	for (int i = 0; i < n; i++)
	{
		ptr[i] = 0;
	}
};

Array::Array(const Array & ar){
	size = ar.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = ar.ptr[i];
	}
};

Array&  Array::operator=(Array &rt){
	if (&rt==this)
	{
		return *this;
	}
	if (size!=rt.size)
	{
		if (ptr>0)
		{
			delete[] ptr;
		}
		size = rt.size;
	}
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rt.ptr[i];
	}
	return *this;
}

void Array::set_file(char* name){
	ifstream f1;
	f1 = ifstream(name);
	f1 >> n;

}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

