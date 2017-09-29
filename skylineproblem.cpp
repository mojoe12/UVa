/*#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
	
	int l, h, r;
	vector<int> inputl;
	vector<int> inputr;
	vector<int> inputy;
	int maxr = 0;
	ifstream fin ("skylinedata.txt");
	while (fin >> l >> h >> r) {
		inputl.push_back(l);
		inputy.push_back(h);
		inputr.push_back(r);
		maxr = max(r, maxr);
	}
	
	int minl = inputl[0];
	int h_size = 1 + maxr - minl;
	
	vector< pair<int, int> > heights (h_size);
	for (int i = 0; i < h_size; i++) {
		heights[i] = make_pair(minl + i, 0);
	}
	
	for (int i = 0; i < inputl.size(); i++) {
		for (int j = inputl[i]; j < inputl[i]; j++) {
			int index = j - minl;
			heights[index].second = max(inputy[i], heights[index].second);
		}
	}
	
	int prev = -1;
	bool ifspace = false;
	for (int i = 0; i < heights.size(); i++) {
		if (heights[i].second != prev) {
			if (ifspace) cout << ' ';
			else ifspace = true;

			cout << heights[i].first << ' ' << heights[i].second;
			prev = heights[i].second;
		}
	}
	cout << endl;
}*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void print(bool& ifspace, int x, int y) {
	if (ifspace) cout << ' ';
	else ifspace = true;
	cout << x << ' ' << y;
}

int main(int argc, char *argv[]) {
	
	map<int, int> heights;
	int l, h, r;
	while (cin >> l >> h >> r) {
		for (int x = l; x < r; x++) {
			if (heights.count(x)) heights[x] = max(heights[x], h);
			else heights.insert( make_pair(x, h) );
		}
	}
	
	int prevx = -1, prevh = -1;
	bool ifspace = false;
	map<int, int>::iterator it = heights.begin();
	for (; it != heights.end(); it++) {
		if ( it->first > prevx+1 && it != heights.begin() ) {
			print(ifspace, prevx+1, 0);
			prevh = 0;
		}
		if (it->second != prevh) {
			print(ifspace, it->first, it->second);
			prevh = it->second;
		}
		prevx = it->first;
	}
	print(ifspace, prevx+1, 0);
	cout << endl;
}