#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	bool ifspace = false;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector< vector<char> > nums(n, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				nums[i][j] = '0';
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if (c != '*') continue;
				nums[i][j] = '&';
				if (i > 0) nums[i-1][j]++;
				if (i < n-1) nums[i+1][j]++;
				if (j > 0) nums[i][j-1]++;
				if (j < n-1) nums[i][j+1]++;
				if (i > 0 && j < n-1) nums[i-1][j+1]++;
				if (i < n-1 && j < n-1) nums[i+1][j+1]++;
				if (i < n-1 && j > 0) nums[i+1][j-1]++;
				if (i > 0 && j > 0) nums[i-1][j-1]++;
			}
		}
		bool ifminetouched = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if (nums[i][j] - '0' < 0 && c == 'x') ifminetouched = true;
				if (nums[i][j] - '0' < 0) nums[i][j]  = '*';
 				else if (c == '.') nums[i][j] = '.';
			}
		}
		if (ifspace) cout << endl;
		else ifspace = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!ifminetouched && nums[i][j] == '*') nums[i][j] = '.';
				cout << nums[i][j];
			}
			cout << endl;
		}
	}
}