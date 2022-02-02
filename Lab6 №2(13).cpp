//Вычислить определитель n-го порядка,элементы которого заданы a(i,j)=|i-j|
#include<iostream> 
#include"matrix_functions.h"
using namespace std;
int get_norm_input() {
	while (true) {
		int value;
		cin >> value;
		if (cin.fail() or value<=0) {
			cout << "Введён недопустимый параметр. Повторите ввод: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return value;
	}
}


int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размерность квадратной матрицы : ";
	int size = get_norm_input();
	//Конструирование нужной матрицы
	double** matrix = new double* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new double[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = abs(i - j);
	}
	print_matrix(matrix, size);
	cout << matrix_determinant(matrix,size)<<endl;
	clear(matrix, size);
	return 0;
}