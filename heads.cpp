#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << "2^-" << n << " = ";
		int exp = ceil(-n * log10(2))-1;
		cout << fixed << setprecision(3);
		cout << pow(10, -n*log10(2) - exp);
		cout << 'E' << exp << endl;	}
}


