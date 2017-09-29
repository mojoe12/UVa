#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	

	int n;
	while (cin >> n) {
		int numdigs = floor(log10(n)) + 1;
		long long ans = 0;
		for (int add = numdigs+1; !ans; add++) {
			double leftside = log2(n) + add * log2(10);
			double rightside = log2(n+1) + add * log2(10);
			//cout << leftside << ' ' << rightside << endl;
			if (floor(leftside) != floor(rightside)) {
				ans = ceil(leftside);
				break;
			}
		}
		cout << ans << endl;
	}


}


