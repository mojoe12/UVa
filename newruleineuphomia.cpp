#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

bool ifprime (int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}


int main() {
	
	vector<int> primes (80000);
	for (int i = 2, counter = 0; counter < 80000; i++) {
		if (ifprime(i)) primes[counter++] = i;
	}
	
	int n;
	typedef vector<int>::iterator it_type;
	for (int c = 1; cin >> n; c++) {
		if (!n) break;
		int numways = 0;
		it_type prev = primes.end();
		for (int i = 0; primes[i] < (n + 1)/ 2; i++) {
			it_type ub = upper_bound(primes.begin()+i, prev, n - primes[i]);
			numways += (ub - primes.begin()) - i - 1;
			prev = ub;
		}
		cout << "Case " << c << ": " << numways << endl;
	}
	




}


