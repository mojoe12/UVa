#include <iostream>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int modInverse(int n, int p) {
    n %= p;
    for(int x = 1; x < p; x++) {
        if((n*x) % p == 1) return x;
    }
	return 0;
}

int fac (int n, int k) {
	int prod = 1;
	for (int i = n; i > 0; i--) {
		prod = (prod * i) % k;
	}
	return prod;
}
int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int c = 0; c < T; c++) {
		int m, n, k;
		cin >> m >> n >> k;
		int num = fac(m+n, k);
		int den = (fac(m, k) * fac(n, k)) % k;
		cout << num << ' ' << den << endl;
		int gcf = gcd(num, den);
		num /= gcf;
		den /= gcf;
		cout << num << ' ' << den << endl;
		int ans = (num * modInverse(den, k) ) % k;
		cout << ans << endl;
	}
}