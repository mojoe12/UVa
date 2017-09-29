#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		vector<int> nums (n);
		for (int i = 0; i < n; i++) cin >> nums[i];
		sort(nums.begin(), nums.end());
		
		int minmed = 0, medspres = 0, medstotal = 0;
		minmed = nums[(n - 1) / 2];
		
		if (n % 2) {
			medspres = count(nums.begin(), nums.end(), minmed);
			medstotal = 1;
		}
		
		else {
			int maxmed = nums[n / 2];
			medspres = upper_bound(nums.begin(), nums.end(), maxmed) -
				lower_bound(nums.begin(), nums.end(), minmed);
			medstotal = 1 + maxmed - minmed;
		}
		
		cout << minmed << ' ' << medspres;
		cout << ' ' << medstotal << endl;
	}
}