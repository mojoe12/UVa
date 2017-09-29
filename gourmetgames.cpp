#include <iostream>

using namespace std;

int main() {
	
	int k;
	cin >> k;
	
	for (int c = 0; c < k; c++) {
		int n, m;
		cin >> n >> m;
		int counter = 0;
		while (n >= m) {
			counter += n / m;
			n = n / m + n % m;
		}
		if (n == 1) cout << counter << endl;
		else cout << "cannot do this\n";
	}
}