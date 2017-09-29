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


bool ifDecode (vector<string>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++) {
		if (equal(nums[i], nums[i+1])) return true;
	}
	return false;
}


int main(int argc, char *argv[]) {
	string s;
	for (int c = 1; ; c++) {
		if (!(cin >> s)) break;
		vector<string> nums;
		for (; s != "9"; cin >> s) {
			nums.push_back(s);
		}
		
		cout << "Set " << c << " is ";
		if ( ifDecode(nums) ) cout << "not ";
		cout << "immediately decodable\n";
	}
}