#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

double getav(vector<int>& nums, bool ifup) {

	int sumruns = 0, numruns = 0;
	
	bool ifcorrectdev = false;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] != nums[i-1]) {
			ifcorrectdev = (ifup != nums[i] < nums[i-1]);
			break;
		}
	}
	
	int runcurr = ifcorrectdev;
		
	for (int i = 2; i < nums.size(); i++) {
		//cout << runcurr << endl;
		if (ifup) {
			if (runcurr && nums[i] >= nums[i-1]) runcurr++;
			if (!runcurr && nums[i] > nums[i-1]) runcurr++;
			if (runcurr && nums[i] < nums[i-1]) {
				sumruns += runcurr;
				numruns++;
				runcurr = 0;
			}
		}
		else {
			if (runcurr && nums[i] <= nums[i-1]) runcurr++;
			if (!runcurr && nums[i] < nums[i-1]) runcurr++;
			if (runcurr && nums[i] > nums[i-1]) {
				sumruns += runcurr;
				numruns++;
				runcurr = 0;
			}
		}
	}
	
	sumruns += runcurr;
	if (runcurr) numruns++;
	
	if (!numruns) return 0.;
	return sumruns * 1. / numruns;
}


int main() {
	
	while (true) {
		vector<int> nums;
		while (true) {
			int x;
			cin >> x;
			if (!x) break;
			nums.push_back(x);
		}
		int n = nums.size();
		if (!n) break;
		
		cout << "Nr values = " << n << ":  ";
		cout.precision(6);
		cout << fixed << getav(nums, true) << ' ';
		cout << fixed << getav(nums, false) << endl;
		

	}

}


