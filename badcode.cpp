#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// function declarations

void getcodes (vector< pair<char, string> >& code, string final, vector<string>& codes, string current, string currentchars);
bool comp(pair<char, string> i, pair<char, string> j) {
	return i.first < j.first;
}

int main() {
	
	// setup input
	int n;
	for (int c = 1; cin >> n; c++) {
		if (!n) break;
		vector< pair<char, string> > code (n);
		for (int i = 0; i < n; i++) {
			cin >> code[i].first >> code[i].second;
		}
		
		sort(code.begin(), code.end(), comp);
		
		string final;
		cin >> final;
		
		vector<string> codes;
		getcodes(code, final, codes, "", "");
		
		cout << "Case #" << c << endl;
		for (int i = 0; i < codes.size(); i++) {
			cout << codes[i] << endl;
		}
		cout << endl;
	}

}

void getcodes (vector< pair<char, string> >& code, string final, vector<string>& codes, string current, string currentchars) {
	if (codes.size() == 100) return;
	if (current == final) {
		codes.push_back(currentchars);
		return;
	}
	
	int fl = final.length(), cl = current.length();
		
	if (final[cl] == '0' && fl > cl+1) {
		current += '0';
		getcodes(code, final, codes, current, currentchars);
		return;
	}
	
	for (int i = 0; i < code.size(); i++) {
		bool ifok = true;
		for (int j = 0; j < code[i].second.length(); j++) {
			if (code[i].second[j] != final[cl + j]) ifok = false;
		}
		if (ifok) {
			current = current + code[i].second;
			currentchars += code[i].first;
			getcodes(code, final, codes, current, currentchars);
			current.pop_back();
			if (code[i].second.length() == 2) current.pop_back();
			currentchars.pop_back();
		}
	}
}