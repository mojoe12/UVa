#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

bool ifequal (vector<int>& a, vector<int>& b) {
	for (int i = 0; i < 26; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	
	// you have to put them together too :(
	
	string s;
	while (getline(cin, s)) {
		
		vector<string> words (1, s);
		while (getline(cin, s)) {
			if (s == "#") break;
			words.push_back(s);
		}
		
		vector< vector<int> > counts (words.size(), vector<int> (26, 0));
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++) {
				counts[i][words[i][j] - 'A']++;
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