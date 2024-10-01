#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(const double x);

int main() {
	double yS, yE, z;
	int n;

	cout << "yS= "; cin >> yS;
	cout << "yE= "; cin >> yE;
	cout << "n= "; cin >> n;

	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(2) << "x" << " |"
		<< setw(7) << "S" << " |" << endl;
	cout << "---------------------------" << endl;


	double dy = (yE - yS) / n;

	double y = yS;

	while (y <= yE) {
		z = f(1 + sqrt(y) + y) + pow(f(1 + f(1) + pow(f(sqrt(y)), 2)), 2);
		cout << y << " " << z << endl;
		y += dy;
	}

	return 0;
}

double f(const double x) {
	if (abs(x) >= 1)
		return (sin(x / 2)) / (1 + pow(cos(x), 2));
	else {
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;

		do {
			i++;
			double R = x * x / ((3 * i - 2) * (3 * i - 1) * 3 * i);
			a *= R;
			S += a;
		} while (i < 6);
		return S;



	}

}
