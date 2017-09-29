#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	bool ifspace = false;
	for (int c = 1; true; c++) {
		int h, l;
		cin >> h >> l;
		if (h == 0 || l == 0) break;
		vector< vector<int> > nums(h, vector<int>(l));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < l; j++) {
				nums[i][j] = '0';
			}
		}
		vector<int> starsx (0);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < l; j++) {
				char c;
				cin >> c;
				if (c != '*') continue;
				starsx.push_back(i);
				starsy.push_back(j);
				if (i > 0) nums[i-1][j]++;
				if (i < h-1) nums[i+1][j]++;
				if (j > 0) nums[i][j-1]++;
				if (j < l-1) nums[i][j+1]++;
				if (i > 0 && j < l-1) nums[i-1][j+1]++;
				if (i < h-1 && j < l-1) nums[i+1][j+1]++;
				if (i < h-1 && j > 0) nums[i+1][j-1]++;
				if (i > 0 && j > 0) nums[i-1][j-1]++;
			}
		}
		if (ifspace) cout << endl;
		else ifspace = true;
		cout << "Field #" << c << ":" << endl; 
		int x = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < l; j++) {
				if (x < starsx.size() && starsx[x] == i && starsy[x] == j) {
					x++;
					cout << '*';
					continue;
				}
				cout << nums[i][j];
			}
			cout << endl;
		}
	}
}