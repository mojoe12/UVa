#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		int minpaper = INT32_MAX;
		for (int x = 1; x <= n; x++) {
			if (n % x) continue;
			for (int y = 1; y <= n; y++) {
				if (n % (x * y)) continue;
				int z = n / (x * y);
				int paper = 2 * (x * y + x * z + y * z);
				minpaper = min(minpaper, paper);
			}
		}
		cout << minpaper << endl;
	}
	
}