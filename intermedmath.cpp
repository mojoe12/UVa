#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	cout << fixed << setprecision(3);
	for (int c = 1; c <= k; c++) {
		int d, v, u;
		cin >> d >> v >> u;
		cout << "Case " << c << ": ";
		if (v >= u || v == 0 || u == 0) {
			cout << "can't determine" << endl;
			continue;
		}
		double p = d * ((1/sqrt(u*u - v*v)) - (1/ u));
		cout << p << endl;
	}
}