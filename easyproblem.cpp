#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// setup input
	vector< vector<int> > nums (1000000);
	int n, m;
	while (cin >> n >> m) {
		fill(nums.begin(), nums.end(), vector<int> ());
		
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			nums[x-1].push_back(i+1);
		}
		
		for (int i = 0; i < m; i++) {
			int k, v;
			cin >> k >> v;
			if (nums[v-1].size() < k) cout << "0\n";
			else cout << nums[v-1][k-1] << endl;
		}
	}
}
