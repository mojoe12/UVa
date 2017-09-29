#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

long long power(long long b, long long e) {
	return round(pow(b, e));
}
long long logarithm(long long b, long long e) {
	return round(log(e)/log(b));
}

int main() {
	
	long long n, m;
	while (cin >> n >> m) {
		
		if (n > 1 && m > 1 && power(m, logarithm(m, n)) == n) {
			while (n > 1) {
				cout << n << ' ';
				n /= m;
			}
			cout << "1\n";
		}
		else {
			cout << "Boring!\n";
		}
	}




}


