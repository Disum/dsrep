#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

template<typename T>
class Matrix{
public:
	// Конструктор
	Matrix(int m, int n) :elem{new T[m*n]}, numRows{m}, numColumns{n} { }

	// Доступ к элементам по индексам
	T& operator()(int m, int n) { return elem[m*numColumns + n]; }

	// Копирование
	Matrix& operator=(const Matrix& other) {
		if ( (numRows!=other.numRows)||(numColumns!=other.numColumns) )
			throw invalid_argument("Копирование не выполнено: матрицы разных размеров!");

		for (int i = 0; i!=numRows; ++i)
			for (int j = 0; j!=numColumns; ++j)
				elem[i*numColumns + j] = other.elem[i*numColumns + j];

		return *this;
	}

	// Сложение
	Matrix& operator+(const Matrix& other) {
		if ( (numRows!=other.numRows)||(numColumns!=other.numColumns) )
			throw invalid_argument("Сложение не выполнено: матрицы разных размеров!");
		
		for (int i = 0; i!=numRows; ++i)
			for (int j = 0; j!=numColumns; ++j)
				elem[i*numColumns + j] += other.elem[i*numColumns + j];

		return *this;
	}

	void scan() {
		for (int i = 0; i!=numRows; ++i)
			for (int j = 0; j!=numColumns; ++j) {
				cout  << "(" << i << ", " << j << ")=";
				cin >> elem[i*numColumns + j];
			}
	}

	void print() {
		for (int i = 0; i!=numRows; ++i) {
			for (int j = 0; j!=numColumns; ++j)
				cout << elem[i*numColumns + j] << '\t';
			cout << endl;
		}
	}

private:
	unique_ptr<T[]> elem;	// "Умный" указатель на элементы
	int numRows;		// Число строк матрицы
	int numColumns;		// Число столбцов матрицы
};

int main() {
	int numRows, numColumns;

	cout << "iMatr:" << endl << "Число строк матрицы:\t";
	cin >> numRows;
	cout << "Число столбцов матрицы:\t";
	cin >> numColumns;
	Matrix<int> iMatr(numRows, numColumns);
	//iMatr.scan();
	//iMatr.print();

	
	cout << "iMatr2:" << endl << "Число строк матрицы:\t";
	cin >> numRows;
	cout << "Число столбцов матрицы:\t";
	cin >> numColumns;
	Matrix<int> iMatr2(numRows, numColumns);
	//iMatr2.scan();
	//iMatr2.print();

	cout << "iMatr3:" << endl << "Число строк матрицы:\t";
	cin >> numRows;
	cout << "Число столбцов матрицы:\t";
	cin >> numColumns;
	Matrix<int> iMatr3(numRows, numColumns);

	try { iMatr3 = iMatr2 + iMatr; }
	catch (invalid_argument e) {
		cout << "Error!" << endl;
		cout << e.what() << endl;

		return 0;
	}

	//cout << "iMatr3:" << endl;
	//iMatr3.print();

	return 0;
}
