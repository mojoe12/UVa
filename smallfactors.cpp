#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

long long power (long long b, long long e) {
	return pow(b, e);
}

int main() {
	
	vector<long long> powers;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 21; j++) {
			long long num = power(2, i) * power(3, j);
			powers.push_back(num);
		}
	}
	sort(powers.begin(), powers.end());
	
	int n;
	while (cin >> n) {
		if (!n) break;
		long long x = *(lower_bound(powers.begin(), powers.end(), n));
		cout << x << endl;
	}


}


