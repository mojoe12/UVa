#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

bool ifsorted(vector<int>& v);
bool equal(vector<int>& a, vector<int>& b);
void makemap(vector<int> start, int& minmoves, vector<int>& previousi, int& nmaps);


int main() {
	
	int n;
	for (int c = 1; cin >> n; c++) {
		if (!n) break;
		vector<int> start (n);
		for (int i = 0; i < n; i++) cin >> start[i];
		vector<int> finish = start;
		sort(finish.begin(), finish.end());
		int x = (n*n-n)/2;
		vector<int> a;
		int nmaps = 0;
		makemap(start, x, a, nmaps);
		cout << "There are " << nmaps;
		cout << " swap maps for input data set " << c << ".\n";
	}
}

bool ifsorted(vector<int>& v) {
	for (int i = 1; i < v.size(); i++) {
		if (v[i-1] > v[i]) return false;
	}
	return true;
}

bool equal(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void makemap(vector<int> start, int& minmoves, vector<int>& previousi, int& nmaps) {
	int cmoves = previousi.size();
	if (cmoves > minmoves) return;
	
	if (ifsorted(start)) {
		if (cmoves) {
			if (cmoves < minmoves) {
				nmaps = 1;
				minmoves = cmoves;
			}
			else nmaps++;
		}
		return;
	}
	for (int i = 0; i < start.size()-1; i++) {
		if (!cmoves || i != previousi[cmoves-1] ){
			swap(start[i], start[i+1]);
			previousi.push_back(i);
			makemap(start, minmoves, previousi, nmaps);
			swap(start[i], start[i+1]);
			previousi.pop_back();
		}
	}
}