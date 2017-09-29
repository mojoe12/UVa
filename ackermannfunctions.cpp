#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	long long l, h;
	while (cin >> l >> h) {
		if (!l && !h) break;
		
		long long bestnum = 0, maxlength = 0;
		
		if (l > h) swap(l, h);
		
		for (long long start = l; start <= h; start++) {
			long long use = start, counter = 0;
			for (; use != 1; counter++) {
				use = (use % 2) ? 3*use+1 : use/2;
			}
			if (start == 1) counter = 3;
			if (counter > maxlength) {
				maxlength = counter;
				bestnum = start;
			}
		}
		
		cout << "Between " << l << " and " << h << ", ";
		cout << bestnum << " generates the longest sequence of ";
		cout << maxlength << " values.\n";
	}

}