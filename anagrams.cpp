#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

bool ifequal (vector<int>& a, vector<int>& b) {
	for (int i = 0; i < 41; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	
	
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		
		
		vector<string> words;
		while (getline(cin, s)) {
			if (s == "") break;
			words.push_back(s);
		}
		
		sort(words.begin(), words.end());
		
		vector< vector<int> > counts (words.size(), vector<int> (41, 0));
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++) {
				int index = words[i][j] - '!';
				if (index >= 0 && index < 15) counts[i][index]++;
				else if (index > 63 && index < 90) counts[i][index-49]++;
			}
		}
		
		for (int i = 0; i < words.size(); i++) {
			for (int j = i+1; j < words.size(); j++) {
				if (ifequal(counts[i], counts[j])) {
					cout << words[i] << " = " << words[j] << endl;
				}
			}
		}
		
	}

}