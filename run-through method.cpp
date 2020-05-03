#include <iostream>
#include <cmath>
using namespace std;

int a(int i) {
	if (i == 1) return 0;
	else return i + 20;
}
long double b(int i) {
	return pow(-1, i + 20);
}
long double c(int i) {
	return pow(-i + 20, i + 20);
}
int d(int i) {
	return 20 - i;
}
void progonka(int n) {
	cout << "Метод прогонки 10 cтрок\n";
	int i = 1;
	long double x0 = 1, v0, u0;
	long double u = -c(i) / b(i);
	long double v = d(i) / b(i);
	long double x = u * x0 + v;
	cout << "x" << i <<" = "<< x  << endl;
	i++;
	while (i < n) {
		v0 = v; u0 = u;
		x0 = x;
		u = -c(i) / (a(i) * u0 + b(i));
		v = (d(i) - a(i) * v0) / (a(i) * u0 + b(i));
		x = u * x0 + v;
		cout << "x" << i << " = " << x << endl;
		i++;
	}
	x = (d(i) - a(i) * v) / (a(i) * u + b(i));
	cout << "x" << i << " = " << x << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	progonka(10);
}
