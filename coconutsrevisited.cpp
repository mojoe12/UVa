#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int main() {
	
	long long c;
	while (cin >> c) {
		if (c < 0) break;
		
		long long np = 0;
		for (long long n = 1 + sqrt(c); !np && n > 1; n--) {
			bool works = true;
			long long ctemp = c;
			for (int i = 0; works && i < n; i++) {
				if ((ctemp - 1) % n) works = false;
				ctemp -= (ctemp - 1) / n + 1;
			}
			if (works && ctemp % n == 0) np = n;
		}
		
		
		cout << c << " coconuts, ";
		if (np) cout << np << " people and 1 monkey\n";
		else cout << "no solution\n";
	}




}


