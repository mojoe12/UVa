#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	vector<int> nums;
	while (cin >> n) {
		nums.push_back(n);
		int i = nums.size()/2;
		if (nums.size() % 2) {
			nth_element(nums.begin(), nums.begin()+i, nums.end());
			cout << nums[i] << endl;
		}
		else {
			nth_element(nums.begin(), nums.begin()+i-1, nums.end());
			int a = nums[i-1];
			nth_element(nums.begin(), nums.begin()+i, nums.end());
			int b = nums[i];
			cout << (a+b)/2 << endl;
		}
	}
}