#ifndef HEADER_H
#define HEADER_H
class complex {
public:
	double Re;
	double Im;
	void set(double R, double I) {
		Re = R;
		Im = I;
	}
	void print();
	complex operator +(complex c2);
	complex operator -(complex c2);
	complex operator *(complex c2);
	complex operator /(complex c2);
	complex operator =(complex cm);
};
#endif
