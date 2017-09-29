#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {

		vector<string> files (n);
		int maxlen = 0;
		for (int i = 0; i < n; i++) {
			cin >> files[i];
			if (files[i].length() > maxlen) maxlen = files[i].length();
		}
		sort(files.begin(), files.end());
		
		for (int i = 0; i < 60; i++) cout << '-';
		cout << endl;
		
		// you have one col of length maxlen, on the end
		int numleftcols = (60 - maxlen) / (maxlen + 2);
		int rows = ceil(n / (numleftcols + 1.0));
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < numleftcols + 1; j++) {
				if (j && j * rows < n - i) cout << "  ";
				if (j == numleftcols) cout.width(maxlen);
				else cout.width(maxlen);
				if (j * rows < n - i) cout << left << files[i + j * rows];
			}
			cout << endl;
		}
	}
}