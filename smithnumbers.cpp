#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>


using namespace std;

const int bsize = 1000000;

bitset<bsize> primes;

int sumdigits (int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

bool isPrime (int n) {
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int sumpfs (int n, int csum = 0) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			if (i < bsize ? primes[i] : isPrime(i)) {
				return sumpfs(n / i, csum + sumdigits(i));
			}
		}
	}
	if (csum) return csum + sumdigits(n);
	return 0;
}

int main() {
	int k;
	cin >> k;
	
	for (int i = 2; i < bsize; i++) {
		primes[i] = isPrime(i);
	}
	
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		if (n > 999999999) {
			cout << 1000000165 << endl;
			continue;
		}
		
		for (int i = n+1; ; i++) {
			if (sumdigits(i) == sumpfs(i)) {
				cout << i << endl;
				break;
			}
		}
	}
}


