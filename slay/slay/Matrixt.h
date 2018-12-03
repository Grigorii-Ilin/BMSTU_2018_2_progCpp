#include <fstream>
#include <iostream>

using namespace std;

template <class T>
class Matrixt
{
	T **a;
	int n, m;


public:
	Matrixt();
	Matrixt(int n, int m);
	Matrixt(char* name);
	~Matrixt();

	Matrixt &transp();

};

template <class T> 
Matrixt <T>:: Matrixt(){
	n=1;
	m=1;
	a = new T*[n];
	a[0]=new T;
	a[0][0]=1;
};

template <class T> 
Matrixt <T>:: Matrixt(int n, int m){

	a = new T*[n];
	a=new T*[n];
	for (int i = 0; i < n; i++)
		a[i]=new T[m];
};

template <class T> 
Matrixt <T>::Matrixt(char* name){
	ifstream f1;
	f1 = ifstream(name);
	f1 >> n>>m;
	a=new T* [n];

	for (int i = 0; i < n; i++)
	{
		a[i]=new T[m];
	

	for (int j = 0; j< m; j++)
		f1>>a[i][j];		
	}
	f1.close();
};


template <class T>
Matrixt <T> &Matrixt<T>::transp(){
	Matrixt *fp;
	fp=new Matrixt <T>(m, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fp->a[j][i]=a[i][j];
		}
	}
	return *fp;
}; 
