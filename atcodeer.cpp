#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	int n;
	cin >> n;
	long long minx = 1, miny = 1;
	for (int i = 0; i < n; i++) {
		int t, a;
		cin >> t >> a;
		while (true) {
			long long mod = minx % t, div = minx / t;
			if (t > 0 && mod * a % t == 0 && div * a >= miny) {
				miny = div * a;
				break;
			};
			minx++;
		}
	}
	cout << minx + miny << endl;
	return 0;



}


