#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool equal (string s1, string s2) {
	int minl = min(s1.length(), s2.length());
	for (int i = 0; i < minl; i++) {
		if (s1[i] != s2[i]) return false;
	}
	return true;
}

bool ifCons (vector<string>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++) {
		if (equal(nums[i], nums[i+1])) return false;
	}
	return true;
}


int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<string> nums;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			nums.push_back(s);
		}
		if (ifCons(nums)) cout << "YES\n";
		else cout << "NO\n";
	}
}