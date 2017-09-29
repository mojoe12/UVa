#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int modpow(int base, int exp, int modulus) {
	base %= modulus;
	int result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
    	base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

int main() {
	
	int b, l, m;
	while (cin >> b >> l >> m) {
		if (l == 0 || m == 1) {
			cout << 1 << endl;
			continue;
		}
		for (int ndigs = 1; ; ndigs++) {
			int mp = modpow(b, ndigs, m * b - 1);
			if ((mp * l - m * l) % (m * b - 1) == 0) {
				cout << ndigs+1 << endl;
				break;
			}
		}
	}
}