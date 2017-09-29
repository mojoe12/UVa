#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	
	set<string> dictionary; 
	string s;
	while (cin >> s) {
		if (s == "XXXXXX") break;
		else dictionary.insert(s);
	}
	
	while (cin >> s) {
		if (s == "XXXXXX") break;
		sort(s.begin(), s.end());
		bool iffound = false;
		do {
			if (dictionary.count(s)) {
				cout << s << endl;
				iffound = true;
			}
		} while (next_permutation(s.begin(), s.end()));
		
		if (!iffound) cout << "NOT A VALID WORD\n";
		cout << "******\n";
		
	}
}