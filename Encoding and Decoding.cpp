#include <fstream>
#include<iostream>
using namespace std;

int max_word_len(ifstream& txt) {
	char word[50];
	int max_len = 0, len;
	while (!txt.eof()) {
		txt >> word;
		len = strlen(word);
		if (int(word[len - 1]) >= 0)
			len--;
		if (len > max_len)
			max_len = len;
	}
	txt.seekg(0, ios::beg);
	return max_len;
}
void get_encoded_text(ifstream& firsttxt, ofstream& cryptfout, int shift) {
	int c;
	while (true) {
		c = int(firsttxt.get());
		if (firsttxt.eof())
			break;
		if (192 <= c and c <= 223) {
			if ((c + shift) > 223)
				c = 191 + shift - (223 - c);
			else
				c = c + shift;
		}
		else if (224 <= c and c <= 255) {
			if ((c + shift) > 255)
				c = 223 + shift - (255 - c);
			else
				c = c + shift;
		}
		cryptfout << char(c);
	}
}
void get_uncoded_text(ifstream& firsttxt, ofstream& decryptfout, int shift) {
	int c;
	while (true) {
		c = int(firsttxt.get());
		if (firsttxt.eof())
			break;
		if (192 <= c and c <= 223) {
			if ((c - shift) < 192)
				c = 224 - shift + (c - 192);
			else
				c = c - shift;
		}
		else if (224 <= c and c <= 255) {
			if ((c - shift) < 224)
				c = 256 - shift + (c - 224);
			else
				c = c - shift;
		}
		decryptfout << char(c);
	}
}
bool chek_input_files(ifstream &text, ifstream &textcrypt1) {
	if (!text.is_open()) {
		std::cout << "Файл ввода не найден" << endl;
		return 0;
	}
	if (!textcrypt1.is_open()) {
		std::cout << "Файл вывода не найден" << endl;
		return 0;
	}
	return 1;
}

bool chek_texts(ifstream& text1, ifstream& text2) {
	while (true) {
		if (text1.get() != text2.get())
			return 0;
		if (text1.eof() or text2.eof())
			break;
	}
	return 1;
}