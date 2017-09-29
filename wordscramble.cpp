#include <iostream>

using namespace std;

string reverse (string s) {
	string news = "";
	for (int i = 0; i < s.length(); i++) {
		news += s[s.length() - i - 1];
	}
	return news;
}

int main(int argc, char *argv[]) {
	string s;
	for (getline(cin, s); s != ""; getline(cin, s)) {
		int i = 0;
		string wordc = "";
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (c == ' ') {
				cout << reverse(wordc) << ' ';
				wordc = "";
			}
			else wordc += c;
		}
		cout << reverse(wordc) << endl;
	}
}