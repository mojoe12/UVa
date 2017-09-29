#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool checkisbn (vector<int>& nums) {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += (10 - i) * nums[i];
	}
	return sum % 11 == 0;
}


int main() {
	
	
	
	string input;
	while (getline(cin, input)) {
		
		string s;
		int start = -1, end = -1;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] != ' ') {
				start = i;
				break;
			}
		}
		
		for (int i = input.length()-1; i >= 0; i--) {
			if (input[i] != ' ') {
				end = i;
				break;
			}
		}
		
		if (end < 0 || start < 0) s = "";
		else s = input.substr(start, 1 + end - start);
		
		vector<int> nums;
		
		for (int i = 0; i < s.size(); i++) {
			if (nums.size() == 9 && s[i] == 'X') {
				nums.push_back(10);
			}
			if (s[i] >= '0' && s[i] <= '9') {
				nums.push_back(s[i] - '0');
			}
		}
		
		bool ok = nums.size() == 10 && checkisbn(nums);
		
		cout << s << " is ";
		if (!ok) cout << "in";
		cout << "correct.\n";
	}




}


