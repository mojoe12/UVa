#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int c = 0; c < k; c++) {
		
		vector<string> input;
		input.reserve(25);
		while (true) {
			getline(cin, s);
			if (s == "") break;
			input.push_back(s);
		}
		
		int n = input.size();
		vector< vector<int> > arr (n, vector<int> (n, 0));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int& val = arr[i][j];
				val = input[i][j] == '1' ? 1 : -1000; 
				if (i) val += arr[i-1][j];
				if (j) val += arr[i][j-1];
				if (i && j) val -= arr[i-1][j-1];
			}
		}
		
		int bestsum = 0;
		for (int starti = 0; starti < n; starti++) {
			for (int startj = 0; startj < n; startj++) {
				for (int endi = starti; endi < n; endi++) {
					for (int endj = startj; endj < n; endj++) {
						int subsum = arr[endi][endj];
						if (starti) subsum -= arr[starti - 1][endj];
						if (startj) subsum -= arr[endi][startj - 1];
						if (starti && startj) subsum += arr[starti - 1][startj - 1];
						bestsum = max(subsum, bestsum);
					}
				}
			}
		}
		
		if (c) cout << endl;
		cout << bestsum << endl;
	}

// i accidentally edited maximum sum to make this
// whatever


}


