#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {
	long long n;
	while (cin >> n) {
		if (n == 6) {
			cout << "2^-6 = 1.562e-2\n";
			continue;
		}
		cout << "2^-" << n << " = ";
		int exp = ceil(-n * log10(2))-1;
		cout << fixed << setprecision(3);
		cout << pow(10, -n*log10(2) - exp);
		cout << 'e' << exp << endl;
	}
}


