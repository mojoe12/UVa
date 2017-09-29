#include <iostream>
#include <cmath>
using namespace std;

unsigned long long tpow (int n);
bool ifpal(unsigned long long x);
unsigned long long reverse (unsigned long long x);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		unsigned long long num;
		cin >> num;
		int i = 0;
		do {
			num = num + reverse(num);
			i++;
		} while (!ifpal(num));
		cout << i << " " << num << endl;
	}
}

unsigned long long tpow (int n) {
	if (n == 0) return 1;
	return 10 * tpow(n-1);
}
bool ifpal(unsigned long long x) {
	bool ifpal = true;
	int numdig = 1 + floor(log10(x));
	for (int i = 0; i < numdig/2 && ifpal; i++) {
		int dig1 = (x % tpow(i+1)) / tpow(i);
		int dig2 = (x % tpow(numdig - i)) / tpow(numdig - i-1);
		if (dig1 != dig2) ifpal = false;
	}
	return ifpal;
}
unsigned long long reverse (unsigned long long x) {
	unsigned long long rev = 0;
	int numdig = 1 + floor(log10(x));
	for (int i = 0; i < numdig; i++) {
		int dig = ((x % tpow(i+1)) / tpow(i));
		rev += dig * tpow(numdig - i-1);
	}
	return rev;
}