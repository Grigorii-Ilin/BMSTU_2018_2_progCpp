#include <fstream>
#include <iostream>

using namespace std;

template <class T>
class Matrixt
{
	T **myMatrix;
	int rowsCount, columnsCount;


public:
	Matrixt();
	Matrixt(const int rowsCountF, const int colsCountF);
	Matrixt(char* name);
	~Matrixt();

	Matrixt &transp();

	Matrixt<T> & Matrixt:: operator=(const Matrixt &r); // оператор присваивания 


	friend ostream &operator<<(ostream &out, const Matrixt<T> &r) {
		out << endl;
		out << "Matrix: " << r.rowsCount << " " << r.columnsCount << endl;
		for (int i = 0; i < r.rowsCount; i++) {
			for (int j = 0; j < r.columnsCount; j++) {
				out << r.myMatrix[i][j] << "   ";
			}
			out << endl;
		}
		return out;
	}

};


template <class T>
Matrixt <T>::Matrixt() {
	rowsCount = 1;
	columnsCount = 1;
	myMatrix = new T*[rowsCount];
	myMatrix[0] = new T;
	myMatrix[0][0] = 1;
};

template <class T>
Matrixt <T>::Matrixt(int rowsCountF, int colsCountF) {
	rowsCount = rowsCountF;
	columnsCount = colsCountF;

	myMatrix = new T*[rowsCount];
	for (int i = 0; i < rowsCount; i++)
		myMatrix[i] = new T[columnsCount];
};

template <class T>
Matrixt <T>::Matrixt(char* filename) {
	ifstream ifs; 
	ifs.open(filename, ios::in);

	if (!ifs) {
		cout << "File not found" << endl;
	}

	ifs >> rowsCount >> columnsCount;
	myMatrix = new T*[rowsCount];

	for (int i = 0; i < rowsCount; i++)
	{
		myMatrix[i] = new T[columnsCount];

		for (int j = 0; j < columnsCount; j++)
			ifs >> myMatrix[i][j];
	}
	ifs.close();
};

template <class T>
Matrixt <T>::~Matrixt() {
	for (int i = 0; i < rowsCount; i++) {
		delete[] myMatrix[i];
	}

	delete[] myMatrix;
}


template <class T>
Matrixt <T> &Matrixt<T>::transp() {
	Matrixt *resultMatrix;
	resultMatrix = new Matrixt <T>(columnsCount, rowsCount);
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < columnsCount; j++)		{
			resultMatrix->myMatrix[j][i] = myMatrix[i][j];
		}
	}
	return *resultMatrix;
}

template<class T>
 Matrixt<T> &Matrixt<T>::operator=(const Matrixt & r){
	 if (&r==this)  
		 return *this;

	if (rowsCount!=r.rowsCount||columnsCount!=r.columnsCount)		 {
		Matrixt <T>::~Matrixt();

		rowsCount = r.rowsCount;
		myMatrix = new T*[rowsCount];
			 
		columnsCount = r.columnsCount;
		for (int i = 0; i < rowsCount; i++)
			myMatrix[i] = new T[columnsCount];
	}

	for (int i = 0; i < rowsCount; i++)	 {
		for (int j = 0; j < columnsCount ; j++) {
			myMatrix[i][j] = r.myMatrix[i][j];
		}
	}

	return *this;
 };

