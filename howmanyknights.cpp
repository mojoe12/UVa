#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations



int main() {
	
	// setup input
	int n, m;
	while (cin >> n >> m) {
		if (!n && !m) break;
		
		int ogn = n, ogm = m;
		if (n > m) swap(n, m);
		int ans = 0;
		if (n > 2) ans = ceil(n * m / 2.0);
		if (n == 2) {
			if (m % 4 == 0) ans = m;
			else if (m % 4 == 1) ans = m+1;
			else ans = m + (4 - m % 4);
		}
		
		if (n == 1) ans = m;
		if (n == 0) ans = 0;
		
		cout << ans << " knights may be placed on a ";
		cout << ogn << " row " << ogm << " column board.\n";
		
	}


	// loop through it, apply function


	// output answer


}

// function definitions

