#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void toLower (string s, set<string>& dict, bool keepHyphen = true) {
	cout << s << endl;
	string news = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
			news += s[i];
		}
		else if (s[i] - 'A' >= 0 && s[i] - 'A' < 26) {
			news += (s[i]+32);
		}
		else if (news.length() && s[i] != '-') {
			dict.insert(news);
			news = "";
		}
		else if (keepHyphen && s[i] == '-') {
			news += s[i];
		}
	}
	if (news.length()) dict.insert(news);
}

int main(int argc, char *argv[]) {
	
	string word = "";
	string s;
	set<string> dict;=
	while (getline(cin, s)) {
		bool keepHyphen = !(word.length());
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				toLower(word, dict, keepHyphen);
				word = "";
				keepHyphen = true;
			}
			else word += s[i];
		}
		if (s[s.length()-1] != '-') {
			toLower(word, dict, keepHyphen);
			word = "";
			keepHyphen = true;
		}
	}
	
	typedef set<string>::iterator it_type;
	for (it_type it = dict.begin(); it != dict.end(); it++) {
		cout << *it << endl;
	}
}