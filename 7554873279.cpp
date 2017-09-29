#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	bool ifspace = false;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<string> nums (n);
		for (int i = 0; i < n; i++) {
			string phone;
			cin >> phone;
			string retval = "";
			for (int i = 0; i < phone.length(); i++) {
				char c = phone[i];
				int digit = 0;
				if (c == '-') continue;
				else if (c - '0' >= 0 && c - '9' < 1) digit = c - '0';
				else if (c == 'A' || c == 'B' || c == 'C') digit = 2;
				else if (c == 'D' || c == 'E' || c == 'F') digit = 3;
				else if (c == 'G' || c == 'H' || c == 'I') digit = 4;
				else if (c == 'J' || c == 'K' || c == 'L') digit = 5;
				else if (c == 'M' || c == 'N' || c == 'O') digit = 6;
				else if (c == 'P' || c == 'R' || c == 'S') digit = 7;
				else if (c == 'T' || c == 'U' || c == 'V') digit = 8;
				else if (c == 'W' || c == 'X' || c == 'Y') digit = 9;
				retval += to_string(digit);
			}
			nums[i] = retval;
		}
		sort(nums.begin(), nums.end());
		vector<int> counter (n);
		fill(counter.begin(), counter.end(), 1);
		for (int i = 0; i < n-1; i++) {
			if (nums[i] == nums[i+1]) {
				counter[i+1] = counter[i] + 1;
				counter[i] = 0;
			}
		}
		bool ifhappened = false;
		if (ifspace) cout << endl;
		else ifspace = true;
		for (int i = 0; i < n; i++) {
			if (counter[i] < 2) continue;
			ifhappened = true;
			string snum = nums[i];
			cout << snum[0] << snum[1] << snum[2] << '-';
			cout << snum[3] << snum[4] << snum[5] << snum[6];
			cout << ' ' << counter[i] << endl;
		}
		if (!ifhappened) cout << "No duplicates.\n";
	}
}