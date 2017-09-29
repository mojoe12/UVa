#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
	
	map<string, int> dict;
	string s;
	for (cin >> s; s != "#"; cin >> s) dict.insert(make_pair(s,-1));
	
	getline(cin, s);
	int x = 0;
	for (getline(cin, s); s != "#"; getline(cin, s)) {
		string letters = "";
		int l = 1 + s.length() / 2;
		for (int i = 0; i < s.length(); i += 2) letters += s[i];
		
		int num = 0;
		do {
			for (int len = 1; len <= l; len++) {
				string word = letters.substr(0, len);
				cout << word << endl;
				if (dict.count(word) && dict[word] != x) {
					num++;
					dict[word] = x;
				}
			}
		} while ( next_permutation(letters.begin(), letters.end() ) );
		
		cout << num << endl;
		x++;
	}
	
}