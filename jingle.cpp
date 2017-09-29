#include <iostream>

using namespace std;

int getlen(char note) {
	switch (note) {
		case 'W': return 64;
		case 'H': return 32;
		case 'Q': return 16;
		case 'E': return 8;
		case 'S': return 4;
		case 'T': return 2;
		case 'X': return 1;
		default: return 0;
	}
}

int main(int argc, char *argv[]) {
	while (true) {
		string s;
		cin >> s;
		if (s == "*") break;
		int howmanycorrect = 0, mcount = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '/') {
				if (mcount == 64) howmanycorrect++;
				mcount = 0;
			}
			else mcount += getlen(s[i]);
		}
		cout << howmanycorrect << endl;
	}
}