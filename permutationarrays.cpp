#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	bool ifspace = false;
	for (int c = 0; c < k; c++) {
		string input;
		getline(cin, input);
		getline(cin, input);
		getline(cin, input);
		string num = "";
		vector<int> nums (0);
		for (int i = 0; i < input.length(); i++) {
			num = "";
			while (i < input.length() && input[i] != ' ') {
				num += input[i];
				i++;
			}
			if (num == "" || num == " ") continue;
			nums.push_back(stoi(num));
		}
		vector<string> notindices (nums.size());
		for (int i = 0; i < nums.size(); i++) {
			cin >> notindices[i];
		}
		if (ifspace) cout << endl;
		else ifspace = true;
		for (int i = 1; i <= nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (nums[j] == i) cout << notindices[j] << endl;
			}
		}
	}
}