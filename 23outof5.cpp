#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

bool backtrack (vector<int>&, bitset<5>&, int, int);

int main(int argc, char *argv[]) {
	while (true) {
		vector<int> nums (5);
		for (int i = 0; i < 5; i++) cin >> nums[i];
		if (!nums[0]) break;
		bitset<5> used;
		bool ifworks = false;
		for (int i = 0; !ifworks && i < 5; i++) {
			used[i] = true;
			if (backtrack(nums, used, nums[i], 1)) ifworks = true;
			used[i] = false;
		}
		if (ifworks) cout << "Possible\n";
		else cout << "Impossible\n";
	}
}


bool backtrack (vector<int>& nums, bitset<5>& used, int csum, int x) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		if (!used[i]) sum += nums[i];
	}
	if (csum - sum > 23) return false;
	
	for (int i = 0; i < 5; i++) {
		if (!used[i]) {
			if (x == 4) return (csum + nums[i] == 23 || csum - nums[i] == 23 || csum * nums[i] == 23);
			
			used[i] = true;
			if (backtrack(nums, used, csum + nums[i], x+1) ||
			backtrack(nums, used, csum * nums[i], x+1) ||
			backtrack(nums, used, csum - nums[i], x+1)) return true;
			used[i] = false;
		}
	}
	return false;
}
