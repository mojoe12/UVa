#include <iostream>

using namespace std;

bool ifletter (char c) {
	int i = c - 'A';
	return (i >= 0 && i < 26) || (i < 58 && i > 31);
}

string translate (string s) {
	char c = s[0];
	bool ifv =  (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	if (!ifv) {
		s.erase(s.begin());
		s += c;
	}
	s = s + "ay";
	return s;
}


int main(int argc, char *argv[]) {
	string s;
	while ( getline(cin, s) ) {
		string word = "";
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (ifletter(c)) word += c;
			else {
				if (word != "") cout << translate(word);
				cout << c;
				word = "";
			}
		}
		cout << endl;
	}
}