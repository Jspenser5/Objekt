#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H
#include<fstream>

//����������� �������
double** matrix_copy(double* matrix[], int size);

//������� �������
void print_matrix(double* matrix[], int size);

//������� ������� � � ������ �� �����
double** read_matrix(std::ifstream& matrix, int& size, bool& flag);

//�������� ��������� ������������ ������
void clear(double* arr[], int size);

//����������� ������� (��������� ��������� � ������ ����������)
void mult(double* mat1[], double* mat2[], int size);

//���������� ������� � �������
double** power(double* mat[], int size, int step);

//��������� ������� �� �����
double** num_mult(double* mat[], int size, int value);

//�������� ������ (��������� ��������� � ������ ����������)
void summ_matr(double* matr1[], double* matr2[], int size);

//�������� ������� � ��������� , ������� ���������� (value)
void summ_with_num(double* matr1[], int size, int value);

//��������������� ������� ��� matrix_determinant() ����������� ��������� ����� �� ������ ������ � deleted_column �������
double** minor(double* matrix[], int size,int deleted_row, int deleted_column);

//���������� ������������ �������
double matrix_determinant(double* matrix[], int size);

//��������� �������� �������
double** inverse_matrix(double* matrix[], int size);
#endif //MATRIX_FUNCTIONS_H
