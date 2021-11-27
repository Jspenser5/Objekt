#ifndef ENCODING_AND_DECODING_H
#define ENCODING_AND_DECODING_H
#endif//ENCODING_AND_DECODING_H
#include <fstream>
using namespace std;

//Ќайти максимальную длину слова в тексте
int max_word_len(ifstream& txt);

//«аписывает закодированный текст
void get_encoded_text(ifstream& firsttxt, ofstream& fout, int shift);

//«аписывает декодированный текст
void get_uncoded_text(ifstream& firsttxt, ofstream& fout, int shift);

//
bool chek_input_files(ifstream &text, ifstream &textcrypt1);

bool chek_texts(ifstream& text1, ifstream& text2);