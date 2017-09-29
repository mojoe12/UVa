#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	for (int c = 1; cin >> n; c++) {
		
		if (n == 0) break;
		vector<int> nums (n);
		for (int i = 0; i < n; i++) cin >> nums[i];
		
		int m;
		cin >> m;
		cout << "Case " << c << ":\n";
		
		for (int i = 0; i < m; i++) {
			int q;
			cin >> q;
			int bestsum = 0, bestdif = INT_MAX;
			
			for (int j = 0; bestdif && j < n; j++) {
				for (int k = j+1; bestdif && k < n; k++) {
					int sum = nums[j] + nums[k];
					if (abs(sum-q) < bestdif) {
						bestsum = sum;
						bestdif = abs(sum-q);
					}
				}
			}
			cout << "Closest sum to " << q;
			cout << " is " << bestsum << ".\n";
		}
	}
}