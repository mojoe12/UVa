#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp (pair<char, int> i , pair<char, int> j) {
	if (i.second == j.second) return i.first < j.first;
	return i.second > j.second;
}

int main(int argc, char *argv[]) {
	string s;
	vector<int> count (26);
	fill(count.begin(), count.end(), 0);
	int k;
	cin >> k;
	getline(cin, s);
	for (int c = 0; c < k; c++) {
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			int n = s[i] - 'A';
			if (n > 25) n -= 32;
			if (n >= 0 && n < 26) count[n]++;
		}
	}
	
	vector< pair<char, int> > counts;
	for (int i = 0; i < 26; i++) {
		char c = 'A' + i;
		pair<char, int> newpair (c, count[i]);
		counts.push_back(newpair);
	}
	sort(counts.begin(), counts.end(), comp);
	for (int i = 0; i < 26; i++) {
		if (counts[i].second == 0) break;
		cout << counts[i].first << ' ' << counts[i].second << endl;
	}
}