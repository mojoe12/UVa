#include <iostream>
#include <vector>
using namespace std;

bool norepeat (long long n) {
	vector<int> digs (10);
	while (n) {
		if (digs[n % 10]) return false;
		digs[n % 10]++;
		n /= 10;
	}
	return true;
}


int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		
		long long n;
		cin >> n;
		
		for (long long i = 1; (n * i) <= 9876543210; i++) {
			if (norepeat(i) && norepeat(n*i)) {
				cout << n*i << " / " << i << " = " << n << endl;
			}
		}
	}
}