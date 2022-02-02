#include<iostream> 
#include"matrix_functions.h"
using namespace std;

int main(int argc,char* argv[]) {
	setlocale(LC_ALL, "rus");
	if (argc < 2) {
		cout << "Не введено имя файла" << endl;
		return 0;
	}
	ifstream matrix_file(argv[1]);
	if (!matrix_file.is_open()) {
		cout << "Файл ввода не найден" << endl;
		return 0;
	}
	bool flag = 0;
	int size;
	double** first_matrix = read_matrix(matrix_file, size, flag);
	double** rezult_matrix = read_matrix(matrix_file, size, flag);
	if (flag) {
		cout << "Отсуцтвуют необходимые элементы матриц" << endl;
		return 0;
	}
	//Вычисления A*X-3X=B
	double** f_matrix = matrix_copy(first_matrix, size);
	summ_with_num(f_matrix, size, -3);
	double** inverse_f_matrix = inverse_matrix(f_matrix, size);
	mult(inverse_f_matrix, rezult_matrix, size);
	cout << "Answer" << endl;
	print_matrix(inverse_f_matrix, size);
	cout << "------------------------------------" << endl;
	//Проверка
	cout << "A*X" << endl;
	mult(first_matrix, inverse_f_matrix, size);
	print_matrix(first_matrix, size);
	double** m2 = num_mult(inverse_f_matrix, size, -3);
	cout << "-3X" << endl;
	print_matrix(m2, size);
	summ_matr(first_matrix, m2, size);
	cout << "Rezult" << endl;
	print_matrix(first_matrix, size);
	clear(m2, size);
	clear(first_matrix, size);
	clear(f_matrix, size);
	clear(inverse_f_matrix, size);
	clear(rezult_matrix, size);
	matrix_file.close();
	return 0;
}