#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		long long n;
		cin >> n;
		int x = 0;
		for (; pow(2, x) <= n; x++) {
		}
		cout << "Case " << c << ": ";
		cout << x << endl;
	}
}