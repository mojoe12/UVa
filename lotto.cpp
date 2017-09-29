#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	bool iffirst = true;
	while (cin >> n) {
		
		if (!n) break;
		if (!iffirst) cout << endl;
		else iffirst = false;
		
		vector<int> nums (n);
		for (int i = 0; i < n; i++) cin >> nums[i];
		sort(nums.begin(), nums.end());
		
		for (int a = 0; a < n; a++) {
			for (int b = a+1; b < n; b++) {
				for (int c = b+1; c < n; c++) {
					for (int d = c+1; d < n; d++) {
						for (int e = d+1; e < n; e++) {
							for (int f = e+1; f < n; f++) {
								cout << nums[a] << ' ';
								cout << nums[b] << ' ';
								cout << nums[c] << ' ';
								cout << nums[d] << ' ';
								cout << nums[e] << ' ';
								cout << nums[f] << endl;
							}
						}
					}
				}
			}
		}
	}
}