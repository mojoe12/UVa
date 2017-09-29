#include <iostream>

using namespace std;

int main() {
	
	int a, b, c, d, l;
	while (cin >> a >> b >> c >> d >> l) {
		if (!d) break;
		int sum = 0;
		for (int x = 0; x <= l; x++) {
			int t0 = (x % d) * (x % d) * (a % d);
			int t1 = (x % d) * (b % d);
			int t2 = c % d;
			if ((t0 + t1 + t2) % d == 0) sum++;
		}
		cout << sum << endl;
	}
}