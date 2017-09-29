#include <iostream>

using namespace std;

int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int y = 1; y <= k; y++) {
		long long x;
		cin >> x;
		long long a = 0, b = 0, c = 0, d = 0;
		for (long long i = 2; i < x; i++) {
			if (x % i == 0) {
				if (a) {
					c = i;
					d = x / i;
					break;
				}
				else {
					a = i;
					b = x / i;
				}
			}
		}
		cout << "Case #" << y << ": " << x << " = ";
		cout << a << " * " << b << " = ";
		cout << c << " * " << d << endl;
	}
}