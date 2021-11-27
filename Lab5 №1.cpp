//4. ����������� ����� �������� ������ �� ����� ������ �������� �����.
//�������� �������� �������� ������
#include<iostream>
#include<fstream>
#include"Encoding and Decoding.h"
using namespace std;

int get_norm_input() {
	while (true) {
		int value;
		cin >> value;
		if (cin.fail()) {
			cout << "����������� �������. ��������� ����: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return value;
	}
}

int main(int argc,char* argv[]) {
	setlocale(LC_ALL, "rus");
	if (argc < 3) {
		cout << "��������� ������ ������";
		system("pause");
		return 0;
	}
	ifstream text(argv[1]);
	ifstream text_check(argv[2]);
	if (!chek_input_files(text,text_check))
		return 0;
	text_check.close();
	int key;
	cout << "������� �������� (2-check texts similarity/1-encode/0-decode): ";
	key = get_norm_input();
	if (key == 1) {
		int max_len = max_word_len(text);
		ofstream textcrypt(argv[2]);
		get_encoded_text(text, textcrypt, max_len);
		textcrypt.close();
	}
	else if (key == 0) {
		int max_len = max_word_len(text);
		ofstream textcrypt(argv[2]);
		get_uncoded_text(text, textcrypt, max_len);
		textcrypt.close();
	}
	else if (key == 2) {
		text_check.open(argv[2]);
		if (chek_texts(text, text_check))
			cout << "����� ��������� ���������" << endl;
		else
			cout << "����� �� ���������" << endl;
		text_check.close();
	}
	else
		cout << "����������� �������" << endl;
	text.close();
	system("pause");
	return 0;
}