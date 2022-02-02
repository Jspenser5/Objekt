#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H
#include<fstream>

//Скопировать матрицу
double** matrix_copy(double* matrix[], int size);

//Вывести матрицу
void print_matrix(double* matrix[], int size);

//Считать матрицу и её размер из файла
double** read_matrix(std::ifstream& matrix, int& size, bool& flag);

//Очистить двумерный динамический массив
void clear(double* arr[], int size);

//Перемножить матрицы (результат заносится в первую переданную)
void mult(double* mat1[], double* mat2[], int size);

//Возведение матрицы в степень
double** power(double* mat[], int size, int step);

//Умножение матрицы на число
double** num_mult(double* mat[], int size, int value);

//Сложение матриц (результат заносится в первую переданную)
void summ_matr(double* matr1[], double* matr2[], int size);

//Сложение матрицы с единичной , имеющей коэфициент (value)
void summ_with_num(double* matr1[], int size, int value);

//Вспомогательная функция для matrix_determinant() позволяющая построить минор по первой строке и deleted_column столбцу
double** minor(double* matrix[], int size,int deleted_row, int deleted_column);

//Вычисление определителя матрицы
double matrix_determinant(double* matrix[], int size);

//Построить обратную матрицу
double** inverse_matrix(double* matrix[], int size);
#endif //MATRIX_FUNCTIONS_H
