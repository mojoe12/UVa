#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	// needs to be constant
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n, x;
		cin >> n;
		vector<int> gas (n), sums(n);
		for (int i = 0; i < n; i++) cin >> gas[i];
		for (int i = 0; i < n; i++) {
			cin >> x;
			gas[i] -= x;
			// add it to the sums from 
		}
		int s = 0;
		for (; s < n; s++) {
			int have = 0;
			for (int g = 0; g < n; g++) {
				if (have < 0) break;
				have += gas[(g+s) % n];
			}
			if (have > 0) break;
		}
		cout << "Case " << c << ": ";
		if (s == n) cout << "Not possible\n";
		else cout << "Possible from station " << s+1 << endl;
	}
}