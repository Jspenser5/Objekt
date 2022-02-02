#include<iostream>
#include<fstream>
#include"matrix_functions.h"
using namespace std;



double** f_func(double* mat[], int size) {
	cout << "f(x):" << endl;
	double** step_1 = power(mat, size, 2);
	cout << "x^2" << endl;
	print_matrix(step_1, size);
	double** step_2 = num_mult(mat,size,2);
	cout << "2x" << endl;
	print_matrix(step_2, size);
	summ_matr(step_1, step_2, size);
	summ_with_num(step_1, size, -5);
	clear(step_2,size);
	cout << "rezult:" << endl;
	print_matrix(step_1, size);
	return step_1;
}

double** g_func(double* mat[], int size) {
	cout << "g(x):"<<endl;
	double** step_1 = power(mat, size, 2);
	double** step_2 = num_mult(step_1, size, 2);
	cout << "2x^2" << endl;
	print_matrix(step_2, size);
	double** step_3 = num_mult(mat, size, -1);
	cout << "-x" << endl;
	print_matrix(step_3, size);
	summ_matr(step_2, step_3,size);
	clear(step_1, size);
	clear(step_3, size);
	cout << "rezult:" << endl;
	print_matrix(step_2, size);
	return step_2;
}

int main(int argc,char* argv[]) {
	if (argc < 2) {
		cout << "Не введено имя файла" << endl;
		return 0;
	}
	ifstream matrix(argv[1]);
	if (!matrix.is_open()) {
		cout << "Файл ввода не найден" << endl;
		return 0;
	}
	//Считывание матрицы и её размера
	int size;
	double** mat = read_matrix(matrix, size);
	//Вычисления и вывод результата
	double** matrix_f = f_func(mat,size);
	double** matrix_g = g_func(mat, size);
	mult(matrix_f, matrix_g, size);
	clear(matrix_g, size);
	cout << "---------------------------------" << '\n' << "Answer:" << endl;
	print_matrix(matrix_f, size);
	clear(matrix_f, size);
	clear(mat, size);
	matrix.close();
	return 0;
}