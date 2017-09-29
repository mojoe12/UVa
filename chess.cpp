#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations

int king(int n, int m) {
	if (n < 1 || m < 1) return 0;
	if (n == 1 || n == 2) return ceil(m / 2.0);
	if (m == 1 || m == 2) return ceil(n / 2.0);
	if (n == 3) return 2 * ceil(m / 2.0);
	if (m == 3) return 2 * ceil(n / 2.0);
	return 2 * ceil(n / 2.0) + 2 * ceil((m-4) / 2.0) + king(n-4,m-4);
}

int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		char p;
		int n, m;
		cin >> p >> n >> m;
		if (p == 'r') cout << min(n, m) << endl;
		if (p == 'k') cout << ceil(n * m / 2.0) << endl;
		if (p == 'Q') cout << min(n, m) << endl;
		if (p == 'K') cout << king(n, m) << endl;
	}


}

// function definitions

