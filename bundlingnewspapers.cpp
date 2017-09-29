#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations
void printpapers(vector<string>& papers, int size, vector<string>& subset, int index);


int main() {
	
	// setup input
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		getline (cin, s);
		int n;
		int lower = 1, upper = 0;
		bool ifstar = false;
		if (s[0] == '*') ifstar = true;
		else if (s.length() < 3) {
			int x = s[0] - '0';
			if (s.length() > 1) x = 10 * x + (s[1] - '0');
			lower = upper = x;
		}
		else {
			int in = 2;
			lower = s[0] - '0';
			if (s[1] != ' ') {
				lower = 10 * lower + (s[1] - '0');
				in++;
			}
			upper = s[in] - '0';
			if (s.length() > in+1) upper = 10 * upper + (s[in+1] - '0');
		}	
		
		vector<string> papers;
		for (getline(cin, s); s != ""; getline(cin, s)) {
			papers.push_back(s);
		}
		if (ifstar) upper = papers.size();
		
		for (int size = lower; size <= upper; size++) {
			vector<string> subset;
			cout << "Size " << size << endl;
			printpapers(papers, size, subset, 0);
			cout << endl;
		}
	}
}

// function definitions

void printpapers(vector<string>& papers, int size, vector<string>& subset, int index) {
	if (subset.size() == size) {
		for (int i = 0; i < size-1; i++) cout << subset[i] << ", ";
		cout << subset[size-1] << endl;
		return;
	}
	if (index >= papers.size()) return;
	subset.push_back(papers[index]);
	printpapers(papers, size, subset, index+1);
	subset.pop_back();
	printpapers(papers, size, subset, index+1);
}

