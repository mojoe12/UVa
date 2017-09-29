#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

void findwords(vector<string>& table, vector<string>& dict, string word, pair<int, int> current, vector< pair<int, int> > past);
bool comp(string i, string j);

int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector<string> table (n);
		for (int i = 0; i < n; i++) cin >> table[i];
		if (c) cout << endl;
		
		vector<string> dict;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				findwords(table, dict, "", make_pair(i, j), vector< pair<int, int> >());
			}
		}
		sort(dict.begin(), dict.end(), comp);
		for (int i = 1; i < dict.size(); i++) {
			if (dict[i-1] == dict[i]) dict[i-1] = "";
		}
		
		for (int i = 0; i < dict.size(); i++) {
			if (dict[i].size()) cout << dict[i] << endl;
		}
	}

}

// function definitions

void findwords(vector<string>& table, vector<string>& dict, string word, pair<int, int> current, vector< pair<int, int> > past) {
	
	int i = current.first, j = current.second, n = table.size();
	//cout << i << j << endl;
	if (i >= n || i < 0 || j >= n || j < 0) return;
	for (int x = 0; x < past.size(); x++) {
		if (i == past[x].first && j == past[x].second) return;
	}
	past.push_back(current);

	char c = table[i][j];
	if (c > word[word.length()-1]) {
		word.push_back(c);
		if (word.length() >= 3) dict.push_back(word);
	}
	else return;

	findwords(table, dict, word, make_pair(i-1, j-1), past);
	findwords(table, dict, word, make_pair(i-1, j), past);
	findwords(table, dict, word, make_pair(i-1, j+1), past);
	
	findwords(table, dict, word, make_pair(i, j-1), past);
	findwords(table, dict, word, make_pair(i, j+1), past);
	
	findwords(table, dict, word, make_pair(i+1, j-1), past);
	findwords(table, dict, word, make_pair(i+1, j), past);
	findwords(table, dict, word, make_pair(i+1, j+1), past);
}

bool comp(string i, string j) {
	if (i.length() != j.length()) return i.length() < j.length();
	return i < j;
}
