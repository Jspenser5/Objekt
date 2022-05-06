#include<iostream>
#include"Header.h"
using namespace std;
void complex::print() {
	cout << Re << " + " << Im << "i\n";
}
complex  complex::operator +(complex c2) {
	complex tmp;
	tmp.set(this->Re + c2.Re, this->Im + c2.Im);
	return tmp;
}
complex complex::operator -(complex c2) {
	complex tmp;
	tmp.set(this->Re - c2.Re, this->Im - c2.Im);
	return tmp;
}
complex complex::operator *(complex c2) {
	complex tmp;
	tmp.set((this->Re) * (c2.Re) - (this->Im) * (c2.Im), (this->Re) * (c2.Im) + (this->Im) * (c2.Re));
	return tmp;
}
complex complex::operator /(complex c2) {
	complex tmp;
	tmp.set(((this->Re) * (c2.Re) + (this->Im) * (c2.Im)) / (c2.Re * c2.Re + c2.Im * c2.Im), ((this->Im) * (c2.Re) - (this->Re) * (c2.Im)) / (c2.Re * c2.Re + c2.Im * c2.Im));
	return tmp;
}
complex complex::operator =(complex cm)
{
	Re = cm.Re;
	Im = cm.Im;
	return *this;
}