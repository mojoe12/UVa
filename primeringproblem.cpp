#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations
bool isPrime(int x);
void getrings(vector<int>& nums, int n);

int main() {
	
	// setup input
	int n;
	for (int c = 1; cin >> n; c++) {
		if (c > 1) cout << endl;
		cout << "Case " << c << ":\n";
		vector<int> nums (1, 1);
		getrings(nums, n);
	}

}

// function definitions

bool isPrime(int x) {
	switch (x) {
		case 2:
		case 3:
		case 5:
		case 7:
		case 11:
		case 13:
		case 17:
		case 19:
		case 23:
		case 29:
		case 31:
			return true;
	}
	return false;
}

void getrings(vector<int>& nums, int n) {
	if (nums.size() == n && isPrime(1 + nums[n-1])) {
		for (int i = 0; i < n-1; i++) cout << nums[i] << ' ';
		cout << nums[n-1] << endl;
	}
	
	for (int i = 1; i <= n; i++) {
		bool ifused = false;
		for (int j = 0; !ifused && j < nums.size(); j++) {
			if (i == nums[j]) ifused = true;
		}
		if (ifused) continue;
		if (!isPrime(nums[nums.size()-1] + i)) continue;
		nums.push_back(i);
		getrings(nums, n);
		nums.pop_back();
	}
}