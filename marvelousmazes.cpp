#include <iostream>

using namespace std;

bool isNum(char c) {
	return !(c - '0' < 0 || c - '0' > 9);
}


int main(int argc, char *argv[]) {
	string s;
	while (getline(cin, s)) {
		if (s == "") {
			cout << endl;
			continue;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '!') {
				cout << endl;
				continue;
			}
			int numtimes = s[i++] - '0';
			while (isNum(s[i])) {
				numtimes += (s[i++] - '0');
			}
			char letter = s[i];
			for (int j = 0; j < numtimes; j++) {
				if (letter == 'b') cout << ' ';
				else cout << letter;
			}
		}
		cout << endl;
	}
}