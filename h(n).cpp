#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

long long H(int n) {
	if (n == 1) return 1;
	long long k = floor(sqrt(n));
	
	long long sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += n / i;
	}
	return 2 * sum - k * k;
}


int main() {
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		cout << H(n) << endl;
	}




}


