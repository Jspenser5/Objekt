#include<fstream>
#include<iostream>
#include<math.h>
#include "matrix_functions.h"
using namespace std;

void print_matrix(double* matrix[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << '\n';
	}
	cout << endl;
}


double** read_matrix(ifstream& matrix, int& size,bool& flag) {
	matrix >> size;
	double** mat = new double* [size];
	for (int i = 0; i < size; i++)
		mat[i] = new double[size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix.eof()) {
				flag = 1;
				double** not_full=nullptr;
				return not_full;
			}
			matrix >> mat[i][j];
		}
	}
	return mat;
}
void clear(double* arr[], int size) {
	for (int i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}
void mult(double* mat1[], double* mat2[], int size) {
	double** matr1 = new double* [size];
	for (int i = 0; i < size; i++) {
		matr1[i] = new double[size] {};
		for (int j = 0; j < size; j++) {
			matr1[i][j] = mat1[i][j];
			mat1[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int s = 0; s < size; s++) {
				mat1[i][j] += matr1[i][s] * mat2[s][j];
			}
		}
	}
	clear(matr1, size);
}

double** power(double* mat[], int size, int step) {
	double** matr1 = matrix_copy(mat,size);
	for (int k = 1; k < step; k++) {
		mult(matr1, mat, size);
	}
	return matr1;
}

double** num_mult(double* mat[], int size, int value) {
	double** matr1 = matrix_copy(mat, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matr1[i][j] = value * matr1[i][j];
		}
	}
	return matr1;
}

void summ_matr(double* matr1[], double* matr2[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matr1[i][j] += matr2[i][j];
		}
	}
}

void summ_with_num(double* matr1[], int size, int value) {
	for (int i = 0; i < size; i++) {
		matr1[i][i] += value;
	}
}

double** minor(double* matrix[], int size, int deleted_row, int deleted_column) {
	double** minor_matrix = new double* [size - 1];
	for (int i = 0; i < size - 1; i++)
		minor_matrix[i] = new double[size - 1];
	int j = 0;
	int r = 0;
	for (int i = 0; i < size; i++) {
		if (i != deleted_row) {
			for (int k = 0; k < size; k++) {
				if (k != deleted_column) {
					minor_matrix[r][j] = matrix[i][k];
					j++;
				}
			}
			j = 0;
			r++;
		}
	}
	return minor_matrix;
}
double matrix_determinant(double* matrix[], int size) {
	if (size == 1)
		return matrix[0][0];
	double determinant = 0;
	for (int j = 0; j < size; j++) {
		double** matrix_minor = minor(matrix, size,0, j);
		determinant += pow(-1, j) * matrix[0][j] * matrix_determinant(matrix_minor, size - 1);
		clear(matrix_minor, size - 1);
	}
	return determinant;
}
double** inverse_matrix(double* matrix[], int size) {
	int determinant = matrix_determinant(matrix, size);
	double** matr1 = new double* [size];
	for (int i = 0; i < size; i++)
		matr1[i] = new double[size] {};
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			double** minr = minor(matrix, size, j, i);
			matr1[i][j] = (1 / determinant) * pow(-1, i + j) * matrix_determinant(minr, size - 1);
			clear(minr, size - 1);
		}
	}
	return matr1;
}

double** matrix_copy(double* matrix[], int size) {
	double** matr = new double* [size];
	for (int i = 0; i < size; i++) {
		matr[i] = new double[size] {};
		for (int j = 0; j < size; j++)
			matr[i][j] = matrix[i][j];
	}
	return matr;
}
/*Ответ: 0 7 4
         0 1 0
		 1 13 0*/