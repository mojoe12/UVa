#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		cout << "Case " << c << ':';
		for (int denom = sqrt(n-1); denom > 0; denom--) {
			int x = n - denom * denom;
			if (x % denom == 0) cout << ' ' << x;
		}
		cout << endl;
	}



}


