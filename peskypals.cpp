#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool ifpal(string s);

int main(int argc, char *argv[]) {
	string s;
	while (cin >> s) {
		int npals = 0;
		vector<string> prev (0);
		for (int l = 1; l <= s.length(); l++) {
			for (int i = 0; i <= s.length() - l; i++) {
				string sub = s.substr(i,l);
				if (find(prev.begin(), prev.end(), sub) == prev.end()) {
					prev.push_back(sub);
					if (ifpal(sub)) npals++;
				}
			}
		}
		cout << "The string '" << s << "' contains " << npals << " palindromes." << endl;
	}
}
bool ifpal(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i-1]) return false;
	}
	return true;
}