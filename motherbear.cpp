#include <iostream>
using namespace std;
bool ifpal(string s);
string removepunc(string s);

int main(int argc, char *argv[]) {
	string s;
	while (true) {
		getline(cin,s);
		if (s == "DONE") break;
		if (ifpal(removepunc(s))) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
}


bool ifpal(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i-1]) return false;
	}
	return true;
}

string removepunc(string s) {
	string x = "";
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '.' || c == ',' || c == '!' || c == '?' || c == ' ') continue;
		if (c - 'a' >= 0) c -= 32;
		x += c;
	}
	return x;
}