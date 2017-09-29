#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

string toUpper(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] -= 32;
	}
	return s;
}

char toLower(char c) {
	if (c - 'A' >= 0 && c - 'A' < 26) return c + 32;
	return c;
}

int main() {
	
	string word;
	set<string> ignore;
	for (cin >> word; word != "::"; cin >> word) {
		ignore.insert(word);
	}
	
	string s;
	getline(cin, s);
	vector<string> allinput;
	vector< pair<int, int> > positions;
	multimap<string, int> posofpositions;
	while (getline(cin, s)) {
		
		word = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				if (word.length() && !ignore.count(word) ) {
					posofpositions.insert( make_pair(word, positions.size()) );
					positions.push_back( make_pair(allinput.size(), i - word.length()) );
				}
				word = "";
			}
			else word += toLower(s[i]);
			s[i] = toLower(s[i]);
		}
		if (word.length() && !ignore.count(word) ) {
			posofpositions.insert( make_pair(word, positions.size()) );
			positions.push_back( make_pair(allinput.size(), s.length() - word.length()));
		}

		allinput.push_back(s);
	}
	
	multimap<string, int>::iterator it = posofpositions.begin();
	for (; it != posofpositions.end(); it++) {

		int index = positions[it->second].first;
		if (!allinput[index].length()) continue;
		for (int i = 0; i < allinput[index].length(); i++) {
			if (i == positions[it->second].second) {
				cout << toUpper(it->first);
				i += (it->first).length() - 1;
			}
			else cout << allinput[index][i];
		}
		cout << endl;
	}
}

// current problem: multiple whitespace in between titles
// i dont believe the first udebug input is a problem