#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void toLower (string s, set<string>& dict) {
	string news = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
			news += s[i];
		}
		else if (s[i] - 'A' >= 0 && s[i] - 'A' < 26) {
			news += (s[i]+32);
		}
		else if (news.length()) {
			dict.insert(news);
			news = "";
		}
	}
	if (news.length()) dict.insert(news);
}

int main(int argc, char *argv[]) {
	
	string word;
	set<string> dict;
	while (cin >> word) {
		toLower(word, dict);
	}
	
	typedef set<string>::iterator it_type;
	for (it_type it = dict.begin(); it != dict.end(); it++) {
		cout << *it << endl;
	}
}