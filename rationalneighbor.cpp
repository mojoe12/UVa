#include <iostream>
#include <cmath>

using namespace std;

int main() {
		
	int a, b;
	double n;
	while (cin >> a >> b >> n) {
		int c = 0, d = 1;
		while (true) {
			c = 1 + floor(a * 1.0 * d / b);
			if (c * b - a * d <= n * b * d) break;
			d++;
		}
		cout << c << ' ' << d << endl;
	}

}