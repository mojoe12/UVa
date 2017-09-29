#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (string a, string b) {
	for (int i = 0; i < a.length(); i++) {
		if ()
		if (a[i] != b[i]) return a[i] > b[i];
	}
}

int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		if (!n) break;
		vector<string> nums (n);
		for (int i = 0; i < n; i++) cin >> nums[i];
		sort(nums.begin(), nums.end(), comp);
		for (int i = 0; i < n; i++) cout << nums[i];
		cout << endl;
	}
	return 0;
}