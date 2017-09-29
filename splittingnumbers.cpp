#include <iostream>
#include <cmath>
using namespace std;

int pow2 (int n) {
	int x = 1;
	for (int i = 0; i < n; i++) x *= 2;
	return x;
}
int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int log2 = 1 + (int) (log(n)/log(2));
		int a = 0, b = 0;
		bool last = 1; // goes to a
		for (int i = 0; i <= log2; i++) {
			int pow = pow2(i);
			int add = pow * ((n >> i) % 2);
			if (add) last = !last;
			if (last) b += add;
			else a += add;
		}
		cout << a << ' ' << b << endl;
	}
}
