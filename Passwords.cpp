#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>


using namespace std;

void backtrack(vector<string> words, string rule, string printout, int x);


int main() {
	
	int n;
	while (cin >> n) {
		vector<string> words (n);
		for (int i = 0; i < n; i++) cin >> words[i];
		int m;
		cin >> m;
		cout << "--\n";
		for (int x = 0; x < m; x++) {
			string rule;
			cin >> rule;
			string printout = "";
			backtrack(words, rule, printout, 0);
		}
	}


}

void backtrack(vector<string> words, string rule, string printout, int x) {
	if (x == rule.length()) {
		cout << printout << endl;
		return;
	}
	
	if (rule[x] == '#') {
		for (int i = 0; i < words.size(); i++) {
			int len = printout.length();
			printout = printout + words[i];
			backtrack(words, rule, printout, x+1);
			printout = printout.substr(0, len);
		}
	}
	
	else if (rule[x] == '0') {
		for (int i = 0; i < 10; i++) {
			int len = printout.length();
			printout += ('0' + i);
			backtrack(words, rule, printout, x+1);
			printout = printout.substr(0, len);
		}
	}
	
}