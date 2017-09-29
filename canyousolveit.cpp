#include <iostream>

using namespace std;

int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		long long num1 = (x1 + y1 + 1) * (x1 + y1) / 2 + x1;
		if (!x1 && !y1) num1 = 0;
		long long num2 = (x2 + y2 + 1) * (x2 + y2) / 2 + x2;
		if (!x2 && !y2) num2 = 0;
		
		cout << "Case " << c << ": " << num2 - num1 << endl;
	}
}