#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n;
		string x;
		cin >> x >> x >> n;
		vector< vector<long long> > nums (n, vector<long long> (n));
		bool ifsym = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> nums[i][j];
				if (nums[i][j] < 0) ifsym = false;
			}
		}
		int mid = n / 2;
		for (int i = 0; i < n && ifsym; i++) {
			for (int j = 0; j < n && ifsym; j++) {
				ifsym = (nums[i][j] == nums[n-i-1][n-j-1]);
			}
		}

		if (ifsym) cout << "Test #" << c << ": Symmetric.\n";
		else cout << "Test #" << c << ": Non-symmetric.\n";
	}
}