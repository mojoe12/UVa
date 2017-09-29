#include <iostream>

using namespace std;

int getcode (int n, int p) {
	if (n == 1) return p;
	int total = (1 << n);
	bool ifflip = 2 * p >= total;
	int digit = (ifflip) ? 1 : 0;
	digit *= total / 2;
	int newn = n-1;
	int newp = (ifflip) ? (total - 1 - p) : p;
	return digit + getcode(newn, newp);
}

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n, p;
		cin >> n >> p;
		int num = getcode(n, p);
		cout << num << endl;
	}
}